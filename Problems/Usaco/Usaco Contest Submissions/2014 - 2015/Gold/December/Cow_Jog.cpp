// O(nlogn)
// greedily maintain lanes -> ans is # of lanes in the end
#include<bits/stdc++.h>
using namespace std;

struct cow {
	long long l, r;
};

struct cowcmp {
	bool operator()(const cow& a, const cow& b) const {
		return a.r < b.r;
	}
};

long long n, t;
vector<cow> cows;
// multiset of lanes, storing the maximum right endpoint of a segment in that lane
multiset<cow, cowcmp> lanes;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("cowjog.in", "r", stdin); freopen("cowjog.out", "w", stdout);

	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		long long l, s; cin >> l >> s;
		cows.push_back({ l,l + s * t });
	}

	sort(cows.begin(), cows.end(), [&](const cow& a, const cow& b) {return a.l < b.l; });

	for (int i = 0; i < n; i++) {
		auto lane = lanes.lower_bound(cows[i]);
		
		if (lane == lanes.begin()) {
			// segment is completely contained in a segment in any of the lanes -> make new lane
			lanes.insert(cows[i]);
		}
		else {
			// segment can be added to one of the lanes 
			// (lane with segment that has maximum right endpoint is optimal)
			lane--;
			lanes.erase(lane);
			lanes.insert(cows[i]);
		}
	}

	cout << lanes.size();
}