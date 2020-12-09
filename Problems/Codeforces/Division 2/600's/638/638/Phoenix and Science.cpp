#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int t, n, last_double, left, num, output[35], total;
	cin >> t;
	while (t--) {
		cin >> n;
		last_double = ilogb((n + 1) / 3);
		num = 1;
		for (int exp = 1; exp <= last_double; exp++) {
			output[exp] = num;
			num = num << 1;
		}
		left = (n - 1) - ((num << 1) - 2);
		if (left > 2 * num) {
			output[last_double + 1] = (left / 2 - num);
			output[last_double + 2] = left % 2;
			total = last_double + 2;
		}
		else {
			output[last_double + 1] = left - num;
			total = last_double + 1;
		}
		cout << total << '\n';
		for (int i = 1; i <= total; i++) {
			cout << output[i] << ' ';
		}
		cout << '\n';

	}
}