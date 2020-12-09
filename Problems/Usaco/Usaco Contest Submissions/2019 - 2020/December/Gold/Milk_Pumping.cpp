#include<bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, c, f;
};

struct edge2 {
	int v, c;
};

bool operator<(const edge2& a, const edge2& b) {
	return a.c > b.c;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("pump.in", "r", stdin); freopen("pump.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<vector<edge2>> adj(n + 1);
	vector<edge> edges(m);
	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].c >> edges[i].f;
	}
	sort(edges.begin(), edges.end(), [&](const edge& a, const edge& b) {return a.f > b.f; });
	
	int i = 0;
	double ans = 0;
	while (i < m) {
		auto curr = edges[i];
		while (i < m and edges[i].f == curr.f) {
			adj[edges[i].v].push_back({ edges[i].u ,edges[i].c });
			adj[edges[i].u].push_back({ edges[i].v ,edges[i].c });
			i++;
		}
		priority_queue<edge2, vector<edge2>>pq;
		vector<int> dists(n + 1,1e9);
		pq.push({ 1,0 });
		while (!pq.empty()) {
			auto curr = pq.top(); pq.pop();
			if (dists[curr.v] > curr.c) {
				dists[curr.v] = curr.c;
				for (auto& neighbor : adj[curr.v]) {
					pq.push({ neighbor.v,neighbor.c + curr.c });
				}
			}
		}

		ans = max(ans, double(curr.f) / dists[n]);
	}

	cout << int(1e6*ans) << '\n';
}