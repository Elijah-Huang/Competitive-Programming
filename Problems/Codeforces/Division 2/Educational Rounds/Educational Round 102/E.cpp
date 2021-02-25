#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n, m;
vector<pair<int,int>> adj[maxn];
long long dist[maxn][2][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}

	memset(dist, 0x3f, sizeof(dist));
	dist[1][0][0] = 0;
	priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
	pq.push({ 0,1,0,0 });
	while (!pq.empty()) {
		auto curr = pq.top(); pq.pop();
		long long d = curr[0];
		int c = curr[1], mx = curr[2], mn = curr[3];
		
		if (dist[c][mx][mn] == d) {
			dist[c][mx][mn] = d;

			for (auto [v, w] : adj[c]) {
				if (dist[v][mx][mn] > d + w) {
					dist[v][mx][mn] = d + w;
					pq.push({ d + w,v,mx,mn });					
				}	
				if (mx == 0) {
					if (dist[v][1][mn] > d) {
						dist[v][1][mn] = d;
						pq.push({ d,v,1,mn });
					}
				}
				if (mn == 0) {
					if (dist[v][mx][1] > d + 2 * w) {
						dist[v][mx][1] = d + 2 * w;
						pq.push({ d + 2 * w,v,mx,1 });
					}
				}
				if (mx == 0 and mn == 0) {
					if (dist[v][1][1] > d + w) {
						dist[v][1][1] = d + w;
						pq.push({ d + w,v,1,1 });
					}
				}
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << dist[i][1][1] << ' ';
	}
}