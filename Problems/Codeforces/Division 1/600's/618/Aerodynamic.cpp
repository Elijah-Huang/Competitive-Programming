#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	const int maxn = 1e5 + 1;
	int n, x[maxn], y[maxn];
	cin >> n;
	if (n % 2 == 1) {
		cout << "No\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			cin >> y[i];
		}
		x[n] = x[0];
		y[n] = y[0];
		bool fail = false;
		for (int i = 0; i < n / 2; i++) {
			if (!(x[i + 1] - x[i] + x[i + 1 + n / 2] - x[i + n / 2] == 0
				and y[i + 1] - y[i] + y[i + 1 + n / 2] - y[i + n / 2] == 0)) {
				fail = true;
				break;
			}
		}
		//fail ? cout << "No\n" : cout << "Yes\n";
		cout << (fail ? "No" : "Yes");
	}
	
}