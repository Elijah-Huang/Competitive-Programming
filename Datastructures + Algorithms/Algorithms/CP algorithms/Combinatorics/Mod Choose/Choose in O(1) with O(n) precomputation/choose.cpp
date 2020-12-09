//POWM IS NEEDED!
long long fac[n+1];
long long inv_fac[n+1];
void choose_setup(int n, int mod, long long fac[], long long inv_fac[]) {
	long long curr = 1;
	for (int i = 1; i <= n; i++) {
		curr = curr * i % mod;
		fac[i] = curr;
	}
	curr = powm(curr, mod - 2, mod);
	for (int i = n; i > 0; i--) {
		inv_fac[i] = curr;
		curr = curr * i % mod;
	}
}
long long choose(int n, int k, int mod) {
	return(fac[n] * inv_fac[n - k] % mod) * inv_fac[k] % mod;
}