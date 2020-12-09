#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		bool worked = false;
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		for (int i = 1; i < n - 1; i++) {
			bool left = false;
			int l = 0;
			for (int j = i - 1; j >= 0; j--) {
				if (nums[j] < nums[i]) {
					left = true;
					l = j;
					break;
				}
			}
			if (!left) continue;
			bool right = false;
			int r = 0;
			for (int j = i + 1; j < n; j++) {
				if (nums[j] < nums[i]) {
					right = true;
					r = j;
					break;
				}
			}
			if (right) {
				cout << "YES\n";
				cout << l + 1 << ' ' <<  i + 1 << ' ' << r + 1 << '\n';
				worked = true;
				break;
			}
		}
		if (!worked) {
			cout << "NO\n";
		}
	}
}