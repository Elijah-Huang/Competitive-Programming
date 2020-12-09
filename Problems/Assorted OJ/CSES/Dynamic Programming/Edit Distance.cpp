#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[5001][5001];

int dfs(int prefix1, int prefix2) {
	if (dp[prefix1][prefix2] != 0x3f3f3f3f) {
		
	}
	else if (prefix1 == s1.length()) {
		dp[prefix1][prefix2] = int(s2.length()) - prefix2;
	}
	else if (prefix2 == s2.length()) {
		dp[prefix1][prefix2] = int(s1.length()) - prefix1;
	}
	else {
		if (s1[prefix1] == s2[prefix2]) {
			dp[prefix1][prefix2] = dfs(prefix1 + 1, prefix2 + 1);
		}
		else {
			dp[prefix1][prefix2] = 1 + min({
			dfs(prefix1 + 1, prefix2 + 1),
			dfs(prefix1 + 1, prefix2),
			dfs(prefix1, prefix2 + 1) });
		}
	}

	return dp[prefix1][prefix2];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s1 >> s2;

	memset(dp, 0x3f, sizeof(dp));
	cout << dfs(0, 0);
}