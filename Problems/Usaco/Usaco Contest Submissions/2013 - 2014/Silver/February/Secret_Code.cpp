#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
unordered_map<string, int> ways;
string s;
void solve(string s) {
	string a = s; reverse(a.begin(), a.end());
	vector<string> strings = { s,a };
	for (int t = 0; t < 2; t++) {
		string s = strings[t];
		string sr = s;
		if (t == 1) {
			reverse(sr.begin(), sr.end());
		}
		for (int i = (s.length() + 2) / 2; i <= s.length() - 1; i++) {
			string prev_s = s.substr(0, i);
			if (t == 1) {
				reverse(prev_s.begin(), prev_s.end());
			}

			bool is_prefix = true;
			for (int j = i; j < s.length(); j++) {
				if (s[j] != s[j - i]) {
					is_prefix = false;
					break;
				}
			}
			if (is_prefix) {
				if (not(ways.count(prev_s))) {
					solve(prev_s);
				}
				ways[sr] = (ways[sr] + ways[prev_s]) % 2014;
			}

			bool is_suffix = true;
			for (int j = i; j < s.length(); j++) {
				if (s[j] != s[j - (s.length() - i)]) {
					is_suffix = false;
					break;
				}
			}
			if (is_suffix) {
				if (not(ways.count(prev_s))) {
					solve(prev_s);
				}
				ways[sr] = (ways[sr] + ways[prev_s]) % 2014;
			}
		}
	}
	ways[s] = (ways[s] + 1) % 2014;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("scode.in", "r", stdin); freopen("scode.out", "w", stdout);
	cin >> s;
	solve(s);
	cout << ways[s] - 1;
}