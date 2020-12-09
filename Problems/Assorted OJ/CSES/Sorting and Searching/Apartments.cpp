#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	vector<int> desired(n), apt_sizes(m);
	for (int i = 0; i < n; i++) {
		cin >> desired[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> apt_sizes[i];
	}

	sort(apt_sizes.begin(), apt_sizes.end());
	sort(desired.begin(), desired.end());

	int ans = 0;
	int apt_idx = 0;
	for (int i = 0; i < n; i++) {
		while (apt_idx < m and apt_sizes[apt_idx] < desired[i] - k) {
			apt_idx++;
		}
		if (apt_idx == m) {
			break;
		}

		if (desired[i] - k <= apt_sizes[apt_idx] and apt_sizes[apt_idx] <= desired[i] + k) {
			ans += 1;
			apt_idx++;
		}
	}

	cout << ans;
}