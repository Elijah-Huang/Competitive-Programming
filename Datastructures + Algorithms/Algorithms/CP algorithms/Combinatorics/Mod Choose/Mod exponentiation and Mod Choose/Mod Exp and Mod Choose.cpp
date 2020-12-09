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
long long choose(int n, int k, int const& mod) {
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