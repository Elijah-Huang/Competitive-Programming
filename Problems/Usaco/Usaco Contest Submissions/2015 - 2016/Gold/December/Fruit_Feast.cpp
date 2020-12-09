#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("feast.in", "r", stdin); freopen("feast.out", "w", stdout);
	int t, a, b; cin >> t >> a >> b;
	vector<bool> pos(t + 1);
	pos[0] = 1;
	for (int i = 0; i < t; i++) {
		if (pos[i]) {
			if (i + a <= t) {
				pos[i + a] = 1;
			}
			if (i + b <= t) {
				pos[i + b] = 1;
			}
		}
	}
	for (int i = 0; i <= t; i++) {
		if (pos[i]) {
			pos[i / 2] = 1;
		}
	}
	for (int i = 0; i < t; i++) {
		if (pos[i]) {
			if (i + a <= t) {
				pos[i + a] = 1;
			}
			if (i + b <= t) {
				pos[i + b] = 1;
			}
		}
	}
	for (int i = t; i >= 0; i--) {
		if (pos[i]) {
			cout << i;
			return 0;
		}
	}
}