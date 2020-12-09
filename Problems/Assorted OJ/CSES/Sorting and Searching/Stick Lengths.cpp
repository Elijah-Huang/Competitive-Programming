#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	
	sort(p.begin(), p.end());
	
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(p[i] - p[(n + 1) / 2 - 1]);
	}

	cout << ans;
}