#include<bits/stdc++.h>
using namespace std;

string s;
bool has_letter[128];
string alphabet;
int counts[128][128];
int dp[1 << 20];
int cost[20][1 << 20];

// n*2^n
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		if (!has_letter[s[i]]) {
			has_letter[s[i]] = 1;
			alphabet.push_back(s[i]);
		}
		
		if (i < int(s.size()) - 1) {
			counts[s[i]][s[i + 1]]++;
		}
	}

	// in n * 2^n time precompute the cost for transitions
	for (int i = 0; i < alphabet.size(); i++) {
		// keep track of this to remove an n factor
		int largest_pow = 0;

		for (int j = 1; j < 1 << alphabet.size(); j++) {
			if (1<<( largest_pow+1) == j) {
				largest_pow += 1;
			}

			cost[i][j] = cost[i][j - (1 << largest_pow)] + counts[alphabet[largest_pow]][alphabet[i]];
		}
	}
	
	// do dp
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i < 1 << alphabet.size(); i++) {
		for (int j = 0; j < alphabet.size(); j++) {
			if ((i >> j) & 1) {
				dp[i] = min(dp[i], dp[i - (1 << j)] + cost[j][i]);
			}
		}
	}

	cout << 1 + dp[(1 << alphabet.size()) - 1];
}