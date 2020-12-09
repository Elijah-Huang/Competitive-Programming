struct segment {
	double x1, y1, x2, y2;
};

vector<segment> fence_sides;

bool intersect(segment& a, segment& b, double error = 1e-7) {

	//setup x1, y1 as startpoint(leftmost endpoint)
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
	if (abs(a.x1 - a.x2) < error and abs(b.x1 - b.x2) < error) {
		return abs(a.x1 - b.x1) < error and !(min(a.y1, a.y2) > max(b.y1, b.y2) or min(b.y1, b.y2) > max(a.y1, a.y2));
	}

	// making start points equal
	double a_extra = 0, b_extra = 0;
	double x_start = a.x1;
	if (a.x1 < b.x1) {
		a_extra = (a.y2 - a.y1) / (a.x2 - a.x1) * (b.x1 - a.x1);
		x_start = b.x1;
	}
	else if (b.x1 < a.x1) {
		b_extra = (b.y2 - b.y1) / (b.x2 - b.x1) * (a.x1 - b.x1);
		x_start = a.x1;
	}

	// one vertical line
	if (abs(a.x1 - a.x2) < error) {
		return max(a.y1, a.y2) >= b.y1 + b_extra - error and b.y1 + b_extra + error >= min(a.y1, a.y2);
	}
	else if (abs(b.x1 - b.x2) < error) {
		return max(b.y1, b.y2) >= a.y1 + a_extra - error and a.y1 + a_extra + error >= min(b.y1, b.y2);
	}

	//edgecase of same starting point for x_start
	if (abs(a.y1 + a_extra - (b.y1 + b_extra)) < error) {
		return true;
	}

	// both are diagonals or horizontal
	double m1 = (a.y2 - a.y1) / (a.x2 - a.x1);
	double m2 = (b.y2 - b.y1) / (b.x2 - b.x1);
	if (a.y1 + a_extra > b.y1 + b_extra) {
		return a.y1 + a_extra - (b.y1 + b_extra) - error <= (m2 - m1) * (min(a.x2, b.x2) - x_start);
	}
	else {
		return b.y1 + b_extra - (a.y1 + a_extra) - error <= (m1 - m2) * (min(a.x2, b.x2) - x_start);
	}
}