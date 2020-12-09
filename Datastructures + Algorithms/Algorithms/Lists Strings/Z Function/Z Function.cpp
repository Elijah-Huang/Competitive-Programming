#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string& s) {
	vector<int> z(s.length());
	for (int i = 1, l = 0, r = 0; i < s.length(); i++) {
		if (i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < s.length() and s[i + z[i]] == s[z[i]]) {
			z[i]++;
		}

		if (i + z[i] - 1 > r) {
			l = i, r = i + z[i] - 1;
		}
	}

	return z;
}