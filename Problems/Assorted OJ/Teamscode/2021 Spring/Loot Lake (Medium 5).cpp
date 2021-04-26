#include<bits/stdc++.h>
using namespace std;

vector<int> dx = { 0,-1,0,1 };
vector<int> dy = { 1,0,-1,0 };

const int maxn = 1000, mod = 1e9 + 7;
int n, m;
bool lava[maxn][maxn];
int dp[maxn][maxn]; // dp[i][j] = the # of ways to get to location i,j with a shortest path from the top left
int dist[maxn][maxn];
bool visited[maxn][maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lava[i][j];
		}
	}

	// 2 2 2 2 3 3 3 3 3 
	memset(dist, 0x3f, sizeof(dist));
	dp[0][0] = 1;
	dist[0][0] = 0;
	queue<pair<int, int>> q({{ 0,0 }});
	while (!q.empty()) {
		auto curr = q.front(); q.pop();
		int i = curr.first;
		int j = curr.second;

		if (!visited[i][j]) {
			visited[i][j] = 1;

			for (int k = 0; k < 4; k++) {
				int newi = i + dx[k];
				int newj = j + dy[k];

				if (0 <= newi and newi < n and 0 <= newj and newj < m and !lava[newi][newj]) {
					if (!visited[newi][newj] and dist[newi][newj] >= dist[i][j] + 1) {
						dist[newi][newj] = dist[i][j] + 1;
						dp[newi][newj] = (dp[newi][newj] + dp[i][j]) % mod;
						q.push({ newi,newj });
					}
				}
			}
		}
	}

	cout << dp[n-1][m-1];
}