#include<bits/stdc++.h>
using namespace std;

struct bale {
	int x, s;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);
	int n, b; cin >> n >> b;
	vector<bale> haybales(n);
	for (int i = 0; i < n; i++) {
		cin >> haybales[i].s >> haybales[i].x;
	}

	sort(haybales.begin(), haybales.end(),
		[&](const bale& a, const bale& b) {return a.x < b.x; });

	if (b < haybales[0].x or b > haybales[n - 1].x) {
		cout << -1;
		return 0;
	}

	int lstart = 0, rstart = n - 1;
	while (lstart != rstart) {
		int m = (lstart + rstart) / 2;
		if (haybales[m].x < b) {
			lstart = m + 1;
		}
		else {
			rstart = m;
		}
	}
	lstart = rstart - 1;

	int mn = 2e9;
	vector<int> furthest_right(n, n);
	vector<int> furthest_left(n, -1);
	int l = lstart, r = rstart;
	while (l != -1 and r != n) {
		int dist = haybales[r].x - haybales[l].x;
		if (dist > haybales[l].s) {
			l--;
		}
		else {
			furthest_left[r] = l;
			if (dist > haybales[r].s) {
				r++;
			}
			else {
				cout << 0;
				return 0;
			}
		}
	}
	l = lstart, r = rstart;
	while (l != -1 and r != n) {
		int dist = haybales[r].x - haybales[l].x;
		if (dist > haybales[r].s) {
			r++;
		}
		else {
			furthest_right[l] = r;
			if (dist > haybales[l].s) {
				l--;
			}
			else {
				cout << 0;
				return 0;
			}
		}
	}
	
	for (int i = 0; i <= lstart; i++) {
		if (furthest_right[i] != n) {
			mn = min(mn, haybales[furthest_right[i]].x - haybales[i].x - haybales[i].s);
		}
	}
	for (int i = n - 1; i >= rstart; i--) {
		if (furthest_left[i] != -1) {
			mn = min(mn, haybales[i].x - haybales[furthest_left[i]].x - haybales[i].s);
		}
	}

	cout << (mn < 2e9 ? mn : -1);
}