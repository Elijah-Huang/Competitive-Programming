/*
ID: elijahj1
TASK: fence4
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
};

struct segment {
	double x1, y1, x2, y2;
};

vector<segment> fence_sides, fence_sides2;

bool sign(double val) {
	return (val <= 0 ? 0 : 1);
}

bool intersect(segment& a, segment& b, double error = 1e-7) {
	return (sign((a.x1 - b.x1) * (b.y2 - b.y1) - (b.x2 - b.x1) * (a.y1 - b.y1)) !=
		sign((a.x2 - b.x1) * (b.y2 - b.y1) - (b.x2 - b.x1) * (a.y2 - b.y1)) and
		sign((b.x1 - a.x1) * (a.y2 - a.y1) - (a.x2 - a.x1) * (b.y1 - a.y1)) !=
		sign((b.x2 - a.x1) * (a.y2 - a.y1) - (a.x2 - a.x1) * (b.y2 - a.y1)));
}

int intersects_with_fence(segment test, int removed) {
	for (int j = 0; j < fence_sides2.size(); j++) {
		if (j != removed and intersect(fence_sides2[j], test)) {
			return j;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fence4.in", "r", stdin); freopen("fence4.out", "w", stdout);
	double x, y;
	int n; cin >> n >> x >> y;
	vector<point> points(n);
	vector<bool> visible(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	}

	for (int i = 0; i < n - 2; i++) {
		fence_sides.push_back({ points[i].x, points[i].y, points[i + 1].x,points[i + 1].y });
	}
	fence_sides.push_back({ points[0].x, points[0].y, points[n - 1].x, points[n - 1].y });
	fence_sides.push_back({ points[n - 2].x, points[n - 2].y, points[n - 1].x, points[n - 1].y });
	fence_sides2 = fence_sides;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if ((!(fence_sides[i].x1 == fence_sides[j].x1 and fence_sides[i].y1 == fence_sides[j].y1) and
				!(fence_sides[i].x2 == fence_sides[j].x2 and fence_sides[i].y2 == fence_sides[j].y2) and
				!(fence_sides[i].x1 == fence_sides[j].x2 and fence_sides[i].y1 == fence_sides[j].y2) and
				!(fence_sides[i].x2 == fence_sides[j].x1 and fence_sides[i].y2 == fence_sides[j].y1)) and
				intersect(fence_sides[i], fence_sides[j])) {
				cout << "NOFENCE\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (fence_sides[i].x2 == fence_sides[i].x1 and fence_sides[i].x1 == x or
			fence_sides[i].y2 == fence_sides[i].y1 and fence_sides[i].y1 == y) {
			continue;
		}
		for (int fraction = 1; fraction < 180; fraction++) {
			double added_x = (fence_sides[i].x2 - fence_sides[i].x1) * fraction / 180;
			double added_y = (fence_sides[i].y2 - fence_sides[i].y1) * fraction / 180;
			segment test = { x, y, fence_sides[i].x1 + added_x, fence_sides[i].y1 + added_y };
			if (intersects_with_fence(test, i) == -1) {
				visible[i] = 1;
				break;
			}
		}
	}

	int seen = 0;
	for (int i = 0; i < n; i++) {
		if (visible[i]) {
			seen++;
		}
	}
	cout << seen << '\n';
	for (int i = 0; i < n; i++) {
		if (visible[i]) {
			cout << fence_sides[i].x1 << ' ' << fence_sides[i].y1 << ' ' << fence_sides[i].x2 << ' ' << fence_sides[i].y2 << '\n';
		}
	}
}