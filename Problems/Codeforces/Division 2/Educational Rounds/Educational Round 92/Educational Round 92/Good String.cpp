#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		unordered_set<char> st;
		for (auto i : s) {
			st.insert(i);
		}
		int mn_removed = s.length();
		for (auto i : st) {
			for (auto j : st) {
				int removed = 0;
				char curr = i;
				int idx = 0;
				while (idx < s.length()) {
					while (idx < s.length() and s[idx] != curr) {
						idx++;
						removed++;
					}
					curr = (curr == i ? j : i);
					idx++;
				}
				if (i != j) {
					removed += ((s.length() - removed) % 2 == 1);
				}
				mn_removed = min(mn_removed, removed);
			}
		}
		cout << mn_removed << '\n';
	}
}