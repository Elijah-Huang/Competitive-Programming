struct segment {
	double x1, y1, x2, y2;
};

bool sign(double val) {
	return (val <= 0 ? 0 : 1);
}

bool intersect(segment& a, segment& b, double error = 1e-7) {
	if (abs((a.x2 - a.x1) * (b.y1 - a.y1) - (b.x1 - a.x1) * (a.y2 - a.y1)) < error and
		abs((a.x2 - a.x1) * (b.y2 - a.y1) - (b.x2 - a.x1) * (a.y2 - a.y1)) < error) {
		return min(a.x1, a.x2) - error <= max(b.x1, b.x2) and max(a.x1, a.x2) + error >= min(b.x1, b.x2);
	}
	else if (abs((a.x2 - a.x1) * (b.y1 - a.y1) - (b.x1 - a.x1) * (a.y2 - a.y1)) < error
		and min(a.x1, a.x2) <= b.x1 + error and b.x1 - error <= max(a.x1, a.x2) or
		abs((a.x2 - a.x1) * (b.y2 - a.y1) - (b.x2 - a.x1) * (a.y2 - a.y1)) < error
		and min(a.x1, a.x2) <= b.x2 + error and b.x2 - error <= max(a.x1, a.x2)) {
		return true;
	}
	else {
		return (sign((a.x1 - b.x1) * (b.y2 - b.y1) - (b.x2 - b.x1) * (a.y1 - b.y1)) !=
			sign((a.x2 - b.x1) * (b.y2 - b.y1) - (b.x2 - b.x1) * (a.y2 - b.y1)) and
			sign((b.x1 - a.x1) * (a.y2 - a.y1) - (a.x2 - a.x1) * (b.y1 - a.y1)) !=
			sign((b.x2 - a.x1) * (a.y2 - a.y1) - (a.x2 - a.x1) * (b.y2 - a.y1)));
	}
}