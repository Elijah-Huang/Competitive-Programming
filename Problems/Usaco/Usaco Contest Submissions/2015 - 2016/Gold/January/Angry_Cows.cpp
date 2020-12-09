#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("angry.in", "r", stdin); freopen("angry.out", "w", stdout);
	cout << fixed << setprecision(1);
	int n; cin >> n;
	vector<int> bales(n);
	vector<int> right_need(n, 2e9);
	right_need[0] = 0;
	vector<int> left_need(n, 2e9);
	left_need[n-1] = 0;
	for (int i = 0; i < n; i++) {
		cin >> bales[i];
	}

	sort(bales.begin(), bales.end());

	int last_idx = 0;
	for (int i = 1; i < n; i++) {
		while (bales[i] - bales[last_idx + 1] >= right_need[last_idx + 1] + 1) {
			last_idx++;
		}
		right_need[i] = min(bales[i] - bales[last_idx], right_need[last_idx + 1] + 1);
	}
	last_idx = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		while (bales[last_idx - 1] - bales[i] >= left_need[last_idx - 1] + 1) {
			last_idx--;
		}
		left_need[i] = min(bales[last_idx] - bales[i], left_need[last_idx - 1] + 1);
	}

	double r = 5e8 + 5;
	for (int i = 0; i < n; i++) {
		int L = (right_need[i] + 1)*2, R = 1e9 + 10;
		if (L > R) {
			break;
		}
		while(L != R){
			int m = (L + R) / 2;
			int furthest = bales[i] + m;
			int bl = 0, br = n - 1;
			while (bl != br) {
				int m2 = (bl + br + 1) / 2;
				if (bales[m2] > furthest) {
					br = m2 - 1;
				}
				else {
					bl = m2;
				}
			}
			if (m/2.0 - 1 >= left_need[br] - 1e-5) {
				R = m;
			}
			else {
				L = m + 1;
			}
		}

		r = min(r, R / 2.0);
	}

	cout << r << '\n';
}