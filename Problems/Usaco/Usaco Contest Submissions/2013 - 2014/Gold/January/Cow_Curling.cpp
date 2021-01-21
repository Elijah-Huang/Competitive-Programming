#include<bits/stdc++.h>
using namespace std;

// change all long long to double for real value coordinates

const double eps = 1e-10;

struct point {
	long long x, y;
	double cos;
};

// c->a cross c->b 
long long x_prod(point& a, point& b, point& c) {
	return ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y));
}

bool sgn(long long val) {
	if (abs(val) < sqrt(eps)) {
		return 1;
	}
	else {
		return val > 0;
	}
}

bool cmp(const point& a, const point& b) {
	// points with the same angle(cos) need to be processed in a certain order
	if (abs(a.cos - b.cos) < eps) {
		return a.x < b.x;
	}
	else {
		return a.cos > b.cos;
	}
}

/* reorders points so that the first is the bottom left most, and the rest are sorted by 
* counterclockwise angle with the first point as the origin
*/
void reorder(vector<point>& points) {
	point leftmost;

	int lowest = 1 << 30;
	for (point& p : points) {
		if (p.y < lowest) {
			leftmost = p;
			lowest = p.y;
		}
		else if (p.y == lowest) {
			if (p.x < leftmost.x) {
				leftmost = p;
			}
		}
	}

	for (point& p : points) {
		if (p.x == leftmost.x and p.y == leftmost.y) {
			p.cos = 2;
		}
		else {
			long long x = p.x - leftmost.x, y = p.y - leftmost.y;
			p.cos = (x / sqrt(x * x + y * y));
		}
	}

	sort(points.begin(), points.end(), cmp);
}

vector<point> c_hull(vector<point>& points) {
	vector<point> c_hull;

	reorder(points);

	c_hull = { points[0] };
	for (int i = 1; i < points.size(); i++) {
		// after sort repeated points are adjacent
		if (points[i].x == points[i - 1].x and points[i].y == points[i - 1].y) {
			continue;
		}

		while (c_hull.size() >= 2 and (!sgn(x_prod(points[i], c_hull[c_hull.size() - 2], c_hull[c_hull.size() - 1]))
			or x_prod(points[i], c_hull[c_hull.size() - 2], c_hull[c_hull.size() - 1]) == 0)) {
			c_hull.pop_back();
		}
		c_hull.push_back(points[i]);
	}

	return c_hull;
}

bool point_in_polygon(vector<point>& points, point& a) {
	if (points.size() == 2) {
		return x_prod(points[1], a, points[0]) == 0 and points[0].x <= a.x and a.x <= points[1].x and points[0].y <= a.y and a.y <= points[1].y;
	}

	if (!sgn(x_prod(points[1], a, points[0]))) {
		return false;
	}

	int l = 1; int r = points.size() - 2;
	while (l != r) {
		int m = (l + r + 1) / 2;
		if (sgn(x_prod(points[m], a, points[0]))) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	
	return abs(abs(x_prod(points[l], points[l + 1], points[0])) -
		(abs(x_prod(points[0], points[l], a)) +
		abs(x_prod(points[l], points[l + 1], a)) +
		abs(x_prod(points[l + 1], points[0], a)))) < eps;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("curling.in", "r", stdin); freopen("curling.out", "w", stdout);
	int n; cin >> n;

	vector<vector<point>> teams(2, vector<point>(n)), c_hulls(2);
	for (int t = 0; t <= 1; t++) {
		for (int i = 0; i < n; i++) {
			cin >> teams[t][i].x >> teams[t][i].y;
		}

		c_hulls[t] = c_hull(teams[t]);
	}

	for (int t = 0; t <= 1; t++) {
		int ans = 0;
		for (auto& p : teams[t ^ 1]) {
			if (point_in_polygon(c_hulls[t], p)) {
				ans++;
			}
		}

		cout << ans << " \n"[t];
	}
}