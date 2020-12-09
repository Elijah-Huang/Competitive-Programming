#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		char first = s[0];
		int tot = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == first) {
				tot++;
			}
			else {
				break;
			}
		}
		int greater = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == '<') {
				greater++;
			}
		}
		if (s[0] == '<') {
			greater++;
		}

		//start of min

		int curr_g = n, curr_s = n-greater;
		if (first == '<') {
			for (int i = n-tot; i <= n; i++) {
				cout << i << ' ';
			}
			curr_g -= tot + 1;
		}
		else {
			for (int i = curr_s; i >= curr_s - tot; i--) {
				cout << i << ' ';
			}
			curr_s -= tot + 1;
		}
		int length = 0;
		for (int i = tot; i <= n-1; i++) {
			if (i != n-1 and s[i] == s[i - 1]) {
				length++;
			}
			else {
				if (s[i - 1] == '<') {
					for (int i = curr_g - length+1; i <= curr_g; i++) {
						cout << i << ' ';
					}
					curr_g -= length;
				}
				else {
					for (int i = curr_s; i >= curr_s - length +1; i--) {
						cout << i << ' ';
					}
					curr_s -= length;
				}
				length = 1;
			}
		}
		cout << '\n';

		//start of max

		curr_g = n - greater + 1, curr_s = 1;
		if (first == '<') {
			for (int i = curr_g; i <= curr_g + tot; i++) {
				cout << i << ' ';
			}
			curr_g += tot + 1;
		}
		else {
			for (int i = tot + 1; i >= 1; i--) {
				cout << i << ' ';
			}
			curr_s += tot + 1;
		}
		length = 0;
		for (int i = tot; i <= n - 1; i++) {
			if (i != n - 1 and s[i] == s[i - 1]) {
				length++;
			}
			else {
				if (s[i - 1] == '<') {
					for (int i = curr_g; i < curr_g + length; i++) {
						cout << i << ' ';
					}
					curr_g += length;
				}
				else {
					for (int i = curr_s + length -1; i >= curr_s; i--) {
						cout << i << ' ';
					}
					curr_s += length;
				}
				length = 1;
			}
		}
		cout << '\n';
		/*
		int curr = tot + 2;
		length = 0;
		for (int i = tot; i <= n-1; i++) {
			if (i != n-1 and s[i] == s[i - 1]) {
				length++;
			}
			else {
				if (s[i - 1] == '<') {
					for (int i = curr; i < curr + length; i++) {
						cout << i << ' ';
					}
				}
				else {
					for (int i = curr + length - 1; i >= curr; i--) {
						cout << i << ' ';
					}
				}
				curr += length;
				length = 1;
			}
		}
		cout << '\n';
		*/
	}
}