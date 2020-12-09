#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	cout << (n - 1 + m - 1 + (n - 1) * m + m - 1) << '\n';
	for (int i = 0; i < n - 1; i++) {
		cout << 'D';
	}
	for (int i = 0; i < m - 1; i++) {
		cout << 'L';
	}
	bool direction = true;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (direction) {
				cout << 'U';
			}
			else {
				cout << 'D';
			}
		}
		if (i != m - 1) {
			cout << 'R';
		}
		direction = not direction;
	}
}