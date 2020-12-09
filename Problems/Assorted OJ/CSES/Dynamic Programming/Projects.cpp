#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<long long, int>> endpoints(2 * n);
	vector<int> reward(n);
	for (int i = 0; i < n; i++) {
		cin >> endpoints[2 * i].first >> endpoints[2 * i + 1].first;
		cin >> reward[i];
		endpoints[2 * i].second = i;
		endpoints[2 * i + 1].second = i + n;
	}
	
	sort(endpoints.begin(), endpoints.end());
	
	vector<int> ending_time(n);
	for (int i = 0; i < 2 * n; i++) {
		ending_time[endpoints[i].second % n] = i;
	}
	
	long long prefix_mx = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (ending_time[endpoints[i].second % n] == i) {
			prefix_mx = max(prefix_mx, endpoints[i].first);
		}
		else {
			endpoints[ending_time[endpoints[i].second]].first = prefix_mx + reward[endpoints[i].second];
		}
	}

	cout << prefix_mx;
}