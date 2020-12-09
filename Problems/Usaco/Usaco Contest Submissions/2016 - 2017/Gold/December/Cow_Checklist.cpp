#include<bits/stdc++.h>
using namespace std;

unsigned int dp[1001][1001][2];

struct point {
	int x, y;
};

int cost(point& a, point& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("checklist.in", "r", stdin); freopen("checklist.out", "w", stdout);
	int h, g; cin >> h >> g;
	vector<vector<point>> cows(2, vector<point>(1000));
	for (int i = 0; i < h; i++) {
		cin >> cows[0][i].x >> cows[0][i].y;
	}
	for (int i = 0; i < g; i++) {
		cin >> cows[1][i].x >> cows[1][i].y;
	}

	memset(dp, 0x7f, sizeof(dp));
	dp[1][0][0] = 0;
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= g; j++) {
			for (int loc = 0; loc <= 1; loc++) {
				if ((loc ? j : i) - 1 < 0) continue;
				if (i != h) {
					dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][loc] + cost(cows[loc][(loc ? j : i) - 1], cows[0][i]));
				}
				if (j != g) {
					dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][loc] + cost(cows[loc][(loc ? j : i) - 1], cows[1][j]));
				}
			}
		}
	}

	cout << dp[h][g][0];
}