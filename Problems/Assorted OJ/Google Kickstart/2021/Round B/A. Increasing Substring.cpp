#include<bits/stdc++.h>
using namespace std;

int t;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> t;

	for (int cse = 1; cse <= t; cse++) {
		int n; cin >> n;
		string s; cin >> s;
		vector<int> ans(n);
		ans[0] = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] > s[i - 1]) {
				ans[i] = ans[i - 1] + 1;
			}
			else {
				ans[i] = 1;
			}
		}
		cout << "Case #" << cse << ": ";
		for (auto i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}