#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

struct point {
	int x, y;
};

int energy(point& a, point &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("radio.in", "r", stdin); freopen("radio.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<vector<point>> paths(2, vector<point>(1001));
	for (int i = 0; i < 2; i++) {
		cin >> paths[i][0].x >> paths[i][0].y;
	}
	vector<string> strs(2);
	for (int j = 0; j < 2; j++) {
		cin >> strs[j];
		for (int i = 0; i < strs[j].size(); i++) {
			if (strs[j][i] == 'N') {
				paths[j][i + 1] = { paths[j][i].x, paths[j][i].y + 1 };
			}
			else if (strs[j][i] == 'E') {
				paths[j][i + 1] = { paths[j][i].x + 1, paths[j][i].y };
			}
			else if (strs[j][i] == 'S') {
				paths[j][i + 1] = { paths[j][i].x, paths[j][i].y - 1};
			}
			else if (strs[j][i] == 'W') {
				paths[j][i + 1] = { paths[j][i].x - 1, paths[j][i].y };
			}
		}
	}

	memset(dp, 0x7f , sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i != n) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + energy(paths[0][i + 1], paths[1][j]));
			}
			if (j != m) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + energy(paths[0][i], paths[1][j + 1]));
			}
			if (i != n and j != m) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + energy(paths[0][i + 1], paths[1][j + 1]));
			}
		}
	}
	
	cout << dp[n][m];
}