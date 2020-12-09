#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
bool comparator(pair<int,int> const &a, pair<int,int> const &b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	const int maxn = 2e4;
	int n, x[maxn];
	vector<pair<int, int>> xv(maxn);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		xv[i].first = x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> xv[i].second;
	}
	sort(x, x + n);
	sort(xv.begin(), xv.begin() + n, comparator);
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		m[x[i]] = i;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += x[i] * (2ll * i - (n - 1));
	}
	for (int i = 0; i < n; i++) {
		ans += (long long) xv[i].first*(i - m[xv[i].first]);
	}
	cout << ans;
}