#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int counts[200]{};
	for (int i = 0; i < s.length(); i++) {
		counts[s[i]]++;
	}

	if (s.length() % 2 == 0) {
		for (int i = 'A'; i <= 'Z'; i++) {
			if (counts[i] % 2 == 1) {
				cout << "NO SOLUTION";
				return 0;
			}
		}
		string ans;
		string end;
		for (int i = 'A'; i <= 'Z'; i++) {
			end += string(counts[i] / 2, char(i));
		}
		ans = end;
		reverse(end.begin(), end.end());
		ans += end;
		cout << ans;
	}
	else {
		int odd = 0;
		for (int i = 'A'; i <= 'Z'; i++) {
			if (counts[i] % 2 == 1) {
				if (odd != 0) {
					cout << "NO SOLUTION";
					return 0;
				}
				else {
					odd = i;
				}
			}
		}
		string ans;
		string end;
		for (int i = 'A'; i <= 'Z'; i++) {
			if (i == odd) continue;
			end += string(counts[i] / 2, char(i));
		}
		ans = end;
		reverse(end.begin(), end.end());
		ans += string(counts[odd], char(odd)) + end;
		cout << ans;
	}
}