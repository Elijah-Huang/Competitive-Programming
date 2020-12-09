long long powm(long long base, long long exp, const int& mod) {
	base %= mod;
	long long ans = 1;
	while (exp) {
		if (exp & 1) {
			ans = (ans * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	}
	return ans;
}