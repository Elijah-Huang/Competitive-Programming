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

bool point_in_polygon(vector<point>& points, point& a) {
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

	return (abs(x_prod(points[l], points[l + 1], points[0])) -
		abs(x_prod(points[0], points[l], a)) +
		abs(x_prod(points[l], points[l + 1], a)) +
		abs(x_prod(points[l + 1], points[0], a))) < sqrt(eps);
}