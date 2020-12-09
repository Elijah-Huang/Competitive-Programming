#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("vacation.in", "r", stdin); freopen("vacation.out", "w", stdout);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<vector<long long>> dist(n, vector<long long>(n, 1ll << 61));
	for (int i = 0; i < m; i++) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		u--; v--;
		dist[u][v] = min(dist[u][v],w);
	}

	for (int i = 0; i < n; i++) {
		dist[i][i] = 0;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int worked = 0;
	long long mn_cost = 0;
	long long max_mn_dist = 2e10;
	while (q--) {
		int a, b; 
		cin >> a >> b;
		a--; b--;
		long long mn_dist = 1ll << 62;
		for (int hub = 0; hub < k; hub++) {
			long long curr_dist = dist[a][hub] + dist[hub][b];
			mn_dist = min(mn_dist, curr_dist);
		}
		if (mn_dist <= max_mn_dist) {
			worked += 1;
			mn_cost += mn_dist;
		}
	}

	cout << worked << '\n';
	cout << mn_cost << '\n';
}