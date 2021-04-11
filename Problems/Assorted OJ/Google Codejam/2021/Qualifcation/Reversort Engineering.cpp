// O(T*N^2)
#include<bits/stdc++.h>
using namespace std;

int t, n, c;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cas = 1; cas <= t; cas++) {
		cin >> n >> c;

		if (n - 1 <= c and c <= (n - 1) * (n + 2) / 2) {
			vector<int> lst = { n };
			for (int i = n - 1; i >= 1; i--) {
				int cost = min(c - (i - 1), (int)lst.size() + 1);
				c -= cost;
				lst.insert(lst.begin() + cost - 1, i);
				reverse(lst.begin(), lst.begin() + cost - 1);
			}

			cout << "Case #" << cas << ": ";
			for (auto i : lst) {
				cout << i << ' ';
			}
			cout << '\n';
		}
		else {
			cout << "Case #" << cas << ": " << "IMPOSSIBLE\n";
		}
	}
}