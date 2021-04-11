#include<bits/stdc++.h>
using namespace std;

int a[1000][1000], b[1000][1000], c[1000][1000];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int ra, ca, rb, cb;
	cin >> ra >> ca >> rb >> cb;

	if (ca != rb) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < ra; i++) {
		for (int j = 0; j < ca; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < rb; i++) {
		for (int j = 0; j < cb; j++) {
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < max(ra, rb); i++) {
		for (int j = 0; j < max(ca, cb); j++) {
			if (i < ra and j < ca) {
				c[i][j] += a[i][j];
			}
			if (i < rb and j < cb) {
				c[i][j] += b[i][j];
			}
		}
	}

	for (int i = 0; i < max(ra, rb); i++) {
		for (int j = 0; j < max(ca, cb); j++) {
			cout << c[i][j] << ' ';
		}
		cout << '\n';
	}

}