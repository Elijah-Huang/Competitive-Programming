#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("bbreeds.in", "r", stdin); freopen("bbreeds.out", "w", stdout);
	string s;
	cin >> s;
	vector<int> unmatched(s.length());
	vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1));
	dp[s.length()][0] = 1;
	unmatched[0] = 1;
	for (int i = 1; i < s.length(); i++) {
		unmatched[i] = unmatched[i-1] + (s[i] == '(' ? 1 : -1);
	}
	//unmatched[i] - j( which is unmatched to cowtype1) = unmatched to cowtype2
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '(') {
			for (int j = 0; j <= unmatched[i] - 1; j++) {
				dp[i][j] = (dp[i + 1][j + 1] + dp[i + 1][j]) % 2012;
			}
		}
		else {
			dp[i][0] = dp[i + 1][0];
			for (int j = 1; j <= unmatched[i] + 1; j++) {
				dp[i][j] = (dp[i + 1][j - 1] + dp[i + 1][j]) % 2012;
			}
		}
	}
	cout << dp[0][0];

}