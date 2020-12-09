struct point {
	double x, y, cos;
};
double x_prod(point& a, point& b, point& c) {
	return ((c.x - b.x) * (a.y - b.y) - (a.x - b.x) * (c.y - b.y));
}
bool cmp(point& a, point& b) {
	// points with the same angle need to be processed in a certain order
	if (fabs(a.cos - b.cos) < 1e-7) {
		return a.x < b.x;
	}
	else {
		return a.cos > b.cos;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<point> points;
	vector<point> c_hull;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		points.push_back(point{ x,y });
	}
	if (n <= 3 and n > 0) {
		c_hull = points;
	}
	else {
		int lowest = 1 << 30;
		point leftmost;
		for (point p : points) {
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
				p.cos = -2;
			}
			else {
				p.cos = ((p.x - leftmost.x) / sqrt((p.x - leftmost.x) * (p.x - leftmost.x)
					+ (p.y - leftmost.y) * (p.y - leftmost.y)));
			}
		}
		sort(points.begin(), points.end(), cmp);

		// convex hull creation

		c_hull = { points[points.size() - 1], points[0] };
		for (int i = 1; i < points.size(); i++) {
			// after sort repeated points are adjacent
			if (points[i].x == c_hull[c_hull.size() - 1].x and
				points[i].y == c_hull[c_hull.size() - 1].y) {
				continue;
			}
			while (c_hull.size() >= 2 and
				x_prod(c_hull[c_hull.size() - 2], c_hull[c_hull.size() - 1], points[i]) < 0) {
				c_hull.pop_back();
			}
			c_hull.push_back(points[i]);
		}
		c_hull.pop_back();
	}
}