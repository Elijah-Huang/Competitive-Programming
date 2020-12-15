#include<bits/stdc++.h>
using namespace std;

// change all long long to double for real value coordinates

const double eps = 1e-7;

struct point {
	long long x, y;
	double cos;
};

// c->a cross c->b 
long long x_prod(point& a, point& b, point& c) {
	return ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y));
}

bool sgn(long long val) {
	if (abs(val) < eps) {
		return 1;
	}
	else {
		return val > 0;
	}
}

bool cmp(point& a, point& b) {
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

		while (c_hull.size() >= 2 and !sgn(x_prod(points[i], c_hull[c_hull.size() - 2], c_hull[c_hull.size() - 1]))) {
				c_hull.pop_back();
			}
		c_hull.push_back(points[i]);
	}

	return c_hull;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("curling.in", "r", stdin); freopen("curling.out", "w", stdout);
}