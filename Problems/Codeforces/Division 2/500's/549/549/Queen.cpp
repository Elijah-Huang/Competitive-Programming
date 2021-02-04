#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int n;
bool irremovable[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p, c;
		cin >> p >> c;

		if (c == 0) {
			irremovable[i] = 1;
			if (p > 0) {
				irremovable[p] = 1;
			}
		}
	}

	bool removed = 0;
	for (int i = 1; i <= n; i++) {
		if (!irremovable[i]) {
			removed = 1;
			cout << i << ' ';
		}
	}

	if (!removed) {
		cout << -1;
	}
}