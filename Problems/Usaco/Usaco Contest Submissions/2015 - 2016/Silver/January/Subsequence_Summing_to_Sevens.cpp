#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("div7.in", "r", stdin); freopen("div7.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> cows(n);
	vector<int> left(7,-1), right(7,-1);
	left[0] = right[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> cows[i];
		cows[i] %= 7;
	}
	int curr = 0;
	for (int i = 0; i < n; i++) {
		curr = (curr + cows[i]) % 7;
		if (left[curr] < 0) {
			left[curr] = i + 1;
		}
	}
	curr = 0;
	for (int i = n - 1; i >= 0; i--) {
		curr = (curr + cows[i]) % 7;
		if (right[curr] < 0) {
			right[curr] = n - i;
		}
	}
	if (curr == 0) {
		cout << n;
	}
	else {
		int mn_removed = n;
		for (int i = 0; i <= curr; i++) {
			if (left[i] >= 0 and right[curr - i] >= 0) {
				mn_removed = min(mn_removed, left[i] + right[curr - i]);
			}
		}
		cout << n - mn_removed;
	}
	
}