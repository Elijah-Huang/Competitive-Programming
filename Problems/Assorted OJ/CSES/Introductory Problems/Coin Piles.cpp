#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		if (b > 2 * a) {
			cout << "NO\n";
		}
		else {
			int equal_val = a - (b - a);
			if (equal_val % 3 != 0) {
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
			}
		}
	}
}