#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long k;
	int n; cin >> n >> k;
	vector<pair<int, int>> endpoints(n);
	multiset<int> active_watchers;
	int total_watched = 0;
	for (int i = 0; i < n; i++) {
		cin >> endpoints[i].first >> endpoints[i].second;
	}

	sort(endpoints.begin(), endpoints.end(), 
		[&](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second; });

	for (int i = 0; i < n; i++) {
		auto loc = active_watchers.upper_bound(endpoints[i].first);
		if (loc == active_watchers.begin()) {
			if (active_watchers.size() < k) {
				active_watchers.insert(endpoints[i].second);
				total_watched++;
			}
		}
		else {
			--loc;
			active_watchers.erase(loc);
			active_watchers.insert(endpoints[i].second);
			total_watched++;
		}
	}

	cout << total_watched;
}