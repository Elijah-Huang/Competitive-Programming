#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a(n), b(n), amt_top(n + 1), amt_bot(n + 1);
	map<pair<int, int>, int> pairs;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += i - (amt_top[a[i]] + amt_bot[b[i]] - pairs[{a[i], b[i]}]);
		amt_top[a[i]]++;
		amt_bot[b[i]]++;
		pairs[{a[i], b[i]}]++;
	}

	cout << ans << '\n';
}