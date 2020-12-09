#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("dishes.in", "r", stdin); freopen("dishes.out", "w", stdout);
	int n; cin >> n;
	vector<int> stack(n);
	for (int i = 0; i < n; i++) {
		cin >> stack[i];
	}

	int l = 0, r = n - 1;
	while (l != r) {
		int m = (l + r + 1) / 2;
		bool worked = true;
		vector<int> dirty_plates(stack.begin(), stack.begin() + m + 1);
		vector<int> clean_plates = dirty_plates;
		int clean_idx = 0;
		sort(clean_plates.begin(), clean_plates.end());
		vector<vector<int>> soapy_plates(n);
		int soapy_l = 0; int soapy_r = 0;
		for (int i = 0; i < dirty_plates.size(); i++) {
			if (soapy_plates[soapy_l].empty()) {
				soapy_plates[soapy_l].push_back(dirty_plates[i]);
				soapy_r = soapy_l;
			}
			else {
				int l2 = soapy_l, r2 = soapy_r + 1;
				while (l2 != r2) {
					int m2 = (l2 + r2) / 2;
					if (m2 == soapy_r + 1 or soapy_plates[m2].back() > dirty_plates[i]) {
						r2 = m2;
					}
					else {
						l2 = m2 + 1;
					}
				}

				if (l2 != soapy_l and soapy_plates[l2-1].front() > dirty_plates[i]) {
					worked = false;
					break;
				}
				else {
					if (l2 == soapy_r + 1) {
						soapy_r++;
						soapy_plates[l2].push_back(dirty_plates[i]);
					}
					else {
						soapy_plates[l2].push_back(dirty_plates[i]);
					}
				}
			}

			while (!soapy_plates[soapy_l].empty() and soapy_plates[soapy_l].back() == clean_plates[clean_idx]) {
				soapy_plates[soapy_l].pop_back();
				if (soapy_plates[soapy_l].empty()) {
					soapy_l++;
				}
				clean_idx++;
			}
		}

		if (worked) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}

	cout << l + 1;
}