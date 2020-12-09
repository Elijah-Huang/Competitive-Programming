#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("taxi.in", "r", stdin); freopen("taxi.out", "w", stdout);
	long long total_dist = 0;
	int n, m; cin >> n >> m;
	map<int, int> endpoints;
	long long slope = -2;
	total_dist += m;
	for (int i = 0; i < n; i++) {
		int s, e; cin >> s >> e;
		endpoints[s] += 2;
		endpoints[e] -= 2;
		if (e < s) {
			total_dist += 2 * (s - e);
		}
	}

	int curr_loc = 0;
	for (auto ep : endpoints) {
		total_dist += max(0ll , slope * (ep.first - curr_loc));
		curr_loc = ep.first;
		slope += ep.second;
	}

	cout << total_dist;

}