#include <bits/stdc++.h>
using namespace std;
long long powm(long long base, long long exp, int const& mod) {
	base %= mod;
	long long ans = 1;
	while (exp) {
		if (exp % 2 == 1) {
			ans = (ans * base) % mod;
		}
		exp = exp >> 1;
		base = (base * base) % mod;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	const int mod = 1e9 + 7;
	int x;
	long long n;
	cin >> x >> n;
	vector<int> primes;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			while (x % i == 0) {
				x /= i;
			}
			primes.push_back(i);
		}
	}
	if (x > 1) {
		primes.push_back(x);
	}
	long long ans = 1;
	for (auto prime : primes) {
		long long power = 1;
		while (power <= n / prime) {
			power *= prime;
			long long appearances = n / power;
			if (power <= n / prime) {
				appearances -= n / (power * prime);
			}
			ans = (ans * powm(power, appearances, mod)) % mod;
		}
	}
	cout << ans;
}