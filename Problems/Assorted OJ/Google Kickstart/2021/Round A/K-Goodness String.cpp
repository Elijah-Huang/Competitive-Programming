#include<bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		string s; cin >> s;
		int diff = 0;
		for (int i = 0; i < n/2; i++) {
			diff += s[i] != s[n - 1 - i];
		}

		cout << "Case #" << i << ": " << abs(diff - k) << '\n';
	}
}