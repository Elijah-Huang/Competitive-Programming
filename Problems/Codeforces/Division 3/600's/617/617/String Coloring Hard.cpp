#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin >> n;
	cin >> s;
	vector<int> needed_color(26);
	vector<int> output(n);
	for (int i = 0; i < n; i++) {
		int idx = int(s[i]) - int('a');
		if (idx < 25) {
			needed_color[idx] = *max_element(needed_color.begin() + idx + 1, needed_color.end()) + 1;
		}
		else {
			needed_color[idx] = 1;
		}
		output[i] = needed_color[idx];
	}
	cout << *max_element(needed_color.begin(), needed_color.end()) << '\n';
	for (auto i : output) {
		cout << i << ' ';
	}
}