#include<bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("split.in", "r", stdin); freopen("split.out", "w", stdout);
	int n; cin >> n;
	vector<point> points(n);
	vector<long long> from_left(n, 1ll << 60);
	vector<long long> from_right(n, 1ll << 60);
	long long one_best;
	long long two_best;
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	}
	
	// vertical dividng line
	sort(points.begin(), points.end(), [&](const point& a, const point& b) {return a.x < b.x; });

	int min_x = points[0].x;
	int max_x = points[n - 1].x;
	int min_y = 1 << 30;
	int max_y = 0;
	long long curr_x;
	for (int i = 0; i < n; i++) {
		curr_x = points[i].x;
		while (i < n and points[i].x == curr_x) {
			max_y = max(max_y, points[i].y);
			min_y = min(min_y, points[i].y);
			i++;
		}
		i--;
		from_left[i] = (max_y - min_y) * (curr_x - min_x);
	}
	one_best = two_best = from_left[n - 1];
	min_y = 1 << 30;
	max_y = 0;
	for (int i = n - 1; i >= 0; i--) {
		curr_x = points[i].x;
		while (i >= 0 and points[i].x == curr_x) {
			max_y = max(max_y, points[i].y);
			min_y = min(min_y, points[i].y);
			i--;
		}
		i++;
		from_right[i] = (max_y - min_y) * (max_x - curr_x);
	}

	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < n and points[j].x == points[i].x) {
			j++;
		}
		if (j == n) break;
		two_best = min(two_best, from_left[i] + from_right[j]);
	}
	
	// horizontal dividng line
	from_left.assign(n, 1ll << 60);
	from_right.assign(n, 1ll << 60);
	sort(points.begin(), points.end(), [&](const point& a, const point& b) {return a.y < b.y; });

	min_y = points[0].y;
	max_y = points[n - 1].y;
	min_x = 1 << 30;
	max_x = 0;
	long long curr_y;
	for (int i = 0; i < n; i++) {
		curr_y = points[i].y;
		while (i < n and points[i].y == curr_y) {
			max_x = max(max_x, points[i].x);
			min_x = min(min_x, points[i].x);
			i++;
		}
		i--;
		from_left[i] = (max_x - min_x) * (curr_y - min_y);
	}
	min_x = 1 << 30;
	max_x = 0;
	for (int i = n - 1; i >= 0; i--) {
		curr_y = points[i].y;
		while (i >= 0 and points[i].y == curr_y) {
			max_x = max(max_x, points[i].x);
			min_x = min(min_x, points[i].x);
			i--;
		}
		i++;
		from_right[i] = (max_x - min_x) * (max_y - curr_y);
	}
	
	j = 0;
	for (int i = 0; i < n; i++) {
		while (j < n and points[j].y == points[i].y) {
			j++;
		}
		if (j == n) break;
		two_best = min(two_best, from_left[i] + from_right[j]);
	}

	cout << one_best - two_best << '\n';
}