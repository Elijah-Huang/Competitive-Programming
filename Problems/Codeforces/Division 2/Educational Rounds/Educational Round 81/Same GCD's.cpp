#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long t, a, m;
	cin >> t;
	while (t--) {
		cin >> a >> m;
		long long d = gcd(a, m);
		vector<long long> primes;
		long long am = m / d;
		long long am2 = am;
		for (long long i = 2; i * i <= am2; i++) {
			if (am2 % i == 0) {
				while (am2 % i == 0) {
					am2 /= i;
				}
				primes.push_back(i);
			}
		}
		if (am2 > 1) {
			primes.push_back(am2);
		}
		for (auto p : primes) {
			am /= p;
			am *= (p - 1);
		}
		cout << am << '\n';
	}
}