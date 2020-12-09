#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
const int mod = 1e9 + 7;
const int p = 31;
vector<long long> pinv(maxn);
vector<long long> pnorm(maxn);

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

void precompute_p() {
	pinv[maxn - 1] = powm(powm(p, maxn - 1), mod - 2);
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
		hash += (s[i] - 'a' + 1) * pnorm[i];
	}
	return hash % mod;
}

int substr_hash(vector<int>& prefix_hash, int l, int r) {
	return l != 0 ? ((prefix_hash[r] - prefix_hash[l - 1] + mod) * pinv[l]) % mod : prefix_hash[r];
}

int main() {
	precompute_p();
}