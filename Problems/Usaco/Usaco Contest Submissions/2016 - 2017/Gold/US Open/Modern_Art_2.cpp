#include<bits/stdc++.h>
using namespace std;

struct interval {
	int l = -1, r = -1;
};

vector<int> colors(1e5);
vector<interval> intervals(1e5 + 1);

int solve(int l, int r, int c) {
	int mx_internal = 0;
	for (int i = l + 1; i < r; i++) {
		if (colors[i] != c) {
			mx_internal = max(mx_internal, solve(i, intervals[colors[i]].r, colors[i]));
			i = intervals[colors[i]].r;
		}
	}
	return 1 + mx_internal;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("art2.in", "r", stdin); freopen("art2.out", "w", stdout);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> colors[i];
		if (intervals[colors[i]].l == -1) {
			intervals[colors[i]].l = intervals[colors[i]].r = i;
		}
		else {
			intervals[colors[i]].r = i;
		}
	}

	bool no_cycle = true;
	stack<int> active_intervals;
	for (int i = 0; i < n; i++) {
		if (intervals[colors[i]].l == i){
			if (intervals[colors[i]].r != i) {
				active_intervals.push(colors[i]);
			}
		}
		else {
			if (active_intervals.top() != colors[i]) {
				no_cycle = false;
				break;
			}
			else if (intervals[colors[i]].r == i) {
				active_intervals.pop();
			}
		}
	}

	if (no_cycle) {
		cout << solve(-1, n, 0) - 1;
	}
	else {
		cout << -1;
	}
}