#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct query {
	int b, idx;
};

const int maxn = 1e5 + 1;
int parent[maxn], sizes[maxn];
vector<int> ancestor(maxn);
vector<vector<int>> adj(maxn);
vector<int> types(maxn);
vector<vector<query>> queries(maxn);
vector<int> lca(maxn);
vector<bool> good_milk(maxn);
vector<unordered_set<int>> active(maxn);
vector<vector<query>> to_add(maxn);
vector<vector<query>> to_remove(maxn);

int find_parent(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find_parent(parent[a]);
}

void union_sets(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a != b) {
		if (sizes[a] < sizes[b]) {
			swap(a, b);
		}
		parent[b] = a;
		sizes[a] += sizes[b];
	}
}

void dfs_lca(int curr) {
	parent[curr] = curr;
	sizes[curr] = 1;
	ancestor[curr] = curr;
	for (auto neighbor : adj[curr]) {
		if (!parent[neighbor]) {
			dfs_lca(neighbor);
		}
		union_sets(curr, neighbor);
		ancestor[find_parent(curr)] = curr;
	}
	for (auto other : queries[curr]) {
		if (parent[other.b]) {
			lca[other.idx] = ancestor[find_parent(other.b)];
		}
	}
}

void dfs(int curr, int p) {
	for (auto neighbor : adj[curr]) {
		if (neighbor != p) {
			dfs(neighbor, p);
		}
	}
	for (auto q : to_add[curr]) {
		active[q.b].insert(q.idx);
		to_remove[lca[q.idx]].push_back()
	}
}

/*
struct query {
	int b, idx;
	bool operator==(const query& other)const {
		return b == other.b and idx == other.idx;
	}
};
/*
struct query_cmp {
	int operator()(const query& a) const {
		return a.b ^ a.idx;
	}
};
*/
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("milkvisits.in", "r", stdin); freopen("milkvisits.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> types[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		queries[a].push_back({ b,i });
		queries[b].push_back({ a,i });
		to_add[a].push_back({ c,i });
		to_add[b].push_back({ c,i });
	}

	//find lca
	dfs_lca(1);
	//answer queries 
	dfs(1,0);

	cout << accumulate(good_milk.begin(), good_milk.end(),0);
}