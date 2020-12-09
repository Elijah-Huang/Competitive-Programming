#include<bits/stdc++.h>
using namespace std;
struct spot {
	int x, t;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("reststops.in", "r", stdin); freopen("reststops.out", "w", stdout);
	int L, n, f, b;
	long long diff, total_taste = 0;
	cin >> L >> n >> f >> b;
	diff = f - b;
	vector<spot> spots(n);
	for (int i = 0; i < n; i++) {
		int x, t;
		cin >> x >> t;
		spots[i] = { x,t };
	}
	sort(spots.begin(), spots.end(),
		[&](const spot& a, const spot& b) {return (a.t == b.t) ? a.x < b.x : a.t > b.t; });
	int old_loc = 0;
	int idx = 0;
	while (idx < n) {
		while (idx < n and old_loc > spots[idx].x) {
			idx++;
		}
		total_taste += diff * (spots[idx].x - old_loc) * (spots[idx].t);
		old_loc = spots[idx].x;
		idx++;
	}
	cout << total_taste;
}