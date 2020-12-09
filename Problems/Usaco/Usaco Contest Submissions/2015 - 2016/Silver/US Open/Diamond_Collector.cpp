#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("diamond.in", "r", stdin); freopen("diamond.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> diamonds(n);
	vector<int> max_at(n);
	vector<int> max_after(n+1);
	int largest = 0;
	for (int i = 0; i < n; i++) {
		cin >> diamonds[i];
	}
	sort(diamonds.begin(), diamonds.end());
	for (int i = 0; i < n; i++) {
		max_at[i] = int(upper_bound(diamonds.begin(), diamonds.end(),
			diamonds[i] + k) - diamonds.begin()) - i;
	}
	for (int i = n - 1; i >= 0; i--) {
		max_after[i] = max(max_after[i + 1], max_at[i]);
	}
	for (int smallest = 0; smallest < n; smallest++) {
		int endpoint = smallest + max_at[smallest];
		largest = max(largest, max_at[smallest] + max_after[endpoint]);
	}
	cout << largest;
}