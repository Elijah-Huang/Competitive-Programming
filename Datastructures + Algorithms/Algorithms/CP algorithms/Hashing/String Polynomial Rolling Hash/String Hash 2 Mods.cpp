#include<bits/stdc++.h>
#include<array>
using namespace std;

const int maxn = 2e4 + 1;
array<const int, 2> mod = { int(1e9 + 7), int(9e8 + 11) };
const int p = 31;
vector<vector<long long>> pinv;
vector<vector<long long>> pnorm;

long long powm(long long b, long long exp, int type) {
	b %= mod[type];
	long long res = 1;
	while (exp) {
		if (exp % 2 == 1) {
			res = (res * b) % mod[type];
		}
		exp >>= 1;
		b = (b * b) % mod[type];
	}
	return res;
}

void precompute_p(int type) {
	pinv.push_back(vector<long long>(maxn));
	pnorm.push_back(vector<long long>(maxn));
	pinv[type][maxn - 1] = powm(powm(p, maxn - 1, type), mod[type] - 2, type);
	for (int i = maxn - 2; i >= 0; i--) {
		pinv[type][i] = (pinv[type][i + 1] * p) % mod[type];
	}
	pnorm[type][0] = 1;
	for (int i = 1; i < maxn; i++) {
		pnorm[type][i] = (pnorm[type][i - 1] * p) % mod[type];
	}
}

vector<int> comp_prefix_hash(string& s, int type) {
	vector<int> prefix_hash(s.length());
	prefix_hash[0] = (s[0] - 'a' + 1);
	for (int i = 1; i < s.length(); i++) {
		prefix_hash[i] = (prefix_hash[i - 1] + (s[i] - 'a' + 1) * pnorm[type][i]) % mod[type];
	}
	return prefix_hash;
}

int string_hash(string& s, int type) {
	int hash = 0;
	for (int i = 0; i < s.length(); i++) {
		hash = (hash + (s[i] - 'a' + 1) * pnorm[type][i]) % mod[type];
	}
	return hash;
}

int substr_hash(vector<int>& prefix_hash, int l, int r, int type) {
	return l != 0 ? ((prefix_hash[r] - prefix_hash[l - 1] + mod[type]) * pinv[type][l]) % mod[type] : prefix_hash[r];
}

int main() {
	precompute_p(0); precompute_p(1);
}