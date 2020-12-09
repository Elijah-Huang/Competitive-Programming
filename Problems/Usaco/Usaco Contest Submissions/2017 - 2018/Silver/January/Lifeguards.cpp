#include<bits/stdc++.h>
using namespace std;
struct interval {
	int a, b;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("lifeguards.in", "r", stdin); freopen("lifeguards.out", "w", stdout);
	int n;
	int total_time = 0;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	vector<interval> intervals(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		intervals[i] = { a,b };
	}
	sort(intervals.begin(), intervals.end(),
		[&](const interval& a, const interval& b) {return a.a < b.a; });
	int prev_max = 0;
	bool not_contained = true;
	for (int i = 0; i < n; i++) {
		if (intervals[i].b < prev_max) {
			not_contained = false;
			break;
		}
		else {
			prev_max = intervals[i].b;
		}
	}
	int leftpoint = -1, rightpoint = -1;
	for (int i = 0; i < n; i++) {
		if (rightpoint < intervals[i].a) {
			total_time += rightpoint - leftpoint;
			leftpoint = intervals[i].a;
			rightpoint = intervals[i].b;
		}
		else {
			rightpoint = max(rightpoint, intervals[i].b);
		}
	}
	total_time += rightpoint - leftpoint;
	if (not_contained) {
		int min_unique = int(1e9);
		for (int i = 1; i < n - 1; i++) {
			min_unique = min(min_unique, min(intervals[i].b, intervals[i + 1].a)
				- max(intervals[i - 1].b, intervals[i].a));
		}
		if (n > 1) {
			min_unique = min(min_unique, min(intervals[0].b, intervals[1].a) - intervals[0].a);
			min_unique = min(min_unique, intervals[n - 1].b - max(intervals[n - 1].a, intervals[n - 2].b));
		}
		total_time -= min_unique;
	}
	cout << total_time;
}