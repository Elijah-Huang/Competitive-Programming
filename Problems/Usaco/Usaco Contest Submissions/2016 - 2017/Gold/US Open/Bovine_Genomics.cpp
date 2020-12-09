#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

const int maxn = 500;
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

void precomute_p() {
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
		hash = (hash + (s[i] - 'a' + 1) * pnorm[i]) % mod;
	}
	return hash;
}

int substr_hash(vector<int>& prefix_hash, int l, int r) {
	return l != 0 ? ((prefix_hash[r] - prefix_hash[l - 1] + mod) * pinv[l]) % mod : prefix_hash[r];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cownomics.in", "r", stdin); freopen("cownomics.out", "w", stdout);
	precomute_p();
	int n, m; cin >> n >> m;
	vector<vector<int>> spotty, plain;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		spotty.push_back(comp_prefix_hash(s));
	}
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		plain.push_back(comp_prefix_hash(s));
	}

	bool worked;
	int l = 1, r = m;
	while (l != r) {
		int k = (l + r) / 2;
		for (int i = 0; i <= m - k; i++) {
			unordered_set<int> spotty_hash;
			worked = true;
			for (int j = 0; j < n; j++) {
				spotty_hash.insert(substr_hash(spotty[j], i, i + k - 1));
			}
			for (int j = 0; j < n; j++) {
				if (spotty_hash.count(substr_hash(plain[j], i, i + k - 1))) {
					worked = false;
					break;
				}
			}
			if (worked) {
				break;
			}
		}
		if (worked) {
			r = k;
		}
		else {
			l = k + 1;
		}
	}

	cout << l;
	/*
	bool worked;
	for (int k = 1; k <= m; k++) {
		for (int i = 0; i <= m - k; i++) {
			unordered_set<int> spotty_hash;
			worked = true;
			for (int j = 0; j < n; j++) {
				spotty_hash.insert(substr_hash(spotty[j], i, i + k - 1));
			}
			for (int j = 0; j < n; j++) {
				if (spotty_hash.count(substr_hash(plain[j], i, i + k - 1))) {
					worked = false;
					break;
				}
			}
			if (worked) {
				break;
			}
		}
		if (worked) {
			cout << k;
			return 0;
		}
	}
	*/
}