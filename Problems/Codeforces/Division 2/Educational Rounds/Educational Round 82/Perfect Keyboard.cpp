#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		unordered_map<char, unordered_set<char>> m;
		for (int i = 0; i < s.length() - 1; i++) {
			m[s[i]].insert(s[i + 1]);
			m[s[i + 1]].insert(s[i]);
		}
		bool fail = false;
		for (auto i : m) {
			if (i.second.size() > 2) {
				fail = true; 
				break;
			}
		}
		string leaves;
		int num_leaves = 0;
		if (not fail) {
			for (auto i : m) {
				if (i.second.size() == 1) {
					leaves += i.first;
					num_leaves++;
				}
			}
		}
		if (num_leaves != 2) {
			fail = true;
		}
		if (fail) {
			if (m.size() == 0) {
				cout << "YES\n";
				for (char c = 'a'; c <= 'z'; c++) {
					cout << c;
				}
				cout << '\n';
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			string output(1,leaves[0]);
			unordered_set<char> need;
			for (char i = 'a'; i <= 'z'; i++) {
				need.insert(i);
			}
			need.erase(leaves[0]);
			need.erase(*m[output[output.size() - 1]].begin());
			output += *m[output[output.size() - 1]].begin();
			while (output[output.size() - 1] != leaves[1]){
				for (char i : m[output[output.size() - 1]]) {
					if (i != output[output.size() - 2]) {
						output.push_back(i);
						need.erase(i);
						break;
					}
				}
			}
			for (char i : need) {
				output.push_back(i);
			}
			cout << "YES" << '\n';
			cout << output << '\n';
		}
	}
}