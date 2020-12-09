#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
	int n, max_back = 0;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]].push_back(i);
	}
	sort(a.begin(), a.end());
	int idx = 0;
	while (idx < n) {
		for (auto i : mp[a[idx]]) {
			max_back = max(max_back, i - idx);
			idx++;
		}
	}
	cout << max_back + 1;
}