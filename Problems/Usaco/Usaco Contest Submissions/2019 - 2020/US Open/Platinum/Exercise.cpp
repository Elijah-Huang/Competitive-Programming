//https://codeforces.com/blog/entry/75154?#comment-595528
#include<bits/stdc++.h>
using namespace std;

const int maxn = 7501;
int n, mod;
					
long long fact[maxn], 
part_fact[maxn][maxn], // [a][b] - > a*(a-1)..*b
perms_no_p[maxn], // [i] -> perms without curr prime of length i
num_perms_p[20]; // [i] -> stores n! - perms_no_p[n] for p^i
int spf[maxn];
vector<int> primes;
long long ans = 0;

long long modexp(long long b, int exp) {
	b %= mod;
	long long res = 1;
	while (exp) {
		if (exp & 1) {
			res = (res * b) % mod;
		}

		exp >>= 1;
		b = (b * b) % mod;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> mod;

	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i % (mod - 1);
	}
	for (int i = n; i >= 1; i--) {
		part_fact[i][i] = i;
		for (int j = i - 1; j >= 1; j--) {
			part_fact[i][j] = (part_fact[i][j + 1] * j) % (mod - 1);
		}
	}

	for (int i = 2; i <= n; i++) {
		if (spf[i] == 0) {
			spf[i] = i;
			primes.push_back(i);
		}

		for (int j = 0; j < primes.size() and primes[j] <= spf[i] and primes[j] * i <= n; j++) {
			spf[primes[j] * i] = primes[j];
		}
	}

	for (auto p : primes) {
		// for each power of p <= n, calculate # of perms mod mod-1 that do not have 
		// a cycle divisible by this power of p
		int p_e = p, e = 1;
		for (; p_e <= n; e++, p_e*=p) {
			perms_no_p[1] = fact[n - 1];
			long long psum = fact[n - 1 - 1] * perms_no_p[1] % mod;
			for (int i = 2; i <= n; i++) {
				// transition cumulative sum's implicit denominator to (n-i)!
				psum = psum * (n - i + 1) % (mod - 1);

				// add and subtract unwanted transitions via adding cycle divisible by p^e
				perms_no_p[i] = psum;
				for (int j = p_e; j < i; j += p_e) {
					perms_no_p[i] = (perms_no_p[i] - (fact[n - j - 1] * part_fact[n - (i - j)][n - i + 1] % (mod - 1)) * perms_no_p[i - j]) % (mod - 1);
				}
				//cout << perms_no_p[i] << ' ' << i << ' ' << e << ' ' << p << '\n';
				if (i < n) {
					// add current perms to psum
					psum += fact[n - i - 1] * perms_no_p[i] % (mod - 1);
				}
			}

			cout << perms_no_p[n]%(mod-1) << '\n';
			num_perms_p[e] = (mod-1 + fact[n] - perms_no_p[n]) % (mod-1);
			cout << num_perms_p[e] << '\n';
			//cout << e << ' ' << num_perms_p[e] << ' ' << fact[n] << ' ' << perms_no_p[n] << '\n';
		}

		e--;
		ans += modexp(modexp(p, e), num_perms_p[e]);
		cout << p << ' ' <<  e << ' ' << num_perms_p[n] << ' ' << fact[n] << ' ' << perms_no_p[n] << '\n';
		for (int i = e - 1; i >= 0; i--) {
			ans += modexp(modexp(p, i), mod-1 + num_perms_p[i] - num_perms_p[i + 1]);
		}
		ans %= mod;
		cout << "ans: " << ans << '\n';
	}

	cout << ans;
}