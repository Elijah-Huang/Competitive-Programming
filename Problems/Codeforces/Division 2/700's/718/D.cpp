#include<bits/stdc++.h>
using namespace std;

struct edge {
	int i, j, w;
};

const int maxn = 500;
int n, m, k;
bool vis[maxn][maxn][11];
int dp[maxn][maxn][11];

vector<edge> adj[maxn][maxn];

int solve(int i, int j, int k) {
	if (vis[i][j][k]) {
		return dp[i][j][k];
	}

	if (k == 0) {
		return 0;
	}

	int mn = 1 << 30;
	for (auto [i2, j2, w] : adj[i][j]) {
		mn = min(mn, w + solve(i2, j2, k - 1));
	}

	dp[i][j][k] = mn;
	vis[i][j][k] = 1;

	return mn;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m >> k;

	if (k & 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << -1 << ' ';
			}
			cout << '\n';
		}

		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			int w; cin >> w;

			adj[i][j].push_back({ i,j + 1,w });
			adj[i][j + 1].push_back({ i,j,w });
		}
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m; j++) {
			int w; cin >> w;

			adj[i][j].push_back({ i + 1,j,w });
			adj[i + 1][j].push_back({ i,j,w });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << 2*solve(i, j, k/2) << ' ';
		}
		cout << '\n';
	}
}