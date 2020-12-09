#include<bits/stdc++.h>
using namespace std;

int dp[10001][1001];
int new_max_suffix[26][1000];

vector<int> comp_pf(string& m) {
	vector<int> pf(m.length());
	for (int i = 1; i < m.length(); i++) {
		int j = pf[i - 1];
		while (j > 0 and m[j] != m[i]) {
			j = pf[j - 1];
		}
		pf[i] = j + (m[j] == m[i]);
	}
	return pf;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
	string n; cin >> n;
	string m; cin >> m;
	int mn_change = 1e9;
	vector<int> pf = comp_pf(m);

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < m.length(); j++) {
			int k = j;
			while (k > 0 and m[k] -'a'!= i) {
				k = pf[k - 1];
			}
			new_max_suffix[i][j] = k + (m[k] - 'a' == i);
		}
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < n.length(); i++) {
		for (int j = 0; j < m.length(); j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			dp[i + 1][new_max_suffix[n[i] - 'a'][j]] = min(dp[i + 1][new_max_suffix[n[i] - 'a'][j]], dp[i][j]);
		}
	}
	
	for (int i = 0; i < m.length(); i++) {
		mn_change = min(mn_change, dp[n.length()][i]);
	}

	cout << mn_change;
}	