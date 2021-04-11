#include<bits/stdc++.h>
using namespace std;

string s;
int mx[26][1001][1000]; // c | changed | R up to

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;

	cin >> s;

	for (int c = 0; c < 26; c++) {
		for (int i = 0; i < n; i++) {
			int count = 0;
			for (int j = i; j < n; j++) {
				if (s[j] - 'a' == c) {
					count += 1;
				}
				mx[c][j - i + 1 - count][j] = max(mx[c][j - i + 1 - count][j], j - i + 1);
			}
		}
	}

	for (int c = 0; c < 26; c++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < n; j++) {
				mx[c][i][j] = max({ mx[c][i][j], (i > 0 ? mx[c][i - 1][j] : 0), (j > 0 ? mx[c][i][j - 1] : 0) });
			}
		}
	}

	int q; cin >> q;
	while (q--) {
		char c; int m, p; cin >> c >> m >> p; p--;
		c -= 'a';
		cout << mx[c][m][p] << '\n';
	}
}