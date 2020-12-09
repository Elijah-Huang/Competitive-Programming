#include<bits/stdc++.h>
using namespace std;

struct group {
	int o, n;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("pairup.in", "r", stdin); freopen("pairup.out", "w", stdout);
	int n, mx_time = 0;
	cin >> n;
	vector<group> cows(n);
	for (int i = 0; i < n; i++) {
		int o, n;
		cin >> n >> o;
		cows[i] = { o,n };
	}
	sort(cows.begin(), cows.end(),
		[&](const group& a, const group& b) { return a.o < b.o; });
	int ridx = n - 1;
	int leftover = cows[n-1].n;
	for (int i = 0; i < n; i++) {
		if (ridx == i) {
			mx_time = max(mx_time, 2 * cows[i].o);
			break;
		}
		int paired = cows[i].n;
		if (leftover > paired) {
			leftover -= paired;
			mx_time = max(mx_time, cows[i].o + cows[ridx].o);
		}
		else {
			paired -= leftover;
			mx_time = max(mx_time, cows[i].o + cows[ridx].o);
			ridx--;
			while (ridx > i) {
				if (paired >= cows[ridx].n) {
					paired -= cows[ridx].n;
					mx_time = max(mx_time, cows[i].o + cows[ridx].o);
					ridx--;
				}
				else {
					leftover = cows[ridx].n - paired;
					mx_time = max(mx_time, cows[i].o + cows[ridx].o);
					break;
				}
			}
			if (ridx == i) {
				if (paired) {
					mx_time = max(mx_time, 2 * cows[i].o);
				}
				break;
			}
		}
	}
	cout << mx_time;
}