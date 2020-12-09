#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("convention.in", "r", stdin); freopen("convention.out", "w", stdout);
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> arrival(n);
	for (int i = 0; i < n; i++) {
		cin >> arrival[i];
	}
	sort(arrival.begin(), arrival.end());
	int L = 0, R = int(1e9);
	while (L != R) {
		int M = (L + R) / 2;
		bool worked = true;
		int idx = -1;
		int last_idx = -1;
		int left = m;
		while (idx < n-1 and left) {
			idx++;
			last_idx = idx;
			while (idx < n-1 and idx - last_idx != c - 1 and
				arrival[last_idx] + M >= arrival[idx + 1]) {
				idx++;
			}
			left--;
		}
		if (idx == n - 1) {
			R = M;
		}
		else {
			L = M + 1;
		}
	}
	cout << L;
}