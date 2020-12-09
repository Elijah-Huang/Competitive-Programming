#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, x; cin >> n >> x;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}

	sort(a.begin(), a.end());

	int right_idx = n - 1;
	for (int i = 0; i < n; i++) {
		while (right_idx > i and a[i].first + a[right_idx].first > x) {
			right_idx--;
		}
		if (right_idx <= i) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		if (a[i].first + a[right_idx].first == x) {
			cout << a[i].second << ' ' << a[right_idx].second;
			return 0;
		}
	}
}