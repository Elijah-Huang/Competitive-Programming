#include<bits/stdc++.h>
using namespace std;

long long total_paths = 0;

const int maxn = 2e5 + 5;
int parent[maxn];
long long sizes[maxn];
void make_set(int& v) {
	parent[v] = v;
	sizes[v] = 1;
}

int find_set(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (sizes[a] < sizes[b]) {
			swap(a, b);
		}
		parent[b] = a;
		total_paths -= sizes[b] * (sizes[b] - 1) / 2;
		total_paths -= sizes[a] * (sizes[a] - 1) / 2;
		sizes[a] += sizes[b];
		total_paths += sizes[a] * (sizes[a] - 1) / 2;
	}
}

struct edge {
	int u, v, w;
};

struct query {
	int q, i;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<edge> edges;
	vector<query> queries(m);
	vector<long long> ans(m);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({ u,v,w });
	}

	sort(edges.begin(), edges.end(),
		[&](const edge& a, const edge& b) {return a.w < b.w; });
	for (int i = 0; i < m; i++) {
		int q; cin >> q;
		queries[i] = { q,i };
	}
	sort(queries.begin(), queries.end(),
		[&](const query& a, const query& b) {return a.q < b.q; });

	for (int i = 1; i <= n; i++) {
		make_set(i);
	}
	int edge_idx = 0;
	for (int i = 0; i < m; i++) {
		while (edge_idx < n - 1 and edges[edge_idx].w <= queries[i].q) {
			union_sets(edges[edge_idx].u, edges[edge_idx].v);
			edge_idx++;
		}
		ans[queries[i].i] = total_paths;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << ' ';
	}
}