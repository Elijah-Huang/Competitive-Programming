#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("empty.in", "r", stdin); freopen("empty.out", "w", stdout);
	int n, k; cin >> n >> k;
	vector<bool> occupied(n);
	vector<int> cows(n);
	int ptr = 0;
	while (k--) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		int loc = b;
		for (int i = 0; i < y; i++) {
			loc = (a + loc) % n;
			cows[loc] += x;
		}
	}

	for (int i = 0; i < n; i++) {
		ptr = max(ptr, i);
		for (int j = 0; j < cows[i]; j++) {
			occupied[ptr % n] = 1;
			while (occupied[ptr % n]) {
				ptr += 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!occupied[i]) {
			cout << i;
			return 0;
		}
	}
}