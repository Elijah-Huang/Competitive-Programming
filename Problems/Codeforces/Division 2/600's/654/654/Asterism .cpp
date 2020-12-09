#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	const int maxn = 1e5;
	int n, p, a[maxn];
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mn = *max_element(a, a + n) - n + 1;
	int placements[maxn], under[maxn]{};
	for (int i = 0; i < n; i++) {
		if (a[i] <= mn) {
			under[0]++;
		}
		else {
			under[a[i] - mn]++;
		}
	}
	placements[0] = under[0];
	int smallest = min(1, placements[0]);
	for (int i = 1; i < n; i++) {
		placements[i] = placements[i - 1] - 1 + under[i];
		smallest = min(smallest, placements[i]);
	}
	if (smallest <= 0) {
		int to_add = -smallest + 1;
		for (int i = 0; i < to_add; i++) {
			under[to_add] += under[i];
		}
		placements[0] = under[to_add];
		for (int i = 1; i < n; i++) {
			if (i + to_add < n) {
				placements[i] = placements[i - 1] - 1 + under[i + to_add];
			}
			else {
				placements[i] = placements[i - 1] - 1;
			}
		}
		mn += to_add;
	}
	int least_to_reach_p = p-1;
	for (int i = 0; i < n; i++) {
		if (p - placements[i] <= i) {
			least_to_reach_p = min(least_to_reach_p, p - placements[i]);
		}
	}
	if (least_to_reach_p <= 0) {
		cout << 0 << '\n';
	}
	else {
		cout << least_to_reach_p << '\n';
		for (int i = mn; i < mn + least_to_reach_p; i++) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}