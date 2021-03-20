#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	int cases = 1;

	while (t--) {
		int n, b; cin >> n >> b;
		vector<int> a(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sort(a.begin(), a.end());

		int tot = 0;
		int i = 0;
		while (i < n and tot + a[i] <= b) {
			tot += a[i];
			i += 1;
		}

		cout << "Case #" << cases << ": " << i << '\n';
		cases += 1;
	}
}