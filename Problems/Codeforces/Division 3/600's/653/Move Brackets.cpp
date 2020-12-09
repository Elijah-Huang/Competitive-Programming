#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int t, n, good;
	cin >> t;
	while (t--) {
		cin >> n;
		string s;
		cin >> s;
		bool had_sequence = true;
		while (had_sequence) {
			had_sequence = false;
			for (int i = 0; i < n - 1; i++) {
				if (s[i] == '(' and s[i + 1] == ')') {
					n -= 2;
					had_sequence = true;
					s.erase(i, 2);
					break;
				}
			}
		}
		cout << n/2 << '\n';
	}
}