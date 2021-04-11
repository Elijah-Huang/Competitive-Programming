#include<bits/stdc++.h>
using namespace std;

int t, x, y;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cas = 1; cas <= t; cas++) {
		// cj, jc
		cin >> x >> y >> s;

		int cost = 0;
		char lst = 'a';
		for (auto c : s) {
			if (x + y < 0) {
				// tc 3

				if (c == '?') {
					if (lst == 'a') {
						if (x < y) {
							lst = 'C';
						}
						else {
							lst = 'J';
						}
					}
					if (lst == 'C') {
						cost += x;
						lst = 'J';
					}
					else if (lst == 'J') {
						cost += y;
						lst = 'C';
					}
				}
				else {
					if (lst == 'a') {
					}
					else if (lst == 'C') {
						if (c == 'J') {
							cost += x;
						}
					}
					else if (lst == 'J') {
						if (c == 'C') {
							cost += y;
						}
					}

					lst = c;
				}
			}
			else {
				if (c == '?') {
					continue;
				}
				else {
					if (lst == 'a') {
					}
					else if (lst == 'C') {
						if (c == 'J') {
							cost += x;
						}
					}
					else if (lst == 'J') {
						if (c == 'C') {
							cost += y;
						}
					}
					
					lst = c;
				}
			}
		}

		cout << "Case #" << cas << ": " << cost << '\n';
	}

}