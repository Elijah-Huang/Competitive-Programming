// O(4*n^3/3) ~ 5e8
#include<bits/stdc++.h>
using namespace std;

const int maxn = 500, mod = 1e9 + 7;
int ans = 0;

int n;
string field[maxn];
// dp builds from the left and right of the string until it meets in the middle
int dp[maxn][maxn], dp2[maxn][maxn]; // dp[right moves for first][left moves for second]

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("palpath.in", "r", stdin); freopen("palpath.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> field[i];
	}
	
	dp[0][0] = 1;
	for (int length = 0; length <= n-2; length++) {
		for (int right = 0; right <= length; right++) {
			for (int left = 0; left <= length; left++) {
				for (int dr = 0; dr <= 1; dr++) {
					for (int dl = 0; dl <= 1; dl++) {
						if (field[length + 1 - (right + dr)][right + dr] ==
							field[n-1-(length+1-(left+dl))][n-1-(left+dl)] ){
							dp2[right + dr][left + dl] = (dp2[right + dr][left + dl] + dp[right][left]) % mod;
						}
					}
				}
			}
		}
		swap(dp, dp2);
		memset(dp2, 0, sizeof(dp2));
	}

	for (int right = 0; right < n; right++) {
		ans = (ans + dp[right][n - 1 - right]) % mod;
	}

	cout << ans;
}