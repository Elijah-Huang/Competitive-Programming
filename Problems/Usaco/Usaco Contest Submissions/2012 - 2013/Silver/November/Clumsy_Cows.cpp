#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("clumsy.in", "r", stdin); freopen("clumsy.out", "w", stdout);
	string s;
	cin >> s;
	int needed = s.length() / 2;
	int close = 0;
	int open = 0;
	int flipped = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			if (close == needed) {
				open++;
				flipped++;
			}
			else {
				close++;
			}
		}
		else {
			if (close == open) {
				close++;
				flipped++;
			}
			else {
				open++;
			}
		}
	}
	cout << flipped;
}