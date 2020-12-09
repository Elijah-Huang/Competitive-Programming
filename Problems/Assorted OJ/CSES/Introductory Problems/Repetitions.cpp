#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	s.push_back('a');
	int l = 1;
	int most = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[i + 1]) {
			most = max(most, l);
			l = 1;
		}
		else {
			l += 1;
		}
	}

	cout << most << '\n';
}