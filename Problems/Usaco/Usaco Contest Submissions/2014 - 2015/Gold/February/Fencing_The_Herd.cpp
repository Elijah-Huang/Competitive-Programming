// O( (n+Q1/2)*logn * Q1/(block_size) + Q2*(log(n) + block_size/2) ) -> (assume Q1==Q2) min = 1.13e8 at x = 2258
// The actual best block size is about 6400 (500 ms) because recomputing the convex hull has decent constant factor
// Somewhat humorously, because of weak test data as long as the initial points are put in a hull, 
// not recomputing the hull takes 1150 ms (ofc worst case is (q/2)^2 which is tle)
#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-10;

struct point {
	long long x, y;
};

int n, q;
vector<point> points;
vector<point> buffer_points;
vector<point>& c_hull = points;
// process queries in ~ sqrt(n) blocks -> don't have to reupdate the convex hull but runtime is ~ n^3/2
int b_sz = 6400;
long long a, b, c;

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

// reorders points in counterclockwise order relative to bot_left point (bot_left point is first) O(nlogn)
void reorder(vector<point>& points) {
	// make bottom left point first point
	swap(points[0], *min_element(points.begin(), points.end(),
		[&](point& a, point& b) {return a.y < b.y or a.y == b.y and a.x < b.x; }));

	// sort counterclockwise so that points with same cos are processed in correct order -> increasing x 
	sort(points.begin() + 1, points.end(),
		[&](point& a, point& b) {long long x = x_prod(a, b, points[0]); return x > 0 ? 1 : x == 0 and a.x < b.x; });
}

// graham scan O(n)
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

// 1 if point is above 2 if on 0 if below (line a*x + b*y = c) 
// note that greater dot product might mean below the line and we are only comparing dot products
// it's easier to think about it as above or below the line though and this is fine since 
// if smaller dot product means above the line, larger dot product means below the line too (everything is flipped)
int point_test(point& p) {
	long long c2 = a * p.x + b * p.y;

	if (c2 > c) {
		return 1;
	}
	else if (c2 == c) {
		return 2;
	}
	else {
		return 0;
	}
}

// see if max or min y intercept of the line going through a point in the hull is above or below line
// note that this different from the dot product of a vector (x,y) with (a,b) (max intercept might = min dot product due to signs)
int find_y(vector<point>& c_hull, bool mn, bool pr = 0) {
	// the idea is that the sides of the polygon rotate 360 degrees and the angle of segment c_hull[i]->c_hull[i+1] 
	// can be interpreted as a displacement from c_hull[i] that changes the y intercept based on it's angle with line y
	// Let's compare the y intercept of the line that goes
	// through point c_hull[i] and point c_hull[i+1]. 
	// Assume that c_hull[i] is the origin and y is the line that passes through it
	// We know that the y intercept of c_hull[i+1] is >= c_hull[i] if
	// the point c_hull[i+1] lies above the line y
	// this means that the angle going counterclockwise from line y to segment c_hull[i]->c_hull[i+1] is <= 180 degrees
	// The cross product is thus positive
	// Using this logic, the segments that increase the y intercept when going from point i to i+1 make a contiguous segment
	// so we can binary search on the final of these segments and thus find the point with greatest y intercept in log(n)
	// note: although there can be segs that decrease the y intercept at the beginning and end (going ccw around the c_hull)
	// the cross product of the first seg with the seg is >= 0 at the beg and < 0 at the end (so we can differentiate)
	// there can also be increasing segs before the beginning and after the beginning, but again we can casework

	int n = c_hull.size() - 1;
	point y = { b,-a }; // seg on line y
	if (b < 0) {
		y.x = -y.x;
		y.y = -y.y;
	}

	// this is to handle the dec consecutive at beginning and lump it into the inc consecutive so we can bin search
	// also to handle the inc consecutive from beg and before beg via removing the inc consecutive before beg
	// (binary search can end up at c_hull.size()-1 when it should be at the end of the inc consecutive from beg)
	y.x += c_hull[n].x, y.y += c_hull[n].y;
	bool dec_consecutive_at_begin = mn ^ sgn(x_prod(c_hull[0], y, c_hull[n]));
	y.x -= c_hull[n].x, y.y -= c_hull[n].y;
	
	int l = 0, r = n;
	while (l != r) {
		int m = (l + r + 1) / 2;
		int m_prev = m == 0 ? n : m - 1;
		point y_scaled = { y.x + c_hull[m_prev].x, y.y + c_hull[m_prev].y };
		point m_scaled = { c_hull[m].x - c_hull[m_prev].x + c_hull[n].x, c_hull[m].y - c_hull[m_prev].y + c_hull[n].y};
		long long prod;
		// if current seg m_prev->m is within 180 degress of seg n->0 (going ccw from n->0)
		bool within_180 = ((prod = x_prod(c_hull[0], m_scaled, c_hull[n])) > 0 ? 1 :
			// use dot product to see if they make the same angle relative to the x axis
			prod == 0 and (c_hull[m].x - c_hull[m_prev].x) * (c_hull[0].x - c_hull[n].x) + (c_hull[m].y - c_hull[m_prev].y) * (c_hull[0].y - c_hull[n].y) > 0);

		if ((mn^sgn(x_prod(y_scaled,c_hull[m],c_hull[m_prev])) 
			// handle increasing at beginning case
			and (dec_consecutive_at_begin or within_180))
			// handle decreasing at beginning case
			or (dec_consecutive_at_begin and within_180)) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}

	return point_test(c_hull[l]);
}

//2 if line intersects hull else 1 if hull is above and 0 if below
int hull_test(vector<point>& c_hull) {
	int a, b;
	if (c_hull.size() > 2) {
		a = find_y(c_hull, 0), b = find_y(c_hull, 1);
	}
	else {
		a = point_test(c_hull[0]), b = point_test(c_hull.back());
	}

	if (a == b and a != 2) {
		return a;
	}
	else {
		return 2;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
	
	cin >> n >> q;
	
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		points.push_back({ a,b });
	}
	c_hull = generate_c_hull(points);


	while(q--) {
		// recompute hull
		if (buffer_points.size() == b_sz) {
			points.insert(points.end(), buffer_points.begin(), buffer_points.end());
			buffer_points.clear();
			c_hull = generate_c_hull(points);
		}

		int t; cin >> t;

		if (t == 1) {
			int x, y; cin >> x >> y;
			buffer_points.push_back({ x,y });
		}
		else {
			cin >> a >> b >> c;

			int above = hull_test(c_hull);
			for (int i = 0; i < buffer_points.size() and above != 2; i++) {
				if (above != point_test(buffer_points[i])) {
					above = 2;
				}
			}

			if (above != 2) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
			
		}
	}
}