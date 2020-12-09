#include<bits/stdc++.h>
using namespace std;

struct cow {
	int x, h;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("crowded.in", "r", stdin); freopen("crowded.out", "w", stdout);
	int n, d; cin >> n >> d;
	vector<cow> cows;
	for (int i = 0; i < n; i++) {
		int x, h; cin >> x >> h;
		cows.push_back({ x,h });
	}
	
	sort(cows.begin(), cows.end(),
		[&](const cow& a, const cow& b) {return a.x < b.x; });
	
	set<int> left;
	set<int> right;
	int left_idx = 0;
	int right_idx = 1;
	int total = 0;
	for (int i = 1; i < n-1; i++) {
		if (cows[i - 1].x + d >= cows[i].x) {
			left.insert(cows[i - 1].h);
		}
		if (right.count(cows[i].h)) {
			right.erase(cows[i].h);
		}
		while (cows[left_idx].x < cows[i].x - d) {
			left.erase(cows[left_idx].h);
			left_idx++;
		}
		while (right_idx < n and cows[right_idx].x <= cows[i].x + d) {
			if (right_idx != i) {
				right.insert(cows[right_idx].h);
			}
			right_idx++;
		}
		total += (left.lower_bound(2 * cows[i].h) != left.end() and
			right.lower_bound(2 * cows[i].h) != right.end());
	}

	cout << total;
}