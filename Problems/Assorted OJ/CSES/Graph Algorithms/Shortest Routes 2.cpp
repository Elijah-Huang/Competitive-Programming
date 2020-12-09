#include<bits/stdc++.h>
using namespace std;

int n, m, q;
long long dists[501][501];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q;
	memset(dists, 0x3f, sizeof(dists));
	for (int i = 1; i <= n; i++) {
		dists[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		long long a, b, w; cin >> a >> b >> w;
		dists[a][b] = dists[b][a] = min(dists[a][b],w);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
			}
		}
	}

	while (q--) {
		int a, b; cin >> a >> b;
		if (dists[a][b] == 0x3f3f3f3f3f3f3f3f) {
			cout << -1 << '\n';
		}
		else {
			cout << dists[a][b] << '\n';
		}
	}
}
