#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

struct query {
	int v, i;
};

vector<int> parent(maxn, -1);
vector<int> sizes(maxn, 1);
vector<vector<int>> adj(maxn);
vector<int> ancestor(maxn);
vector<vector<query>> lca_queries(maxn);
vector<int> lca(maxn);

int find_parent(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = find_parent(parent[v]);
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
	ancestor[curr] = curr;
	for (auto child : adj[curr]) {
		if (parent[child] == -1) {
			dfs_lca(child);
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

int main() {
	// for query of lca(a,b):
	//		queries[a].push_back({b,i}); queries[b].push_back({a,i});
	// i is the index of the query and the answer will be found in lca[i]
}