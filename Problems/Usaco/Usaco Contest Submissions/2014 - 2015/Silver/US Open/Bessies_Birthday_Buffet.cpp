#include<bits/stdc++.h>
using namespace std;


struct edge {
	int v, w;
};

vector<vector<int>> adj;

void bfs(int start, vector<int>& dist) {
	queue<pair<int, int>> q({ {start,0 } });
	while (!q.empty()) {
		auto curr = q.front(); q.pop();
		if (dist[curr.first] == -1) {
			dist[curr.first] = curr.second;
			for (auto neighbor : adj[curr.first]) {
				q.push({ neighbor, curr.second + 1 });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("buffet.in", "r", stdin); freopen("buffet.out", "w", stdout);
	int n, e; cin >> n >> e;
	vector<pair<int,int>> quality(n);
	vector<int> convert1(n);
	vector<int> convert2(n);
	vector<int> mx_dist(n);
	adj.resize(n);
	for (int i = 0; i < n; i++) {
		int q, d; cin >> q >> d;
		quality[i] = { q,i };
		for (int j = 0; j < d; j++) {
			int v; cin >> v; v--;
			adj[i].push_back(v);
		}
	}

	sort(quality.begin(), quality.end());
	for (int i = 0; i < n; i++) {
		convert1[quality[i].second] = i;
		convert2[i] = quality[i].second;
	}

	vector<vector<int>> s_dists(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		bfs(i, s_dists[i]);
	}
	
	vector<vector<edge>> adj2(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j and s_dists[i][j] != -1 and quality[convert1[i]].first < quality[convert1[j]].first) {
				adj2[i].push_back({ j,quality[convert1[j]].first - e * s_dists[i][j] });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		mx_dist[i] = quality[i].first;
	}
	for (int i = 0; i < n; i++) {
		for (auto neighbor : adj2[convert2[i]]) {
			mx_dist[convert1[neighbor.v]] = max(mx_dist[convert1[neighbor.v]], mx_dist[i] + neighbor.w);
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, mx_dist[i]);
	}

	cout << mx << '\n';
}