#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	const int maxn = 2e5;
	int n, m, a[maxn];
	cin >> n >> m;
	if (n > m) {
		cout << 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int ans = 1;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i+1; j < n; j++) {
				ans = (ans * (abs(a[j] - a[i]) % m) % m);
			}
		}
		cout << ans;
	}

}