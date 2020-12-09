#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> endpoints(2 * n);
	for (int i = 0; i < n; i++){
		cin >> endpoints[2 * i].first >> endpoints[2 * i + 1].first;
		endpoints[2 * i].second = 1; endpoints[2 * i + 1].second = -1;
	}

	sort(endpoints.begin(), endpoints.end());

	int mx = 0, curr = 0;
	for (int i = 0; i < 2*n; i++) {
		curr += endpoints[i].second;
		mx = max(mx, curr);
	}
	
	cout << mx;
}