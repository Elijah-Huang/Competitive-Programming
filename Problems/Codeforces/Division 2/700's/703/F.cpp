// O(q*log(q)) with pretty big constant factor
#include<bits/stdc++.h>
using namespace std;

struct query {
	vector<int> nodes;
};
// for a given path
// active will find intersections not at it's lca 
// cnts with find intersections at it's lca

const int maxn = 3e5 + 1;
int n, m;
vector<int> adj[maxn];
// for changing # active
vector<pair<int,int>> updates[maxn];
// intersections of 2 paths with common lca = this node + for active
vector<query> queries[maxn];
// counts of paths with lca at current point
int tot_cnt = 0;
map<long long, int> cnts;
// intersections of 2 paths one at it's lca and the other not at it's lca
int active[maxn];
long long ans = 0;

// for lca
int t = 0;
int ancestor[maxn][20], tin[maxn], tout[maxn];

void dfs_lca(int c, int p) {
	tin[c] = t++;

	ancestor[c][0] = p;
	for (int i = 1; i < 20; i++) {
		ancestor[c][i] = ancestor[ancestor[c][i - 1]][i - 1];
	}

	// messes with bin search
	if (!(c==1 and p == 1)) {
		adj[c].erase(find(adj[c].begin(), adj[c].end(), p));
	}
	for (auto n : adj[c]) {
		dfs_lca(n, c);
	}

	tout[c] = t++;
}

// p is ancestor of a
bool is_ancestor(int a, int p) {
	// lol <= is very important or else you say the lca of a and a is parent of a
	return tin[p] <= tin[a] and tout[a] <= tout[p];
}

int find_lca(int a, int b) {
	if (is_ancestor(b, a)) {
		return a;
	}
	else if (is_ancestor(a, b)) {
		return b;
	}
	else {
		for (int i = 19; i >= 0; i--) {
			if (!is_ancestor(b, ancestor[a][i])) {
				a = ancestor[a][i];
			}
		}

		return ancestor[a][0];
	}
}

// find which subtree rooted at a child of c this node is in
int find_sub(int node, int c) {
	int l = 0, r = adj[c].size() - 1;
	while (l != r) {
		int m = (l + r + 1) / 2;

		if (tin[adj[c][m]] <= tin[node]) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}

	return adj[c][l];
}

// for computing the intersections of line path with any other path
void dfs(int c, int p) {
	for (auto n : adj[c]) {
		if (n != p) {
			dfs(n, c); 
			active[c] += active[n];
		}
	}

	for (auto upd : updates[c]) {
		if (upd.first == -1) {
			active[c]++;
			updates[upd.second].push_back({ c, upd.second });
		}
		else {
			active[c]--;
			active[find_sub(upd.first, c)]--;
		}
	}

	// loop through queries and update cnts as you iterate so that every intersection is counted only one time
	for (auto& q : queries[c]) {
		// find which subtrees rooted at children of c each node in the query is in
		// use this for PIE and complementary counting later
		vector<long long> subtrees;
		for (auto& node : q.nodes) {
			if (node != c) {
				subtrees.push_back(find_sub(node,c));
			}
		}

		// update ans with compl counting
		ans += tot_cnt + active[c];
		if (subtrees.size() == 1) {
			ans += - cnts[subtrees[0]];
			ans += - active[subtrees[0]];
		}
		else if (subtrees.size() == 2) {
			// make unique
			if (subtrees[0] > subtrees[1]) {
				swap(subtrees[0], subtrees[1]);
			}
			ans += - cnts[subtrees[0]] - cnts[subtrees[1]] + cnts[subtrees[0] * maxn + subtrees[1]];
			ans += - active[subtrees[0]] - active[subtrees[1]];
		}

		// update cnts
		for (auto subtree : subtrees) {
			cnts[subtree]++;
		}
		if (subtrees.size() == 2) {
			cnts[subtrees[0] * maxn + subtrees[1]]++;
		}
		tot_cnt++;
	}

	tot_cnt = 0;
	cnts.clear();
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs_lca(1, 1);

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b, lca; cin >> a >> b;
		lca = find_lca(a, b);

		queries[lca].push_back({ {a,b} });
		if (a != lca) {
			updates[a].push_back({ -1, lca });
		}
		if (b != lca) {
			updates[b].push_back({ -1, lca });
		}
	}

	dfs(1, 1);

	cout << ans;
}