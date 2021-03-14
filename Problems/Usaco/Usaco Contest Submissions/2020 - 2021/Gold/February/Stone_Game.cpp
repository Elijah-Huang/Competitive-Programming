// O(n + max(a_i)*log(max(a_i)*log(n))
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, a[maxn];
long long ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	for (int s = 1; s <= 1e6; s++) {
		vector<int> odd_val, odd_num;
		int l = 0, r = 0, val = 1;

		while (val * s <= 1e6 and odd_val.size() <= 2) {
			l = lower_bound(a, a + n, val * s) - a;
			r = lower_bound(a, a + n, (val+1) * s) - a;

			if ((r - l) & 1) {
				odd_num.push_back(r - l);
				odd_val.push_back(val);
			}
			val++;
		}

		if (odd_val.size() == 1 and odd_val[0] == 1 or 
			odd_val.size() == 2 and odd_val[1] - odd_val[0] == 1) {
			ans += odd_num.back();
		}
	}

	cout << ans;
}