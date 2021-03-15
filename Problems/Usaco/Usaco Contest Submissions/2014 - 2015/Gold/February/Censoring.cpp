// O(n^3/2 * log(n))
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
string s, final;
set<int> t_lengths;
set<int> t_hashes[maxn];

// string hashing
const int mod = 1e9 + 7;
const int p = 29;

long long binexp(long long b, long long e) {
	b %= mod;
	long long res = 1;
	while (e) {
		if (e & 1) {
			res = (res * b) % mod;
		}

		e >>= 1;
		b = (b * b) % mod;
	}

	return res;
}

long long po[maxn], inv[maxn];

void precompute() {
	po[0] = 1;
	for (int i = 1; i < maxn; i++) {
		po[i] = po[i - 1] * p % mod;
	}

	inv[maxn - 1] = binexp(binexp(p, maxn - 1), mod - 2);
	for (int i = maxn - 2; i >= 0; i--) {
		inv[i] = inv[i + 1] * p % mod;
	}
}

long long final_hash[maxn];

int suffix_hash(int len) {
	return (final_hash[final.length()-1] + mod - (int(final.length())-1 - len >= 0 ? final_hash[final.length()-1 - len] : 0)) * inv[final.length()-1 - len + 1] % mod;
}

int val(char c, int e) {
	return (c - 'a' + 1) * po[e] % mod;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("censor.in", "r", stdin); freopen("censor.out", "w", stdout);

	precompute();
	
	cin >> s;
	int b; cin >> b;
	while (b--) {
		string ta; cin >> ta;
		int curr_hash = 0;
		for (int i = 0; i < ta.length(); i++) {
			curr_hash = (curr_hash + val(ta[i], i)) % mod;
		}

		t_hashes[ta.length()].insert(curr_hash);
		t_lengths.insert(ta.length());
	}

	for (int i = 0; i < s.length(); i++) {
		final.push_back(s[i]);
		final_hash[final.length() - 1] = (val(final.back(), final.length() - 1) + (final.length() > 1 ? final_hash[final.length() - 2] : 0)) % mod;
	
		for (auto len : t_lengths) {
			if (len > final.length()) {
				break;
			}
			else {
				if (t_hashes[len].count(suffix_hash(len))) {
					// suffix of length len matches with one of the strings in t
					final.resize(final.length() - len);
					break;
				}
			}
		}
	}

	cout << final << '\n';
}