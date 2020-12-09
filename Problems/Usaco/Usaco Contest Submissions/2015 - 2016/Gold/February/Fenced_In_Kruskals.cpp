#include<bits/stdc++.h>
using namespace std;

int added_edges = 0;
long long cost = 0;

int parent[2001 * 2001], sizes[2001 * 2001];

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
	freopen("fencedin.in", "r", stdin); freopen("fencedin.out", "w", stdout);
	int a, b, n, m; cin >> a >> b >> n >> m;
	vector<edge> edges;
	vector<int> xs(n + 2), ys(m + 2);
	xs[n] = a; ys[m] = b;
	for (int i = 0; i < n; i++) {
		cin >> xs[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> ys[i];
	}
	if (n < m) {
		swap(xs, ys);
		swap(n, m);
		swap(a, b);
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());

	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j < m; j++) {
			edges.push_back({ i - 1 + j * (n + 1),  i - 1 + (j + 1) * (n + 1), xs[i] - xs[i - 1] });
		}
	}
	for (int i = 1; i <= m + 1; i++) {
		for (int j = 0; j < n; j++) {
			edges.push_back({ (m + 1 - i) * (n + 1) + j, (m + 1 - i) * (n + 1) + j + 1, ys[i] - ys[i - 1] });
		}
	}

	sort(edges.begin(), edges.end(), edge_cmp());

	for (int i = 0; i < (n + 1) * (m + 1); i++) {
		make_set(i);
	}
	for (int i = 0; i < edges.size(); i++) {
		if (union_sets(edges[i].u, edges[i].v, edges[i].w) == (n+1)*(m+1) - 1) {
			break;
		}
	}

	cout << cost;
}