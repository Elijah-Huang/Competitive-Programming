#include<bits/stdc++.h>
using namespace std;

int n;
string order = "WNESWN";
map<char, int> loc = { {'N',1},{'E',2},{'S',3},{'W',4} };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		s += s[0];

		int turn = 0;
		for (int i = 0; i < s.length() - 1; i++) {
			int locc = loc[s[i]];

			if (s[i + 1] == order[locc - 1]) {
				// left turn
				turn--;
			}
			else if (s[i + 1] == order[locc + 1]) {
				// right turn
				turn++;
			}
		}

		if (turn == -4) {
			cout << "CCW\n";
		}
		else {
			cout << "CW\n";
		}
	}
}