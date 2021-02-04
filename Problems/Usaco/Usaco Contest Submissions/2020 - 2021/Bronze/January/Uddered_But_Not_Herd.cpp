#include<bits/stdc++.h>
using namespace std;

int ans = 0, idx = 0;
string alphabet;
string hum;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> alphabet >> hum;

	for (auto c : hum) {
		while (alphabet[idx%26] != c) {
			idx++;
		}
		idx++;
	}

	cout << idx / 26 + 1;
}