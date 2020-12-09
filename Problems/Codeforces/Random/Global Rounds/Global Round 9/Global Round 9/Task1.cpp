#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin >> n;
	cin >> s;
	string output(n, '0');
	bool fail = false;
	for (int i = 0; i < n; i++) {
		if (fail) break;
		for (int j = 0; j < i; j++) {
			if (fail) break;
			if (int(s[j]) > int(s[i])) {
				if (output[j] == '1') {
					fail = true;
					break;
				}
				else {
					output[i] = '1';
				}
			}
		}
	}
	if (fail) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		cout << output << '\n';
	}
}