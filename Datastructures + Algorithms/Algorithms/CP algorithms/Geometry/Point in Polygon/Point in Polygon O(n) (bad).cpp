#include<bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
	bool operator==(const point& b) const {
		return b.x == x and b.y == y;
	}
};

struct segment {
	int x1, x2, y1, y2;
};

bool intersect(segment a, segment b) {

	//setup x1,y1 as startpoint(leftmost endpoint)
	if (a.x1 > a.x2) {
		swap(a.x1, a.x2); swap(a.y1, a.y2);
	}
	if (b.x1 > b.x2) {
		swap(b.x1, b.x2); swap(b.y1, b.y2);
	}

	//impossible to intersect?
	if (b.x2 < a.x1 or a.x2 < b.x1) {
		return false;
	}

	// both vertical lines
	if (a.x1 == a.x2 and b.x1 == b.x2) {
		return a.x1 == b.x1 and (!(min(a.y1, a.y2) > max(b.y1, b.y2)
			or min(b.y1, b.y2) > max(a.y1, a.y2)));
	}

	// making start points equal
	if (a.x1 < b.x1) {
		a.y1 += double(a.y2 - a.y1) / (a.x2 - a.x1) * (b.x1 - a.x1);
		a.x1 = b.x1;
	}
	else if (b.x1 < a.x1) {
		b.y1 += double(b.y2 - b.y1) / (b.x2 - b.x1) * (a.x1 - b.x1);
		b.x1 = a.x1;
	}

	// one vertical line
	if (a.x1 == a.x2) {
		return a.y1 >= b.y1 and b.y1 >= a.y2;
	}
	else if (b.x1 == b.x2) {
		return b.y1 >= a.y1 and a.y1 >= b.y2;
	}

	// both are diagonals or horizontal
	if (a.y1 < b.y1) {
		swap(a, b);
	}
	double m1 = (double(a.y2 - a.y1) / (a.x2 - a.x1));
	double m2 = (double(b.y2 - b.y1) / (b.x2 - b.x1));
	return (a.y1 - b.y1 - 1e-8 <= (m2 - m1) * (min(a.x2, b.x2) - a.x1));
}

bool inside_polygon(point& test, vector<point>& polygon) {
	bool ans = 0;
	for (int i = 0; i < polygon.size() - 1; i++) {
		point v1 = polygon[i];
		point v2 = polygon[i + 1];
		// the ray you pick should be (x,y) and (x + 1, max y in prob)
		ans ^= intersect({ v1.x,v2.x,v1.y,v2.y }, { test.x, test.x + 1, test.y, int(1e6) });
	}

	return ans;
}