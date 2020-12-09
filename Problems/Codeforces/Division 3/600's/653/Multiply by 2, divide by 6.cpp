#include<bits/stdc++.h>
using namespace std;
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int threes = 0;
		int twos = 0;
		while (n % 2 == 0) {
			twos++;
			n /= 2;
		}
		while (n % 3 == 0) {
			threes++;
			n /= 3;
		}
		if (n != 1 or twos > threes) {
			cout << -1 << '\n';
		}
		else {
			cout << 2 * threes - twos << '\n';
		}
	}
}