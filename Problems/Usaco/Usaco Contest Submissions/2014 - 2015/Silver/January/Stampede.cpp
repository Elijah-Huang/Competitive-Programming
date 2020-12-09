#include<bits/stdc++.h>
using namespace std;

struct event {
	int t, y, type;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("stampede.in", "r", stdin); freopen("stampede.out", "w", stdout);
	int n; cin >> n;
	vector<event> events;
	for (int i = 0; i < n; i++) {
		int x, y, r; cin >> x >> y >> r;
		events.push_back({ -(x + 1) * r, y, 1 });
		events.push_back({ -x * r, y, -1 });
	}

	sort(events.begin(), events.end(), [&](const event& a, const event& b)
		{ if (a.t == b.t) { return a.y < b.y;} return a.t < b.t; });

	set<int> in_ray;
	set<int> seen;
	for (int i = 0; i < 2 * n; i++) {
		int curr_time = events[i].t;
		vector<event> same_time;
		while (i < 2 * n and events[i].t == curr_time) {
			same_time.push_back(events[i]);
			i++;
		}
		i--;

		for (auto& e : same_time) {
			if (e.type == 1) {
				in_ray.insert(e.y);
			}
			else {
				in_ray.erase(e.y);
			}
		}
		if (in_ray.size()) {
			seen.insert(*in_ray.begin());
		}
	}

	cout << seen.size();
}