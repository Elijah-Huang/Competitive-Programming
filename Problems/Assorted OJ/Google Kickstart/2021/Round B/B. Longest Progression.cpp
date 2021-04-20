#include<bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 1;
int t, n;
int a[maxn], d[maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cse = 1; cse <= t; cse++) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 1; i < n; i++) {
			d[i-1] = a[i] - a[i - 1];
		}
		map<int, vector<pair<int, int>>> segss;
		
		for (int i = 0; i < n-1; i++) {
			if (i == 0 or d[i] != d[i - 1]) {
				segss[d[i]].push_back({ i,1 });
			}
			else {
				segss[d[i]].back().second += 1;
			}
		}

		int ans = 2;
		for (int i = 0; i < n - 2; i++) {
			if (a[i] + a[i + 2] % 2 == 0) {
				ans = 3;
			}
		}
		
		for (auto [diff, segs] : segss) {
			// increasing 1 seg by 1
			for (int i = 0; i < segs.size(); i++) {
				ans = max(ans, segs[i].second + 2);
			}

			// increasing 1 seg by 2

			// before first seg
			int before = segs[0].first - 2;
			if (before >= 0 and d[before] + d[before + 1] == 2 * diff) {
				ans = max(ans, segs[0].second + 3);
			}
			// after seg
			for (int i = 0; i < segs.size(); i++) {
				int after1 = segs[i].first + segs[i].second;
				if (after1 + 1 < n - 1 and d[after1] + d[after1 + 1] == 2 * diff) {
					ans = max(ans, segs[i].second + 3);
				}
			}

			// joining 2 segs
			for (int i = 1; i < segs.size(); i++) {
				int after1 = segs[i - 1].first + segs[i - 1].second;
				if (after1 + 2 == segs[i].first and d[after1] + d[after1+1] == 2*diff) {
					ans = max(ans, segs[i - 1].second + segs[i].second + 2 + 1);
				}
			}
		}

		cout << "Case #" << cse << ": " << min(n, ans) << '\n';
	}
}