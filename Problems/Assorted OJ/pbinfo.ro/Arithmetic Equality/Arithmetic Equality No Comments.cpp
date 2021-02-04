#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1, mod = 1e9 + 7;
int n, ans = 0;
long long fact[maxn], inv_fact[maxn];

int counts[10];
void solve(int product = 1, int sum = n, int last_digit = 2) {
	if (product > 9 * n) {
		return;
	}

	if (product == sum) {
		long long perms = fact[n];
		for (int digit = 1; digit <= 9; digit++) {
			perms = (perms * inv_fact[counts[digit]]) % mod;
		}

		ans = (ans + perms) % mod;
	}

	if (counts[1] == 0) {
		return;
	}

	for (int next_digit = last_digit; next_digit <= 9; next_digit++) {
		counts[1] -= 1;
		counts[next_digit] += 1;
		solve(product * next_digit, sum - 1 + next_digit, next_digit);
		counts[1] += 1;
		counts[next_digit] -= 1;
	}
}

int mod_exp(long long base, int exp) {
	long long res = 1;

	while (exp) {
		if (exp & 1) {
			res = (res * base) % mod;
		}

		exp >>= 1;
		base = (base * base) % mod;
	}

	return res;
}

int main() {
	cin >> n;

	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}

	inv_fact[n] = mod_exp(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; i--) {
		inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
	}

	counts[1] = n;
	solve();

	cout << ans;
}