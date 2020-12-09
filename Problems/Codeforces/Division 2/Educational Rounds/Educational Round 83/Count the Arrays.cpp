#include <bits/stdc++.h>
using namespace std;
long long powm(long long base, int exp, int const &mod) {
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
long long choose(int n, int k, int const &mod) {
	long long ans = 1;
	k = min(n - k, k);
	for (int i = n; i > n - k; i--) {
		ans = (ans * i) % mod;
	}
	long long denom = 1;
	for (int i = 1; i <= k; i++) {
		denom = (denom * i) % mod;
	}
	return (ans * powm(denom, mod - 2, mod)) % mod;
}
int main() {
	int a, b;
	int n, m;
	int mod = 998244353;
	cin >> n >> m; 
	if (n == 2) {
		cout << 0;
	}
	else {
		cout << (((choose(m, n - 1, mod) * (n - 2)) % mod) * powm(2, n - 3, mod)) % mod;
	}
}