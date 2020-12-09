/*
ID: elijahj1
TASK: fence4
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
double pi = 2 * (atan(2) + atan(0.5));

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
	/*if (abs((a.x2 - a.x1) * (b.y1 - a.y1) - (b.x1 - a.x1) * (a.y2 - a.y1)) < error and
		abs((a.x2 - a.x1) * (b.y2 - a.y1) - (b.x2 - a.x1) * (a.y2 - a.y1)) < error) {
		//cout << "terrible\n";
		return min(a.x1, a.x2) - error <= max(b.x1, b.x2) and max(a.x1, a.x2) + error >= min(b.x1, b.x2);
	}*/
	/*else if (abs((a.x2 - a.x1) * (b.y1 - a.y1) - (b.x1 - a.x1) * (a.y2 - a.y1)) < error
		and min(a.x1, a.x2) <= b.x1 + error and b.x1 - error <= max(a.x1, a.x2) or
		abs((a.x2 - a.x1) * (b.y2 - a.y1) - (b.x2 - a.x1) * (a.y2 - a.y1)) < error
		and min(a.x1, a.x2) <= b.x2 + error and b.x2 - error <= max(a.x1, a.x2)) {
		cout << abs((a.x2 - a.x1) * (b.y1 - a.y1) - (b.x1 - a.x1) * (a.y2 - a.y1)) << '\n';
		cout << a.x2 << ' ' << a.y2 << ' ' << b.x2 << ' ' << b.y2 << ' ' << '\n';
		cout << a.x1 << ' ' << a.y1 << '\n';
		cout << abs((a.x2 - a.x1) * (b.y2 - a.y1) - (b.x2 - a.x1) * (a.y2 - a.y1)) << '\n';
		cout << "uhoh\n";
		return true;
	}*/
		/*cout << (sign((a.x1 - b.x1) * (b.y2 - b.y1) - (b.x2 - b.x1) * (a.y1 - b.y1)) !=
			sign((a.x2 - b.x1) * (b.y2 - b.y1) - (b.x2 - b.x1) * (a.y2 - b.y1)) and
			sign((b.x1 - a.x1) * (a.y2 - a.y1) - (a.x2 - a.x1) * (b.y1 - a.y1)) !=
			sign((b.x2 - a.x1) * (a.y2 - a.y1) - (a.x2 - a.x1) * (b.y2 - a.y1))) << '\n';*/
		return (sign((a.x1 - b.x1) * (b.y2 - b.y1) - (b.x2 - b.x1) * (a.y1 - b.y1)) !=
			sign((a.x2 - b.x1) * (b.y2 - b.y1) - (b.x2 - b.x1) * (a.y2 - b.y1)) and
			sign((b.x1 - a.x1) * (a.y2 - a.y1) - (a.x2 - a.x1) * (b.y1 - a.y1)) !=
			sign((b.x2 - a.x1) * (a.y2 - a.y1) - (a.x2 - a.x1) * (b.y2 - a.y1)));
}

int intersects_with_fence(segment test) {
	for (int j = 0; j < fence_sides2.size(); j++) {
		if (intersect(fence_sides2[j], test)) {
			return j;
		}
	}
	return -1;
}

int final_intersect(segment test) {
	for (int i = 0; i < fence_sides.size(); i++) {
		if ((!(abs(fence_sides[i].x1 - test.x1) < 1e-4 and abs(fence_sides[i].y1 - test.y1) < 1e-4) and
			!(abs(fence_sides[i].x1 - test.x2) < 1e-4 and abs(fence_sides[i].y1 - test.y2) < 1e-4) and
			!(abs(fence_sides[i].x2 - test.x1) < 1e-4 and abs(fence_sides[i].y2 - test.y1) < 1e-4) and
			!(abs(fence_sides[i].x2 - test.x2) < 1e-4 and abs(fence_sides[i].y2 - test.y2) < 1e-4) and
			intersect(fence_sides[i], test))) {
			return i;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fence4.in", "r", stdin); freopen("fence4.out", "w", stdout);
	double start = 0, end = 2*pi;
	double most_dist = 0;
	double x, y;
	int n; cin >> n >> x >> y;
	vector<point> points(n);
	vector<bool> visible(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
		most_dist = max(most_dist, sqrt((points[i].x - x) * (points[i].x - x) + (points[i].y - y) * (points[i].y - y)));
	}
	most_dist += 1;
	//clock_t startt = clock();
	for (int i = 0; i < n-2; i++) {
		fence_sides.push_back({ points[i].x, points[i].y, points[i + 1].x,points[i + 1].y });
	}
	fence_sides.push_back({ points[0].x, points[0].y, points[n - 1].x, points[n - 1].y });
	fence_sides.push_back({ points[n - 2].x, points[n - 2].y, points[n - 1].x, points[n - 1].y });
	fence_sides2 = fence_sides;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			//cout << i << ' ' << j << '\n';
			if ((!(fence_sides[i].x1 == fence_sides[j].x1 and fence_sides[i].y1 == fence_sides[j].y1) and
				!(fence_sides[i].x2 == fence_sides[j].x2 and fence_sides[i].y2 == fence_sides[j].y2) and
				!(fence_sides[i].x1 == fence_sides[j].x2 and fence_sides[i].y1 == fence_sides[j].y2) and
				!(fence_sides[i].x2 == fence_sides[j].x1 and fence_sides[i].y2 == fence_sides[j].y1)) and
				intersect(fence_sides[i], fence_sides[j])) {
				//cout << fence_sides[i].x1 << ' ' << fence_sides[i].y1 << '\n';
				//cout << fence_sides[j].x1 << ' ' << fence_sides[j].y1 << '\n';
				cout << "NOFENCE\n";
				return 0;
			}
		}
	}
	
	srand(time(NULL));
	int a = rand() % 2;
	int denom = (a == 0 ? 42000 : 20000);
	for (double angle = start; angle < end; angle += 2 * pi / denom) {
		double mag_l = 0; double mag_r = most_dist;
		while (mag_r - mag_l > 1e-4) {
			double mag = (mag_r + mag_l) / 2;
			if (intersects_with_fence({ x, y, x + mag * cos(angle), y + mag * sin(angle) }) != -1) {
				mag_r = mag;
			}
			else {
				mag_l = mag;
			}
		}
		//cout << cos(angle) << ' ' << sin(angle) << ' ' << angle << '\n';
		int idx = final_intersect({ x,y,x + mag_r * cos(angle),y + mag_r * sin(angle) });
		//cout << mag_r << '\n';
		if (idx != -1) {
			visible[idx] = 1;
		}
	}
	//cout << double(clock() - startt) / CLOCKS_PER_SEC << '\n';
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