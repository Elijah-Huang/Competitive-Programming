#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n; cin >> n;
	while (true) {
		cout << n << ' ';
		if (n == 1) {
			break;
		}
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = 3 * n + 1;
		}
	}
}