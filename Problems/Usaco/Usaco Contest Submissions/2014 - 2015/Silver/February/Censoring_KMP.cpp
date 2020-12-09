#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("censor.in", "r", stdin); freopen("censor.out", "w", stdout);
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	vector<int> pf(m);
	vector<int> prefix(n);
	string res;

	for (int i = 1; i < m; i++) {
		int j = pf[i - 1];
		while (j > 0 and t[i] != t[j]) {
			j = pf[j - 1];
		}
		pf[i] = (t[i] == t[j]) ? j + 1 : 0;
	}
	
	int j;
	for (int i = 0; i < n; i++) {
		j = res.size() ? prefix[res.size() - 1] : 0;
		while (j > 0 and s[i] != t[j]) {
			j = pf[j - 1];
		}
		j = (s[i] == t[j]) ? j + 1 : 0;
		if (j == m) {
			res.resize(res.size() - (m - 1));
		}
		else {
			res.push_back(s[i]);
			prefix[res.size() - 1] = j;
		}
	}

	cout << res;
}