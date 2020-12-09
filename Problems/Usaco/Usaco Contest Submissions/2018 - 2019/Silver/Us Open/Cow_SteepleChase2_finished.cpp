#include<bits/stdc++.h>
using namespace std;
int x;

struct segment {
	long long x1, y1, x2, y2, idx;
	bool operator==(const segment& b) const {
		return idx == b.idx;
	}
};

struct seg_cmp {
	bool operator()(const segment& a, const segment& b) const {
		double first = (a.y1 + (x - a.x1) * (a.x1 != a.x2 ? double(a.y2 - a.y1) / (a.x2 - a.x1) : 0));
		double second = (b.y1 + (x - b.x1) * (b.x1 != b.x2 ? double(b.y2 - b.y1) / (b.x2 - b.x1) : 0));
		return (first == second ? !(a == b) : first < second);
	}
};

bool intersect(segment a, segment b) {
	if (b.x2 < a.x1 or a.x2 < b.x1) {
		return false;
	}
	if (a.x1 == a.x2 and b.x1 == b.x2) {
		return a.x1 == b.x1 and (!(min(a.y1, a.y2) > max(b.y1, b.y2) or min(b.y1, b.y2) > max(a.y1, a.y2)));
	}
	if (a.x1 < b.x1) {
		a.y1 += double(a.y2 - a.y1) / (a.x2 - a.x1) * (b.x1 - a.x1);
		a.x1 = b.x1;
	}
	else if (b.x1 < a.x1) {
		b.y1 += double(b.y2 - b.y1) / (b.x2 - b.x1) * (a.x1 - b.x1);
		b.x1 = a.x1;
	}
	if (a.x1 == a.x2) {
		return a.y1 >= b.y1 and b.y1 >= a.y2;
	}
	else if (b.x1 == b.x2) {
		return b.y1 >= a.y1 and a.y1 >= b.y2;
	}
	if (a.y1 < b.y1) {
		swap(a, b);
	}
	double m1 = (double(a.y2 - a.y1) / (a.x2 - a.x1));
	double m2 = (double(b.y2 - b.y1) / (b.x2 - b.x1));
	return (a.y1 - b.y1 <= (m2 - m1) * (min(a.x2, b.x2) - a.x1));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowjump.in", "r", stdin); freopen("cowjump.out", "w", stdout);
	int n;
	cin >> n;
	vector<segment> segments;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		segments.push_back({ x1,y1,x2,y2,i + 1 });
		segments.push_back({ x2,y2,x1,y1,i + 1 });
	}
	sort(segments.begin(), segments.end(),
		[&](const segment& a, const segment& b) {if (a.x1 == b.x1) return a.y1 > b.y1;
	return a.x1 < b.x1; });
	pair<segment, segment> possible;
	set<segment, seg_cmp> intersectable;
	for (int i = 0; i < 2 * n; i++) {
		segment& curr = segments[i];
		x = curr.x1;
		if (intersectable.count(segment{ curr.x2, curr.y2, curr.x1, curr.y1, curr.idx })) {
			auto to_remove = intersectable.find(segment{ curr.x2, curr.y2, curr.x1, curr.y1, curr.idx });
			auto below = to_remove;
			auto above = to_remove; above++;
			if (below != intersectable.begin() and above != intersectable.end()) {
				below--;
				if (intersect(*below, *above)) {
					possible.first = *below;
					possible.second = *above;
					break;
				}
			}
			intersectable.erase(to_remove);
		}
		else {
			intersectable.insert(curr);
			auto loc = intersectable.find(curr);
			auto below = loc;
			auto above = loc; above++;
			if (below != intersectable.begin()) {
				below--;
				if (intersect(*loc, *below)) {
					possible.first = *loc;
					possible.second = *below;
					break;
				}
			}
			if (above != intersectable.end()) {
				if (intersect(*loc, *above)) {
					possible.first = *loc;
					possible.second = *above;
					break;
				}
			}
		}
	}
	int intersection1 = 0, intersection2 = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (segments[i].x1 < segments[i].x2) {
			intersection1 += intersect(possible.first, segments[i]);
			intersection2 += intersect(possible.second, segments[i]);
		}
	}
	if (intersection1 == intersection2) {
		cout << min(possible.first.idx, possible.second.idx);
	}
	else if (intersection1 > intersection2) {
		cout << possible.first.idx;
	}
	else {
		cout << possible.second.idx;
	}
}