#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, c = 0;
	cin >> t;
	while (t--) {
		c++;
		int n, x; cin >> n >> x;
		vector<pair<int,int>> amts(n);
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			amts[i] = { (a + x - 1) / x,i };
		}

		sort(amts.begin(), amts.end());
		cout << "Case #" << c << ": ";
		for (int i = 0; i < n; i++) {
			cout << amts[i].second + 1 << (i == n - 1 ? '\n' : ' ');
		}
	}
}