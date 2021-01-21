#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5, mod = 1e9 + 7;
int ans = 0;
string genome;
// pos | last char | char to match | next char to match
int dp[maxn][4][4][4];
int convert[100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> genome;

	convert['G'] = 0;
	convert['C'] = 1;
	convert['A'] = 2;
	convert['T'] = 3;

	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			if (genome[0] == '?') {
				for (int j = 0; j < 4; j++) {
					dp[0][j][k][j] = 1;
				}
			}
			else {
				dp[0][convert[genome[0]]][k][convert[genome[0]]] = 1;
			}
		}
	}

	for (int i = 0; i < genome.length()-1; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					vector<int> next_chars;
					if (genome[i + 1] == '?') {
						next_chars = { 0,1,2,3 };
					}
					else {
						next_chars = { convert[genome[i + 1]] };
					}
					
					for (auto j2 : next_chars) {
						// split btw i and i+1
						if (j == k) {
							dp[i + 1][j2][l][j2] = (dp[i + 1][j2][l][j2] + dp[i][j][k][l]) % mod;
						}
						// no split
						if (j != j2) {
							dp[i + 1][j2][k][l] = (dp[i + 1][j2][k][l] + dp[i][j][k][l]) % mod;
						}
					}

				}
			}
		}
	}

	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4; k++) {
			ans = (ans + dp[genome.length() - 1][k][k][j]) % mod;
		}
	}

	cout << ans;
}