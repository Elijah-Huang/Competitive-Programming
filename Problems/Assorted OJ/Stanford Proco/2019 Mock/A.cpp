#include<bits/stdc++.h>
using namespace std;

int counts[26];
int main() {
	string s; cin >> s;
	for (auto i : s) {
		counts[i - 'a']++;
	}

	cout << char('a' + int(max_element(counts, counts + 26)-counts)) << '\n';
	cout << s;
}