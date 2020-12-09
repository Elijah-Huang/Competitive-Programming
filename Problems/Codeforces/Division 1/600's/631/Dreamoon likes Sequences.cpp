#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int a = ((1<<30) - 1) << 1;
	int b = 1 << 30;
	cout << a << '\n';
	cout << b << '\n';
	cout << a * b;
	int t, d, m; 
	cin >> t;
	while (t--) {
		cin >> d >> m;
		long long total = 1;
		int used = 1;
		while (d > used) {
			d -= used;
			total = (total * (used + 1)) % m;
			used *= 2;
		}
		total = (total * (d + 1)) % m;
		total = (total + m - 1) % m;
		cout << total << '\n';
	}
}