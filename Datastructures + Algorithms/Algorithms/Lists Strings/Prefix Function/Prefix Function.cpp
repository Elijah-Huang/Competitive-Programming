#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string& s) {
	vector<int> pf(s.length());
	for (int i = 1; i < s.length(); i++) {
		int j = pf[i - 1];
		while (j > 0 and s[j] != s[i]) {
			j = pf[j - 1];
		}
		pf[i] = j + (s[j] == s[i]);
	}

	return pf;
}