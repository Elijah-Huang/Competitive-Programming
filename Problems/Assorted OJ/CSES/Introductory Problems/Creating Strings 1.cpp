#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;

	sort(s.begin(), s.end());
	string output;
	int amt = 0;
	do {
		output += s + '\n';
		amt++;
	} while (next_permutation(s.begin(), s.end()));

	cout << amt << '\n';
	cout << output;
}