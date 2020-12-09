#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("angry.in", "r", stdin); freopen("angry.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> points(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i];
	}
	sort(points.begin(), points.end());
	int L = 0, R = int(5e8);
	while (L != R) {
		int m = (L + R) / 2;
		int loc = 0;
		bool worked = false;
		for (int i = 0; i < k; i++) {
			int end = points[loc] + 2*m;
			while (loc < n and end >= points[loc]) {
				loc++;
			}
			if (end >= points[n-1]) {
				worked = true;
				break;
			}
		}
		if (worked) {
			R = m;
		}
		else {
			L = m + 1;
		}
	}
	cout << L;
}