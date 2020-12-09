#include<bits/stdc++.h>
using namespace std;

int parent[2001 * 2001], sizes[2001 * 2001];
int added_edges = 0;

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

int union_sets(int u,int v) {
	u = parent[u];
	v = parent[v];
	if (u != v) {
		if (sizes[u] < sizes[v]) {
			swap(u, v);
		}
		parent[v] = u;
		sizes[u] += sizes[v];
		added_edges++;
		return added_edges;
	}
}

struct edge {
	int v, w;
};

struct edge_cmp {
	bool operator()(const edge& a, const edge& b) const {
		return a.w > b.w;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fencedin.in", "r", stdin); freopen("fencedin.out", "w", stdout);
	int a, b, n, m; cin >> a >> b >> n >> m;
	long long cost = 0;
	vector<vector<edge>> adj((n + 1) * (m + 1));
	vector<int> xs(n + 2), ys(m + 2);
	xs[n] = a; ys[m] = b;
	for (int i = 0; i < n; i++) {
		cin >> xs[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> ys[i];
	}
	if (n > m) {
		swap(xs, ys);
		swap(n, m);
		swap(a, b);
	}
	sort(xs.begin(), xs.end()); 
	sort(ys.begin(), ys.end());

	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j < m; j++) {
			adj[i - 1 + j * (n + 1)].push_back({ i - 1 + (j + 1) * (n + 1), xs[i] - xs[i - 1] });
			adj[i - 1 + (j + 1) * (n + 1)].push_back({ i - 1 + j * (n + 1), xs[i] - xs[i - 1] });
		}
	}
	for (int i = 1; i <= m + 1; i++) {
		for (int j = 0; j < n; j++) {
			adj[(m + 1 - i) * (n + 1) + j].push_back({ (m + 1 - i) * (n + 1) + j + 1, ys[i] - ys[i - 1] });
			adj[(m + 1 - i) * (n + 1) + j + 1].push_back({ (m + 1 - i) * (n + 1) + j, ys[i] - ys[i - 1] });
		}
	}
	int mst_size = 0;
	vector<bool> in_mst((n + 1) * (m + 1));
	priority_queue<edge, vector<edge>, edge_cmp> pq;
	pq.push({ 0,0 });
	while (mst_size != (n + 1) * (m + 1)) {
		auto curr = pq.top(); pq.pop();
		if (!in_mst[curr.v]) {
			in_mst[curr.v] = 1;
			mst_size++;
			cost += curr.w;
			for (auto neighbor : adj[curr.v]) {
				if (!in_mst[neighbor.v]) {
					pq.push(neighbor);
				}
			}
		}
	}

	cout << cost;
}