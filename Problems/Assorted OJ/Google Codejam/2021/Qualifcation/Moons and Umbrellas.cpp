#include<bits/stdc++.h>
using namespace std;

int t, x, y;
string s;
const int maxn = 1000;
// pos | last char 0->C 1->J
int dp[maxn][2];
string c = "CJ";

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cas = 1; cas <= t; cas++) {
		cin >> x >> y >> s;

		memset(dp, 0x3f, sizeof(dp));
		if (s[0] == '?') {
			dp[0][0] = dp[0][1] = 0;
		}
		else {
			dp[0][s[0] != 'C'] = 0;
		}
		for (int i = 1; i < s.length(); i++) {
			for (int j = 0; j < 2; j++) {
				if (s[i] == c[j] or s[i] == '?') {
					for (int k = 0; k < 2; k++) {
						dp[i][j] = min(dp[i][j], dp[i - 1][k] + x * (k == 0 and j == 1) + y * (k == 1 and j == 0));
					}
				}
			}
		}
		cout << "Case #" << cas << ": " << min(dp[s.length() - 1][0], dp[s.length() - 1][1]) << '\n';
	}
}