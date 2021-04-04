#include<bits/stdc++.h>
using namespace std;

// change all long long to double for real value coordinates

const double eps = 1e-10;

struct point {
	long long x, y;
};

// c->a cross c->b 
long long x_prod(point& a, point& b, point& c) {
	return ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y));
}

// return 0 if a < 0 else 1
bool sgn(long long a) {
	if (abs(a) < sqrt(eps)) {
		return 1;
	}
	return a > 0;
}

/* reorders points so that the first is the bottom left most, and the rest are sorted by ccw angle with the first point as the origin
O(nlogn) */
void reorder(vector<point>& points) {
	// make bottom left point first point
	swap(points[0], *min_element(points.begin(), points.end(),
		[&](point& a, point& b) {return a.y < b.y or a.y == b.y and a.x < b.x; }));

	// sort counterclockwise so that points with same cos are processed in correct order -> increasing x 
	sort(points.begin() + 1, points.end(),
		[&](point& a, point& b) {long long x = x_prod(a, b, points[0]); return x > 0 ? 1 : x == 0 and a.x < b.x; });
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