#include<bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("marathon.in", "r", stdin); freopen("marathon.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<point> points(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	}

	int** dp = new int*[501];
	for (int i = 0; i < 501; i++) {
		dp[i] = new int[500];
		for (int j = 0; j < 500; j++) {
			dp[i][j] = 1 << 30;
		}
	}
	dp[0][0] = 0;
	for (int loc = 0; loc < n - 1; loc++) {
		for (int skipped = 0; skipped <= loc; skipped++) {
			for (int new_loc = loc + 1; new_loc < n; new_loc++) {
				int dist_traveled = abs(points[loc].x - points[new_loc].x) + abs(points[loc].y - points[new_loc].y);
				dp[new_loc][skipped + new_loc - loc - 1] = min(dp[loc][skipped] + dist_traveled, dp[new_loc][skipped + new_loc - loc - 1]);
			}
		}
	}

	cout << dp[n-1][k];
}