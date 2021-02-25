#include<bits/stdc++.h>
using namespace std;

int q;
long long n, x, y;

int least_sig_bit(long long a) {
	int i = 0;
	while ((a >> i) ^ 1) {
		i++;
	}
	return i;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> q;
	while (q--) {
		cin >> n >> x >> y;
		//cout << (1ll << (min(least_sig_bit(x), least_sig_bit(y)))) << '\n';

		int p = 0;
		while ((1ll << (p + 1)) < n) {
			p++;
		}
		for (; p >= 0; p--) {
			if ((1ll<<p) < x) {
				x -= (1ll << p);
			}
			else if ((1ll<<p) < y) {
				y -= (1ll << p);
			}
			else {
				break;
			}
		}

		cout << (1ll << p) << '\n';
	}
}