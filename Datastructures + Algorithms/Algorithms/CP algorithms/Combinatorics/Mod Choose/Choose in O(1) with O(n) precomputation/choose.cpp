#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5;
long long fac[maxn+1];
long long inv_fac[maxn+1];

long long powm(long long b, long long e) {
	b %= mod;

	long long ans = 1;

	while (e) {
		if (e & 1) {
			ans = (ans * b) % mod;
		}

		e >>= 1;
		b = (b * b) % mod;
	}

	return ans;
}

void choose_setup() {
	fac[0] = 1;
	for (int i = 1; i <= maxn; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}

	inv_fac[maxn] = powm(fac[maxn], mod - 2);
	for (int i = maxn - 1; i >= 0; i--) {
		inv_fac[i] = inv_fac[i + 1] * (i + 1) % mod;
	}
}

long long choose(int n, int k) {
	return (fac[n] * inv_fac[n - k] % mod) * inv_fac[k] % mod;
}