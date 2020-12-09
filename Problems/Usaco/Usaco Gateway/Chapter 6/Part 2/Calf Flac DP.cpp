/*
ID: elijahj1
TASK: calfflac
LANG: C++14
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4;

bool dp[2][2001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("calfflac.in", "r", stdin); freopen("calfflac.out", "w", stdout);
	string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string original, converted, a;
	vector<int> convert_back(2e4);
	int	longest = 0, long_idx = -1;
	while (getline(cin, a)) {
		original.append(a + '\n');
	}

	for (int i = 0; i < original.length(); i++) {
		if (find(letters.begin(), letters.end(), original[i]) != letters.end()) {
			convert_back[converted.length()] = i;
			converted.push_back(tolower(original[i]));
		}
	}

	for (int start = converted.length() - 2; start >= 0; start--) {
		int curr_longest = 0;
		dp[0][1] = 1;
		dp[0][2] = converted[start] == converted[start + 1];
		for (int length = 3; length + start <= min(int(converted.length()), start + 1999); length++) {
			dp[0][length] = (dp[1][length - 2] and converted[start] == converted[start + length - 1]);
		}

		for (int len = 1; len <= 2000; len++) {
			curr_longest = max(curr_longest, dp[0][len] * len);
		}
		if (curr_longest >= longest) {
			longest = curr_longest;
			long_idx = start;
		}
		memcpy(dp[1], dp[0], sizeof(dp[0]));
	}
	
	cout << longest << '\n';
	cout << original.substr(convert_back[long_idx], convert_back[long_idx + longest - 1] - convert_back[long_idx] + 1) << '\n';
}