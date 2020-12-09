#include<bits/stdc++.h>
using namespace std;

int added_edges = 0;
long long cost = 0;

const int maxn = 1e5;
int parent[maxn], sizes[maxn];

void make_set(int& v) {
	parent[v] = v;
	sizes[v] = 1;
}

int find_parent(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = find_parent(parent[v]);
}

int union_sets(int u, int v, int& w) {
	u = find_parent(u);
	v = find_parent(v);
	if (u != v) {
		if (sizes[u] < sizes[v]) {
			swap(u, v);
		}
		parent[v] = u;
		sizes[u] += sizes[v];
		added_edges++;
		cost += w;
		return added_edges;
	}
	return 0;
}

struct edge {
	int u, v, w;
};

struct edge_cmp {
	bool operator()(const edge& a, const edge& b) const {
		return a.w < b.w;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, num_nodes;
	cin >> n;
	vector<edge> edges;
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({ u,v,w });
	}

	sort(edges.begin(), edges.end(), edge_cmp());

	for (int i = 0; i < n; i++) {
		make_set(i);
	}
	for (int i = 0; i < edges.size(); i++) {
		if (union_sets(edges[i].u, edges[i].v, edges[i].w) == num_nodes - 1) {
			break;
		}
	}
}