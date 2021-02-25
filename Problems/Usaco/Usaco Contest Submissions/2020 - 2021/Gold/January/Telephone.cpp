#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e4, maxk = 50;
int n, k;
int line[maxn];
int s[maxk][maxk];
int closest[2][maxk][maxn];
vector<int> dp[maxn * (maxk + 1)];
bool visited[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	memset(closest, 0xff, sizeof(closest));

	for (int i = 0; i < n; i++) {
		cin >> line[i];
		line[i]--;
	}

	for (int i = 0; i < k; i++) {
		string bits; cin >> bits;
		for (int j = 0; j < k; j++) {
			s[i][j] = bits[j] == '1';
		}
	}

	for (int b = 0; b < k; b++) {
		int curr = -1;
		for (int i = 0; i < n; i++) {
			closest[0][b][i] = curr;
			if (line[i] == b) {
				curr = i;
			}
		}

		curr = -1;
		for (int i = n - 1; i >= 0; i--) {
			closest[1][b][i] = curr;
			if (line[i] == b) {
				curr = i;
			}
		}
	}

	dp[0].push_back(0);
	for (int i = 0; i <= n*k; i++) {
		for (auto j : dp[i]) {
			if (!visited[j]) {
				visited[j] = 1;

				// found
				if (j == n - 1) {
					cout << i;
					return 0;
				}
				else {
					for (int b = 0; b < k; b++) {
						if (s[line[j]][b]) {
							// transition to the closest cow on the left and on the right for this breed
							for (int t = 0; t < 2; t++) {
								if (closest[t][b][j] != -1) {
									dp[i + abs(j - closest[t][b][j])].push_back(closest[t][b][j]);
								}
							}
						}
					}

					// can transition to the final cow
					if (s[line[j]][line[n - 1]]) {
						dp[i + abs(j - (n - 1))].push_back(n - 1);
					}
				}
			}
		}
	}

	cout << -1;
}