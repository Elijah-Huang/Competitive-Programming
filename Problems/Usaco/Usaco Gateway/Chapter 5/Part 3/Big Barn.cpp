/*
ID: elijahj1
TASK: bigbrn
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("bigbrn.in", "r", stdin); freopen("bigbrn.out", "w", stdout);
	int n, t;
	cin >> n >> t;
	cout << n;
	vector<vector<int>> barn(n + 1, vector<int>(n + 1, 1));
	for (int i = 0; i < n; i++) {
		barn[i][0] = 0;
	}
	for (int j = 0; j < n; j++) {
		barn[0][j] = 0;
	}
	while (t--) {
		int i, j;
		cin >> i >> j;
		barn[i][j] = 0;
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (barn[i][j] == 1) {
				barn[i][j] = 1 + min({barn[i - 1][j], barn[i][j - 1], barn[i - 1][j - 1] });
				mx = max(mx, barn[i][j]);
			}
		}
	}
	cout << mx << '\n';

}