#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int t, x, y, n;
	cin >> t;
	while (t--) {
		cin >> x >> y >> n;
		if (n % x < y) {
			cout << (n - x + y - n%x) << '\n';
		}
		else {
			cout << (n - (n % x -y)) << '\n';
		}
	}
}