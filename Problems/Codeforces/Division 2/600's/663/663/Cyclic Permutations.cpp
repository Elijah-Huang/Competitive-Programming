#include<bits/stdc++.h>
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


void choose_setup(int n, int mod, vector<long long>& fac, vector<long long>& inv_fac) {
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

long long choose(int n, int k, int mod, vector<long long>& fac, vector<long long>& inv_fac) {
	return (fac[n] * inv_fac[n - k] % mod) * inv_fac[k] % mod;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	const int mod = 1e9 + 7;
	vector<long long> fac(n + 1,1);
	vector<long long> inv_fac(n + 1,1);
	choose_setup(n, mod, fac, inv_fac);
	long long total = 1;
	for (int i = 2; i <= n; i++) {
		total = (total * i) % mod;
	}
	for (int i = 0; i < n; i++) {
		total = (mod + total - choose(n - 1, i, mod, fac, inv_fac)) % mod;
	}
	//cout << choose(n - 1, 0, mod, fac, inv_fac) << '\n';
	cout << total;

}