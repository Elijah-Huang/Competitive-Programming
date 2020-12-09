/*
ID: elijahj1
TASK: hidden
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
const int mod = 1e9 + 7;
const int p = 31;
vector<long long> pinv(maxn);
vector<long long> pnorm(maxn);

long long minv(long long a, long long m) {
	if (a == 1) return 1;
	return m - minv(m % a, a) * m / a;
}

long long powm(long long b, long long exp) {
	b %= mod;
	long long res = 1;
	while (exp) {
		if (exp % 2 == 1) {
			res = (res * b) % mod;
		}
		exp >>= 1;
		b = (b * b) % mod;
	}
	return res;
}

void precomute_p() {
	pinv[maxn - 1] = minv(powm(p, maxn - 1), mod);
	for (int i = maxn - 2; i >= 0; i--) {
		pinv[i] = (pinv[i + 1] * p) % mod;
	}
	pnorm[0] = 1;
	for (int i = 1; i < maxn; i++) {
		pnorm[i] = (pnorm[i - 1] * p) % mod;
	}
}

vector<int> comp_prefix_hash(string& s) {
	vector<int> prefix_hash(s.length());
	prefix_hash[0] = (s[0] - 'a' + 1);
	for (int i = 1; i < s.length(); i++) {
		prefix_hash[i] = (prefix_hash[i - 1] + (s[i] - 'a' + 1) * pnorm[i]) % mod;
	}
	return prefix_hash;
}

int string_hash(string& s) {
	int hash = 0;
	for (int i = 0; i < s.length(); i++) {
		hash = (hash + (s[i] - 'a' + 1) * pnorm[i]) % mod;
	}
	return hash;
}

int substr_hash(vector<int>& prefix_hash, int l, int r) {
	return l != 0 ? ((prefix_hash[r] - prefix_hash[l - 1] + mod) * pinv[l]) % mod : prefix_hash[r];
}

int main() {
	precomute_p();
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("hidden.in","r",stdin); freopen("hidden.out","w",stdout);
	int n; cin >> n;
	string s, addon;
	while (cin >> addon) {
		s += addon;
	}
	s += s;

	vector<int> s_hash = comp_prefix_hash(s);

	int best = 0;
	for (int i = 1; i < n; i++) { 
		int l = 0, r = n;
		while (l != r) {
			int m = (l + r + 1) / 2;
			if (m == 0 or substr_hash(s_hash, best, best + m - 1) == substr_hash(s_hash, i, i + m - 1)) {
				l = m; 
			}
			else {
				r = m - 1;
			}
		}
		best = (l == n or s[best + l] < s[i + l] ? best : i);
	}
	
	cout << best << '\n';
}