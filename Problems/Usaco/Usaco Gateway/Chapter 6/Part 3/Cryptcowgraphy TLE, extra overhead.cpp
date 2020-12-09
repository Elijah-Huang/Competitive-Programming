/*
ID: elijahj1
TASK: cryptcow
LANG: C++14
*/

#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;
const int maxn = 100;
const int mod = 1e9 + 7;
const int p = 31;
vector<long long> pinv(maxn);
vector<long long> pnorm(maxn);
char originala[48] = "Begin the Escape execution at the Break of Dawn";
string original = "Begin the Escape execution at the Break of Dawn";
unordered_set<int> substrings = { 0 }, visited;

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

int string_hash(char* s) {
	long long hash = 0;
	for (int i = 0; i < strlen(s); i++) {
		hash = hash + (s[i] - 'a' + 1) * pnorm[i];
	}
	return hash % mod;
}

int string_hash(string s) {
	long long hash = 0;
	for (int i = 0; i < s.length(); i++) {
		hash = hash + (s[i] - 'a' + 1) * pnorm[i];
	}
	return hash % mod;
}


bool solve(char* s) {
	string s2 = s;
	int hash = string_hash(s);
	if (visited.count(hash)) {
		return false;
	}
	visited.insert(hash);
	if (!strcmp(s,originala)) {
		return true;
	}
	
	vector<int> all_locs = { -1 };
	vector<int> c_locs, o_locs, w_locs;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == 'C') {
			c_locs.push_back(i);
			all_locs.push_back(i);
		}
		else if (s[i] == 'O') {
			o_locs.push_back(i);
			all_locs.push_back(i);
		}
		else if (s[i] == 'W') {
			w_locs.push_back(i);
			all_locs.push_back(i);
		}
	}
	all_locs.push_back(strlen(s));

	if (w_locs[0] < c_locs[0] or o_locs[0] < c_locs[0] or c_locs.back() > w_locs.back() or o_locs.back() > w_locs.back()) {
		return false;
	}
	for (int i = 0; i < all_locs.size() - 1; i++) {
		if (!substrings.count(string_hash(s2.substr(all_locs[i] + 1, all_locs[i + 1] - all_locs[i] - 1)))) {
			return false;
		}
	}

	c_locs.clear(), o_locs.clear(), w_locs.clear(), all_locs.clear(), s2.clear();

	char s1[72];
	for (int j = 0; j < strlen(s); j++) {
		if (s[j] == 'O') {
			for (int i = 0; i < j; i++) {
				if (s[i] == 'C') {
					for (int k = strlen(s) - 1; k > j; k--) {
						if (s[k] == 'W') {
							s1[0] = '\0';
							strncat(s1, s, i);
							strncat(s1, s + j + 1, k - j - 1);
							strncat(s1, s + i + 1, j - i - 1);
							strncat(s1, s + k + 1, strlen(s) - k - 1);
							if (solve(s1)) {
								return true;
							}
						}
					}
				}
			}
		}
	}

	/*
	int i2 = 0;
	int k2 = 0;
	for (int j = 0; j < o_locs.size(); j++) {
		while (i2 < c_locs.size() and c_locs[i2] < o_locs[j]) {
			i2++;
		}
		i2--;
		while (k2 < w_locs.size() and w_locs[k2] < o_locs[j]) {
			k2++;
		}
		if (c_locs[i2] > o_locs[j]) {
			continue;
		}
		if (w_locs[k2] < o_locs[j]) {
			break;
		}
		for (int i = i2; i >= 0; i--) {
			for (int k = k2; k < w_locs.size(); k++) {
				if (solve(s.substr(0, c_locs[i]) + s.substr(o_locs[j] + 1, w_locs[k] - o_locs[j] - 1)
					+ s.substr(c_locs[i] + 1, o_locs[j] - c_locs[i] - 1) + s.substr(w_locs[k] + 1, s.length() - w_locs[k] - 1))) {
					return true;
				}
			}
		}
	}
	*/
	/*
	int j2 = 0;
	for (int i = 0; i < o_locs.size(); i++) {
		while (j2 < o_locs.size() and c_locs[i] > o_locs[j2]) {
			j2++;
		}
		if (j2 == o_locs.size()) {
			continue;
		}
		int k2 = 0;
		for (int j = j2; j < o_locs.size(); j++) {
			while (k2 < w_locs.size() and o_locs[j] > w_locs[k2]) {
				k2++;
			}
			if (k2 == w_locs.size()) {
				continue;
			}
			for (int k = k2; k < w_locs.size(); k++) {
				if (solve(s.substr(0, c_locs[i]) + s.substr(o_locs[j] + 1, w_locs[k] - o_locs[j] - 1)
					+ s.substr(c_locs[i] + 1, o_locs[j] - c_locs[i] - 1) + s.substr(w_locs[k] + 1, s.length() - w_locs[k] - 1))) {
					return true;
				}
			}
		}
	}
	*/
	return false;
}

int main() {
	precompute_p();
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("cryptcow.in", "r", stdin); freopen("cryptcow.out", "w", stdout);
	string s;
	char s2[76]; 
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		s2[i] = s[i];
	}
	s2[s.length()] = '\0';

	for (int i = 0; i < original.length(); i++) {
		for (int j = i; j < original.length(); j++) {
			substrings.insert(string_hash(original.substr(i, j - i + 1)));
		}
	}

	vector<int> orig_counts(128), counts(128);
	bool fail = false;
	for (auto c: original) {
		orig_counts[c]++;
	}
	for (auto c : s) {
		counts[c]++;
	}
	if (counts['C'] != counts['O'] or counts['C'] != counts['W']) {
		fail = true;
	}
	counts['C'] = counts['O'] = counts['W'] = 0;
	if (orig_counts != counts) {
		fail = true;
	}

	if (fail or !solve(s2)) {
		cout << 0 << ' ' << 0 << '\n';
	}
	else {
		cout << 1 << ' ' << (s.length() - 47)/3 << '\n';
	}
}