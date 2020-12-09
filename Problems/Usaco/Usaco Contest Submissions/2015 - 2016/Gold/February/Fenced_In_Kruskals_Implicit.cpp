#include<bits/stdc++.h>
using namespace std;

int a, b, n, m;
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

int find_idx(int i, int j) {
	return i * (n + 1) + j;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fencedin.in", "r", stdin); freopen("fencedin.out", "w", stdout);
	cin >> a >> b >> n >> m;
	vector<int> xs(n + 2), ys(m + 2);
	vector<pair<int,int>> x_len(n + 1), y_len(m + 1);
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
		x_len[i - 1] = { xs[i] - xs[i - 1], i-1 };
	}
	for (int i = 1; i <= m + 1; i++) {
		y_len[i - 1] = { ys[i] - ys[i - 1], i-1 };
	}
	sort(x_len.begin(), x_len.end());
	sort(y_len.begin(), y_len.end());

	for (int i = 0; i < (n + 1) * (m + 1); i++) {
		make_set(i);
	}
	int x_idx = 0, y_idx = 0;
	while (x_idx < n + 1 or y_idx < m + 1) {
		if (y_idx < m + 1 and (x_idx == n + 1 or y_len[y_idx].first <= x_len[x_idx].first)) {
			for (int i = 0; i < n; i++) {
				if (union_sets(find_idx(y_len[y_idx].second, i), find_idx(y_len[y_idx].second, i + 1), y_len[y_idx].first) == (n + 1) * (m + 1) - 1) {
					goto a;
				}
			}
			y_idx++;
		}
		else if (x_idx < n + 1) {
			for (int i = 0; i < m; i++) {
				if (union_sets(find_idx(i, x_len[x_idx].second), find_idx(i + 1, x_len[x_idx].second), x_len[x_idx].first) == (n + 1) * (m + 1) - 1) {
					goto a;
				}
			}
			x_idx++;
		}
	}
a:

	cout << cost;
}