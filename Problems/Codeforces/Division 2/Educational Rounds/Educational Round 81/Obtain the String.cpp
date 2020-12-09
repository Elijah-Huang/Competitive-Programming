#include <bits/stdc++.h>
using namespace std;
int idx(char val) {
	return (int(val) - int('a'));
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		string t;
		cin >> s;
		cin >> t;
		int needed = 0;
		bool possible = true;
		vector<vector<int>> locations(26);
		for (int i = 0; i < s.length(); i++) {
			locations[idx(s[i])].push_back(i);
		}
		for (int i = 0; i < t.length(); i++){
			if (locations[idx(t[i])].size() == 0) {
				possible = false;
				break;
			}
		}
		if (possible) {
			int i = 0;
			while (i < t.length()) {
				needed++;
				int next = idx(t[i]);
				int last = locations[next][0];
				i++;
				while (i < t.length()) {
					next = idx(t[i]);
					vector<int>::iterator last2 = upper_bound(locations[next].begin(), locations[next].end(), last);
					if (last2 == locations[next].end()) break;
					else i++; last = *last2;
				}
			}
		}
		cout << (possible ? needed : -1) << '\n';
		
	}
}