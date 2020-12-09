#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	const int maxn = 1e5;
	int t, a[maxn];
	cin >> t;
	while (t--) {
		int m;
		long long n;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		long long tot = accumulate(a, a + m, 0ll);
		if (tot < n) {
			cout << -1 << '\n';
		}
		else {
			int bits[61]{};
			for (int i = 0; i < m; i++) {
				int curr = 1;
				int idx = 0;
				while (curr <= a[i]) {
					if (a[i] & curr) {
						bits[idx] ++;
					}
					curr <<= 1;
					idx++;
				}
			}
			/*
			int need[61]{};
			int idx = 0;
			while (n) {
				need[idx] += n & 1;
				n >>= 1;
				idx++;
			}
			*/
			bitset<60> need = bitset<60>(n);
			int splits = 0;
			for (int i = 0; i < 60; i++) {
				if (need[i]) {
					if (bits[i]) {
						bits[i]--;
						bits[i + 1] += bits[i] / 2;
					}
					else {
						int curr = i + 1;
						while (bits[curr] == 0) {
							curr++;
						}
						bits[curr]--;
						splits += curr - i;
						for (int j = i; j < curr; j++) {
							bits[j]++;
						}
					}
				}
				else {
					bits[i + 1] += bits[i] / 2;
				}
			}
			cout << splits << '\n';
		}
	}
}