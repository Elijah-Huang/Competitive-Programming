/*
ID: elijahj1
TASK: calfflac
LANG: C++14
*/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e4+ 1;
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

int substr_hash(vector<int>& prefix_hash, int l, int r) {
	return ((prefix_hash[r] - prefix_hash[l - 1] + mod) * pinv[l]) % mod;
}

int main() {
	precompute_p();
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("calfflac.in", "r", stdin); freopen("calfflac.out", "w", stdout);
	string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string original, converted, a;
	vector<int> convert_back(2e4);
	int best_length = 1, best_idx = -1;
	while (getline(cin,a)) {
		original.append(a + '\n');
	}

	for (int i = 0; i < original.length(); i++) {
		if (find(letters.begin(), letters.end(), original[i]) != letters.end()) {
			convert_back[converted.length()] = i;
			converted.push_back(tolower(original[i]));
			if (best_idx == -1) {
				best_idx = i;
			}
		}
	}

	if (best_idx == -1) {
		cout << 0 << '\n';
		return 0;
	}

	vector<int> phash = { comp_prefix_hash(converted) };
	reverse(converted.begin(), converted.end());
	vector<int> rphash = { comp_prefix_hash(converted) };
	
	int s_len = converted.length();	
	for (int start = 0; start < s_len; start++) {
		int mn = min(s_len, start + 1999);
		int curr_best = 1;
		for (int end = start + 1; end < mn; end++) {
			int len = (end - start + 1);
			curr_best = max(curr_best, len*(substr_hash(phash, start, start + len / 2 - 1) == substr_hash(rphash, s_len - 1 - end, s_len - 1 - (end - (len / 2 - 1)))));
		}
		if (curr_best > best_length) {
			best_length = curr_best;
			best_idx = start;
		}
	}
	
	cout << best_length << '\n';
	cout << original.substr(convert_back[best_idx], convert_back[best_idx + best_length - 1] - convert_back[best_idx] + 1) << '\n';
}