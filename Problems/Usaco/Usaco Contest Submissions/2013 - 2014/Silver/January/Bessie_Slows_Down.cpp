#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("slowdown.in", "r", stdin); freopen("slowdown.out", "w", stdout);
	int n; cin >> n;
	int speed = 1;
	double time = 0;
	double dist = 0;
	vector<int> times;
	vector<int> dists;
	int t1 = 0, d1 = 0;

	for (int i = 0; i < n; i++) {
		char t;
		int x;
		cin >> t >> x;
		if (t == 'T') {
			times.push_back(x);
		}
		else {
			dists.push_back(x);
		}
	}

	dists.push_back(1000);
	sort(dists.begin(), dists.end());
	sort(times.begin(), times.end());
	
	while (t1 < times.size() or d1 < dists.size()) {
		//cout << t1 << ' ' << d1 << ' ' << time << ' ' << dist << ' ' << speed << '\n';
		if (d1 < dists.size() and t1 < times.size()) {
			double to_travel = dists[d1] - dist;
			double time_needed = to_travel * speed;
			if (time_needed + time < times[t1]) {
				time += time_needed;
				dist = dists[d1];
				while (d1 < dists.size() and dists[d1] == dist) {
					d1++;
					speed++;
				}
			}
			else {
				dist += (times[t1] - time) / speed;
				time = times[t1];
				while (t1 < times.size() and times[t1] == time) {
					t1++;
					speed++;
				}
			}
		}
		else if (t1 < times.size()){
			dist += (times[t1] - time) / speed;
			time = times[t1];
			while (t1 < times.size() and times[t1] == time) {
				t1++;
				speed++;
			}
		}
		else if (d1 < dists.size()){
			double to_travel = dists[d1] - dist;
			double time_needed = to_travel * speed;
			time += time_needed;
			dist = dists[d1];
			while (d1 < dists.size() and dists[d1] == dist) {
				d1++;
				speed++;
			}
		}
		//cout << t1 << ' ' << d1 << ' ' << time << ' ' << dist << ' ' << speed << '\n';
	}

	if (fabs(time - (int(time) + 0.5)) < 1e-7) {
		cout << int(ceil(time));
	}
	else {
		cout << int(round(time));
	}
}