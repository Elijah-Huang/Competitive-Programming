#include<bits/stdc++.h>
using namespace std;

const int n = 1e6;
const int mod = 1e9 + 7;
const int p = 31;
vector<long long> pinv(n);
vector<long long> pnorm(n);

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
	pinv[n - 1] = powm(powm(p, n - 1), mod - 2);
	for (int i = n - 2; i >= 0; i--) {
		pinv[i] = (pinv[i + 1] * p) % mod;
	}
	pnorm[0] = 1;
	for (int i = 1; i < n; i++) {
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
	freopen("censor.in", "r", stdin); freopen("censor.out", "w", stdout);
	precomute_p();
	string s, t;
	cin >> s >> t;
	int n2 = s.length(), m = t.length();
	int match = string_hash(t);
	vector<int> prefix_hash(n2);
	string res;	

	for (int i = 0; i < n2; i++) {
		res.push_back(s[i]);
		prefix_hash[res.size() - 1] = res.size() - 1 ? (prefix_hash[res.size() - 2] + (s[i] - 'a' + 1) * pnorm[res.size() - 1]) % mod 
			: (s[i] - 'a' + 1) * pnorm[res.size() - 1] % mod;
		if (res.size() >= m and substr_hash(prefix_hash, res.size() - m, res.size() - 1) == match) {
			res.resize(res.size() - m);
		}
	}

	cout << res << '\n';
}