#include<bits/stdc++.h>
using namespace std;

// change all long long to double for real value coordinates

const double eps = 1e-10;

struct point {
	long long x, y;
};

// c->a X c->b
long long x_prod(point& a, point& b, point& c) {
	return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
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

// graham scan O(nlogn)
vector<point> generate_c_hull(vector<point>& points) {
	reorder(points);

	vector<point> c_hull{ points[0] };
	for (int i = 1; i < points.size(); i++) {
		// after sort repeated points are adjacent
		if (points[i].x == points[i - 1].x and points[i].y == points[i - 1].y) {
			continue;
		}

		// if you have to turn clockwise to add point i, remove the previous point
		while (c_hull.size() >= 2 and !sgn(x_prod(points[i], c_hull[c_hull.size() - 2], c_hull.back()))) {
			c_hull.pop_back();
		}

		c_hull.push_back(points[i]);
	}

	return c_hull;
}

vector<point> points, c_hull;
long long totx = 0, toty = 0;
long double cenx, ceny;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int n; cin >> n;
	points.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
		totx += points[i].x;
		toty += points[i].y;
	}

	cenx = totx / (long double)(n);
	ceny = toty / (long double)(n);

	cout << cenx << '\n';
	cout << ceny << '\n';
}