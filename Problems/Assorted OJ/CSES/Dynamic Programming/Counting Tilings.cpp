#include<bits/stdc++.h>
using namespace std;

int n, m;
const int mod = 1e9 + 7;
int dp[1001][1 << 10];
vector<int> transitions[1 << 10];

int main() {
	cin >> n >> m;

	for (int i = 0; i < 1 << n; i++) {
		int new_state = i ^ ((1 << n) - 1);

		for (int vert_tile = 0; vert_tile <= n/2; vert_tile++) {
			vector<int> perm;
			for (int j = 0; j < n - 2 * vert_tile; j++) {
				perm.push_back(1);
			}
			for (int j = 0; j < vert_tile; j++) {
				perm.push_back(2);
			}

			do {
				bool fail = false;
				int trans_state = new_state;

				int row = 0;
				for (int j = 0; j < perm.size(); j++) {
					if (perm[j] == 2) {
						if (((new_state >> row) & 1) == 0 and ((new_state >> (row + 1)) & 1) == 0) {
							trans_state += 1 << row;
							trans_state += 1 << (row + 1);
						}
						else {
							fail = true;
							break;
						}
					}

					row += perm[j];
				}

				if (!fail) {
					transitions[i].push_back(trans_state);
				}
				
			} while (next_permutation(perm.begin(), perm.end()));
		}
	}

	dp[0][(1 << n) - 1] = 1;
	for (int i = 0; i < m; i++) {
		for (int state = 0; state < 1 << n; state++) {
			for (auto new_state : transitions[state]) {
				dp[i+1][new_state] = (dp[i+1][new_state] + dp[i][state]) % mod;
			}
		}
	}

	cout << dp[m][(1 << n) - 1];
}