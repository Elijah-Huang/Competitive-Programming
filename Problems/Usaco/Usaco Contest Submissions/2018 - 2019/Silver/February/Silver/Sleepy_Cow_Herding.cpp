#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("herding.in", "r", stdin);
	int n;
	cin >> n;
	vector<int> herd(n);
	for (int i = 0; i < n; i++) {
		cin >> herd[i];
	}
	sort(herd.begin(), herd.end());
	int gap = 0;
	for (int i = 1; i < n; i++) {
		gap += herd[i] - herd[i - 1] - 1;
	}
	int most_filledn = 0;
	for (int i = 0; i < n; i++) {
		most_filledn = max(most_filledn, int(upper_bound(herd.begin() + i, herd.end(), herd[i] + n-1) -
			(herd.begin() + i)));
	}
	int least = n - most_filledn;
	if (least == 1) {
		if (herd[n - 2] - herd[0] == n - 2 and herd[n-1] - herd[n-2] > 2) {
			least = 2;
		}
		if (herd[n - 1] - herd[1] == n - 2 and herd[1] - herd[0] > 2) {
			least = 2;
		}
	}
	int most = gap - min(herd[1] - herd[0] - 1, herd[n - 1] - herd[n - 2] - 1);
	freopen("herding.out", "w", stdout);
	cout << least << '\n';
	cout << most << '\n';
}