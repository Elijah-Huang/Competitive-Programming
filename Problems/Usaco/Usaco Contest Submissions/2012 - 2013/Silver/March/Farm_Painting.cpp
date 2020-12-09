#include<bits/stdc++.h>
using namespace std;

struct rectangle {
	int x1, y1, x2, y2;
};

struct rectangle_cmp {
	bool operator()(const rectangle& a,const rectangle& b) const {
		return a.y1 < b.y1;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("painting.in", "r", stdin); freopen("painting.out", "w", stdout);
	int n, total_uncontained = 0;
	cin >> n;
	vector<rectangle> rectangles;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		rectangles.push_back({ x1,y1,x2,y2 });
		rectangles.push_back({ x2,y1,x1,y2 });
	}
	sort(rectangles.begin(), rectangles.end(),
		[&](const rectangle& a, const rectangle& b) {return a.x1 < b.x1; });
	set<rectangle, rectangle_cmp> uncontained;

	for (int i = 0; i < 2*n; i++) {
		rectangle curr = rectangles[i];
		rectangle reverse = { curr.x2,curr.y1, curr.x1, curr.y2 };
		if (uncontained.count(reverse)) {
			uncontained.erase(reverse);
		}
		else if (curr.x1 < curr.x2) {
			auto loc = uncontained.lower_bound(curr);
			if (loc == uncontained.begin()) {
				uncontained.insert(curr);
				total_uncontained++;
			}
			else {
				loc--;
				if (curr.y2 > (*loc).y2) {
					uncontained.insert(curr);
					total_uncontained++;
				}
			}
		}
	}

	cout << total_uncontained;
}