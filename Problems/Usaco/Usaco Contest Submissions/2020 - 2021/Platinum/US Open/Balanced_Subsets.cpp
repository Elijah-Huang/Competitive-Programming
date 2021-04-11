#include<bits/stdc++.h>
using namespace std;

const int maxn = 150, mod = 1e9 + 7;
int n;
string pasture[maxn];
// row | 0 -> no gaps 1 -> gap on right 2 -> gap on left 3 -> gap on both sides | L | R  
long long dp[maxn][4][maxn][maxn];
// sum of all states inside the range (use this with complementary counting later)
long long subs_inside[4][maxn][maxn];
long long ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> pasture[i];
	}


	// base case
	for (int row = 0; row < n; row++) {
		for (int l = 0; l < n; l++) {
			for (int r = l; r < n; r++) {
				if (pasture[row][r] == '.') {
					break;
				}

				dp[row][0][l][r] = 1;
			}
		}
	}

	// transitions (pull dp so you can transition in O(1) with precomputation)
	for (int row = 1; row < n; row++) {
		// precomputation
		for (int gap = 0; gap < 4; gap++) {
			memcpy(subs_inside[gap], dp[row-1][gap], sizeof(subs_inside[gap]));

			for (int r = 1; r < n; r++) {
				for (int l = r - 1; l >= 0; l--) {
					subs_inside[gap][l][r] += subs_inside[gap][l + 1][r] + subs_inside[gap][l][r - 1];
					if (l + 2 <= r) {
						subs_inside[gap][l][r] -= subs_inside[gap][l + 1][r - 1];
					}
					subs_inside[gap][l][r] %= mod;
				}
			}
		}

		// transitions
		for (int l = 0; l < n; l++) {
			for (int r = l; r < n; r++) {
				if (pasture[row][r] == '.') {
					break;
				}

				dp[row][0][l][r] += subs_inside[0][l][r];

				if (r < n - 1) {
					dp[row][1][l][r] += subs_inside[0][l][n - 1]
						- subs_inside[0][r + 1][n - 1]
						- subs_inside[0][l][r];
				}
				dp[row][1][l][r] += subs_inside[1][l][n - 1]
					- (r + 1 < n ? subs_inside[1][r + 1][n - 1] : 0)
					- (l + 1 <= r ? subs_inside[1][l][r - 1] : 0);

				if (0 < l) {
					dp[row][2][l][r] += subs_inside[0][0][r]
						- subs_inside[0][0][l - 1]
						- subs_inside[0][l][r];
				}
				dp[row][2][l][r] += subs_inside[2][0][r]
					- (l - 1 >= 0 ? subs_inside[2][0][l - 1] : 0)
					- (l + 1 <= r ? subs_inside[2][l + 1][r] : 0);
				
				if (0 < l) {
					dp[row][3][l][r] += subs_inside[1][0][n - 1]
						- (r - 1 >= 0 ? subs_inside[1][0][r - 1] : 0)
						- subs_inside[1][l][n - 1]
						+ (l - 1 + 2 <= r ? subs_inside[1][l][r - 1] : 0);
				}
				if (r < n - 1) {
					dp[row][3][l][r] += subs_inside[2][0][n - 1]
						- subs_inside[2][0][r]
						- (l + 1 < n ? subs_inside[2][l + 1][n - 1] : 0)
						+ (l - 1 + 2 <= r ? subs_inside[2][l + 1][r] : 0);
				}
				if (0 < l and r < n - 1) {
					dp[row][3][l][r] += subs_inside[0][0][n - 1]
						- subs_inside[0][0][r]
						- subs_inside[0][l][n - 1]
						+ subs_inside[0][l][r];
				}
				dp[row][3][l][r] += subs_inside[3][0][n - 1]
					- (l + 1 < n ? subs_inside[3][l + 1][n - 1] : 0)
					- (r - 1 >= 0 ? subs_inside[3][0][r - 1] : 0)
					+ (l + 2 <= r ? subs_inside[3][l + 1][r - 1] : 0);

				for (int gap = 0; gap < 4; gap++) {
					dp[row][gap][l][r] %= mod;
				}
			}
		}
	}

	for (int row = 0; row < n; row++) {
		for (int l = 0; l < n; l++) {
			for (int r = l; r < n; r++) {
				for (int gap = 0; gap < 4; gap++) {
					ans += dp[row][gap][l][r];
				}
			}
		}
	}

	cout << ((ans % mod) + mod) % mod;
}