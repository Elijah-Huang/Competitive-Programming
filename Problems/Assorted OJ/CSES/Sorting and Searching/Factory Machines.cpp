#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, t; cin >> n >> t;
	vector<int> k(n);
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}

	long long l = 0, r = 1ll << 60;
	while (l != r) {
		long long m = (l + r) / 2;
		long long total = 0;
		for (int i = 0; i < n; i++) {
			if (total >= t) {
				break;
			}
			total += m / k[i];
		}
		if (total >= t) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}

	cout << l << '\n';
}