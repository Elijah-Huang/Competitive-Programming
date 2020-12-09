#include<bits/stdc++.h>
using namespace std;

struct edge {
	long long v, w;
};

int n, m;
vector<vector<edge>> adj;
vector<long long> dists;

struct edge_cmp {
	bool operator()(const edge& a, const edge& b) const {
		return a.w > b.w;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	adj.resize(n + 1);
	dists.resize(n + 1, 1ll << 62);
	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back({ b,w });
	}

	priority_queue<edge, vector<edge>, edge_cmp> pq;
	pq.push({ 1,0 });
	while (!pq.empty()) {
		edge curr = pq.top(); pq.pop();
		if (dists[curr.v] > curr.w) {
			dists[curr.v] = curr.w;
			for (auto& neighbor : adj[curr.v]) {
				pq.push({ neighbor.v, curr.w + neighbor.w });
			}
		}
	}
}
