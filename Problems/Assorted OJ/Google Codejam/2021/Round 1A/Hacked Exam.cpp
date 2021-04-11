#include<bits/stdc++.h>
using namespace std;

int t, n, q;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cse = 1; cse <= t; cse++) {
		cin >> n >> q;

		vector<string> a(n), vector<int> s(n);
		vector<int> valid;

		for (int i = 0; i < n; i++) {
			cin >> a[i] >> s[i];
		}

		for (int i = 0; i < (1 << q); i++) {
			vector<int> s2(n);
			for (int j = 0; j < q; j++) {
				for (int k = 0; k < n; k++) {
					if (((i >> j) & 1) and a[k][j] == 'T') {
						s2[k] += 1;
					}
				}
			}

			if (s2 == s) {
				valid.push_back(i);
			}
		}

		vector<int> tot_true(valid.size());
		for (auto i : valid) {
			for (int j = 0; j < q; j++) {
				for (int k = 0; k < n; k++) {
					if (((i >> j) & 1) and a[k][j] == 'T') {
						tot_true[k] += 1;
					}
				}
			}
		}

		cout << "Case #" << cse << ": " << '\n';
	}
}