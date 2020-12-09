#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("pails.in", "r", stdin); freopen("pails.out", "w", stdout);
	bool dp[101][101][101]{};
	dp[0][0][0] = 1;
	int x, y, k, m, mn_diff = 200;
	cin >> x >> y >> k >> m;
	for (int operation = 1; operation <= k; operation++) {
		for (int x1 = 0; x1 <= x; x1++) {
			for (int y1 = 0; y1 <= y; y1++) {
				if (dp[operation - 1][x1][y1]) {
					dp[operation][0][y1] = 1;
					dp[operation][x1][0] = 1;
					dp[operation][x][y1] = 1;
					dp[operation][x1][y] = 1;
					if (x1 + y1 > x) {
						dp[operation][x][y1 - (x - x1)] = 1;
					}
					else {
						dp[operation][x1 + y1][0] = 1;
					}
					if (x1 + y1 > y) {
						dp[operation][x1 - (y - y1)][y] = 1;
					}
					else {
						dp[operation][0][x1 + y1] = 1;
					}
					//mn_diff = min({ mn_diff, abs(m - x1), abs(m - y1), abs(m - x1 - y1)
						//, abs(m - x - y1), abs(m - y - x1) });
				}
			}
		}
	}
	for (int operation = 0; operation <= k; operation++) {
		for (int x1 = 0; x1 <= x; x1++) {
			for (int y1 = 0; y1 <= y; y1++) {
				if (dp[operation][x1][y1]){
					mn_diff = min(mn_diff, abs(m - x1 - y1));
				}
			}
		}
	}
	cout << mn_diff;
}