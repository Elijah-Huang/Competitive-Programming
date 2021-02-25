#include<bits/stdc++.h>
using namespace std;

const int maxsz = 2e6;
vector<long long> pos(1);

int squares_intersecting[maxsz];

long long least_geq_square(long long x) {
	int l = 1, r = 1e9 + 1;
	while (l != r) {
		long long m = (l + r) / 2;
		if (m * m >= x) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}

	return l;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 3; i < 60; i++) {
		for (int j = 2; j <= 1e6; j++) {
			long long a = 1;
			for (int k = 0; k < i; k++) {
				if (a > (long long)(1e18) / j) {
					a = -1;
					break;
				}
				a *= j;
			}

			if (a == -1) {
				break;
			}
			else {
				pos.push_back(a);
			}
		}
	}

	sort(pos.begin(), pos.end());
	pos.resize(unique(pos.begin(), pos.end()) - pos.begin());

	for (int i = 0; i < pos.size(); i++) {
		long long x = least_geq_square(pos[i]);
		squares_intersecting[i] = x * x == pos[i];
	}
	partial_sum(squares_intersecting, squares_intersecting + pos.size(), squares_intersecting);

	int q; cin >> q;
	while (q--) {
		long long l, r; cin >> l >> r;

		int r2 = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
		int l2 = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
		cout << r2 - l2 + least_geq_square(r + 1) - least_geq_square(l) - (squares_intersecting[r2 - 1] - squares_intersecting[l2 - 1]) << '\n';
	}
}