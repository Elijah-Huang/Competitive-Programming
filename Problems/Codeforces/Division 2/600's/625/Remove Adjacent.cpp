#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n; 
	cin >> s;
	bool found = true;
	int idx;
	int mx;
	int removed = 0;
	if (n == 1) {
		cout << 0;
	}
	else {
		while (found) {
			found = false;
			mx = 0;
			idx = 0;
			for (int i = 0; i < s.length(); i++) {
				if (i == 0) {
					if (int(s[i]) == 1 + int(s[i + 1])) {
						found = true;
						if (mx < int(s[i])) {
							idx = i;
							mx = int(s[i]);
						}
					}
				}
				else if (i == s.length() - 1) {
					if (int(s[i]) == 1 + int(s[i - 1])) {
						found = true;
						if (mx < int(s[i])) {
							idx = i;
							mx = int(s[i]);
						}
					}
				}
				else if (int(s[i]) == 1 + int(s[i - 1]) or int(s[i]) == 1 + int(s[i + 1])) {
					found = true;
					if (mx < int(s[i])) {
						idx = i;
						mx = int(s[i]);
					}
				}
			}
			if (found) {
				s.erase(s.begin() + idx);
				removed++;
			}
		}
		cout << removed;
	}
}