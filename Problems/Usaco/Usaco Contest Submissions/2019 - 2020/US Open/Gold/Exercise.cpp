#include<bits/stdc++.h>
using namespace std;

int n, mod, ans = 1;
const int maxn = 1e4 + 1;
int dp[maxn], dp_all_p[maxn], dp_curr_p[maxn];
bool isprime[maxn];

void sieve(int n) {
	fill(isprime, isprime + maxn, 1);
	for (int i = 2; i * i <= n; i++) {
		if (isprime[i]) {
			for (int j = i * i; j <= n; j += i) {
				isprime[j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("exercise.in", "r", stdin); freopen("exercise.out", "w", stdout);

	cin >> n >> mod;

	sieve(n);

	dp[0] = 1;
	for (int p = 2; p <= n; p++) {
		if (isprime[p]) {
			long long curr_pow = p;
			memset(dp_all_p, 0, sizeof(dp_all_p));

			while (curr_pow <= n) {
				memset(dp_curr_p, 0, sizeof(dp_curr_p));

				for (int i = 0; i+curr_pow <= n; i++) {
					dp_curr_p[i + curr_pow] = (curr_pow * dp[i]) % mod;
					dp_all_p[i + curr_pow] = (dp_all_p[i + curr_pow] + dp_curr_p[i + curr_pow]) % mod;
				}

				curr_pow *= p;
			}
			
			for (int i = p; i <= n; i++) {
				dp[i] = (dp[i] + dp_all_p[i]) % mod;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		ans = (ans + dp[i]) % mod;
	}

	cout << ans;
}