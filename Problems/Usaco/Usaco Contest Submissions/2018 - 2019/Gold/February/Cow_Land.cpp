#include<bits/stdc++.h>
using namespace std;

const int maxn = 100001;

struct query {
	int t, a, b;
};

struct query1 {
	int v, i;
};

int tin = 0;
vector<vector<int>> adj(maxn);
vector<query> queries(maxn);
vector<vector<query1>> lca_queries(maxn);
vector<int> lca(maxn);
vector<int> ancestor(maxn);
vector<int> convert(maxn);
vector<int> convert2(maxn);
vector<int> parent(maxn,-1);
vector<int> sub_sizes(maxn, 1);
vector<int> dsu_sizes(maxn, 1);
vector<int> heavy(maxn);
vector<int> enjoyment(maxn);
vector<bool> heavy_parent(maxn, 0);
vector<int> tree_parent(maxn);
vector<int> top_heavy(maxn);

//dsu
int find_parent(int v){
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = find_parent(parent[v]);
}

void union_sets(int a, int b){
	a = find_parent(a);
	b = find_parent(b);
	if (a != b) {
		if (dsu_sizes[a] < dsu_sizes[b]) {
			swap(a, b);
		}
		parent[b] = a;
		dsu_sizes[a] += dsu_sizes[b];
	}
}

//bit
struct bit {

	int n;
	vector<int> a;
	vector<int> a2;

	bit() {}
	bit(int n2, int val) {
		n = n2 + 1;
		a.resize(n);
		a2 = vector<int>(n2);
		if (val) {
			for (int i = 0; i < n; i++) {
				add(i, val);
			}
		}
	}
	bit(vector<int>& b) {
		n = b.size() + 1;
		a.resize(n);
		a2 = b;
		for (int i = 0; i < n; i++) {
			add(i, b[i]);
		}
	}

	void add(int idx, int val) {
		for (idx++; idx < n; idx += idx & -idx) {
			a[idx] ^= val;
		}
	}

	void update(int idx, int val) {
		int val2 = val;
		val ^= a2[idx];
		a2[idx] = val2;
		add(idx, val);
	}

	long long sum(int idx) {
		long long tot = 0;
		for (idx++; idx > 0; idx -= idx & -idx) {
			tot ^= a[idx];
		}
		return tot;
	}

	long long sum(int l, int r) {
		return sum(r) ^ sum(l - 1);
	}
};

bit bit1(maxn, 0);

//Heavylight Decomposition
void dfs_size(int curr, int parent = -1) {
	int best = 0;
	int sz = 0;
	for (auto child : adj[curr]) {
		if (child != parent) {
			dfs_size(child, curr);
			tree_parent[child] = curr;
			sub_sizes[curr] += sub_sizes[child];
			if (sub_sizes[child] > sz) {
				sz = sub_sizes[child];
				best = child;
			}
		}
	}
	heavy[curr] = best;
	heavy_parent[best] = 1;
	
}

int last = 0;
void dfs_heavy_light(int curr, int parent = -1) {
	if (!heavy_parent[curr]) {
		last = tin;
	}
	convert[curr] = tin;
	convert2[tin] = curr;
	tin++;
	top_heavy[curr] = last;
	if (heavy[curr]) {
		dfs_heavy_light(heavy[curr], curr);
	}
	for (auto child : adj[curr]) {
		if (child != parent and child != heavy[curr]) {
			dfs_heavy_light(child, curr);
		}
	}
}

//use tarjan's offline algorithm for lca
void dfs_lca(int curr, int par = -1) {
	parent[curr] = curr;
	ancestor[curr] = curr;
	for (auto child : adj[curr]) {
		if (child != par) {
			dfs_lca(child,curr);
			union_sets(child, curr);
			ancestor[find_parent(curr)] = curr;
		}
	}

	for (auto q : lca_queries[curr]) {
		if (parent[q.v] != -1) {
			lca[q.i] = ancestor[find_parent(q.v)];
		}
	}
}

int solve(int a, int curr_lca) {
	int ans = 0;
	while (a != curr_lca) {
		if (heavy_parent[a]) {
			ans ^= bit1.sum(max(convert[curr_lca] + 1, top_heavy[a]), convert[a]);
			a = tree_parent[convert2[max(convert[curr_lca] + 1, top_heavy[a])]];
		}
		else {
			ans ^= enjoyment[a];
			a = tree_parent[a];
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowland.in", "r", stdin); freopen("cowland.out", "w", stdout);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> enjoyment[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < q; i++) {
		cin >> queries[i].t >> queries[i].a >> queries[i].b;
		if (queries[i].t == 2) {
			lca_queries[queries[i].a].push_back({ queries[i].b,i });
			lca_queries[queries[i].b].push_back({ queries[i].a,i });
		}
	}

	dfs_size(1);
	dfs_heavy_light(1);
	dfs_lca(1);

	for (int i = 1; i <= n; i++) {
		bit1.update(convert[i], enjoyment[i]);
	}

	for (int i = 0; i < q; i++) {
		if (queries[i].t == 2) {
			int curr_lca = lca[i];
			cout << (enjoyment[curr_lca] ^ solve(queries[i].a, curr_lca) ^ solve(queries[i].b, curr_lca)) << '\n';
		}
		else {
			bit1.update(convert[queries[i].a], queries[i].b);
			enjoyment[queries[i].a] = queries[i].b;
		}
	}
}