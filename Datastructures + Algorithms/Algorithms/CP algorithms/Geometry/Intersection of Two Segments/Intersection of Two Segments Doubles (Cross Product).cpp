struct segment {
	double x1, y1, x2, y2;
};

bool sign(double val) {
	return (val <= 0 ? 0 : 1);
}

bool intersect(segment& a, segment& b, double error = 1e-7) {
	// segments are on the same line, check for intersection of 2 segments along a common line
	if (abs((a.x2 - a.x1) * (b.y1 - a.y1) - (b.x1 - a.x1) * (a.y2 - a.y1)) < error and
		abs((a.x2 - a.x1) * (b.y2 - a.y1) - (b.x2 - a.x1) * (a.y2 - a.y1)) < error) {
		return min(a.x1, a.x2) - error <= max(b.x1, b.x2) and max(a.x1, a.x2) + error >= min(b.x1, b.x2);
	}
	// for each segment, check if the points are on opposite sides of the other segment
	// if this is true for both segments then they intersect
	else {
		return (sign((a.x1 - b.x1) * (b.y2 - b.y1) - (b.x2 - b.x1) * (a.y1 - b.y1)) !=
			sign((a.x2 - b.x1) * (b.y2 - b.y1) - (b.x2 - b.x1) * (a.y2 - b.y1)) and
			sign((b.x1 - a.x1) * (a.y2 - a.y1) - (a.x2 - a.x1) * (b.y1 - a.y1)) !=
			sign((b.x2 - a.x1) * (a.y2 - a.y1) - (a.x2 - a.x1) * (b.y2 - a.y1)));
	}
}