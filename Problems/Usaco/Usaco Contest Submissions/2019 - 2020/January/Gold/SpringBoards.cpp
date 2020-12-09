#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

struct new_point {
	int y, amt;
};

struct point {
	int x1, y1, x2, y2;
};

int bit[(int)2e5 + 1];
map<int,vector<new_point>> to_add;
vector<point> points;
vector<int> y_coord;
unordered_map<int, int> y_to_idx;

int mx(int idx) {
	int res = 0;
	for (idx++; idx > 0; idx -= idx & -idx) {
		res = max(res, bit[idx]);
	}
	return res;
}

void update(int idx, int amt) {
	for (idx++; idx < 2e5 + 1; idx += idx & -idx) {
		bit[idx] = max(bit[idx], amt);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("boards.in", "r", stdin); freopen("boards.out", "w", stdout);
	int n, p; cin >> n >> p;
	points.resize(p);
	for (int i = 0; i < p; i++) {
		cin >> points[i].x1 >> points[i].y1 >> points[i].x2 >> points[i].y2;
		y_coord.push_back(points[i].y1), y_coord.push_back(points[i].y2);
	}

	sort(points.begin(), points.end(),
		[&](const point& a, const point& b) {if (a.x1 == b.x1) return a.y1 < b.y1; return a.x1 < b.x1; });
	sort(y_coord.begin(), y_coord.end());
	
	int idx = 0;
	for (int i = 0; i < y_coord.size();) {
		int curr = y_coord[i];
		y_to_idx[curr] = idx++;
		while (i < y_coord.size() and curr == y_coord[i]) {
			i++;
		}
	}

	int best = 0;
	for (int i = 0; i < p; i++) {
		while (!to_add.empty() and to_add.begin()->first <= points[i].x1) {
			for (auto p : to_add.begin()->second) {
				update(y_to_idx[p.y], p.amt);
			}
			to_add.erase(to_add.begin());
		}
		int change = points[i].x2 - points[i].x1 + points[i].y2 - points[i].y1;
		change += mx(y_to_idx[points[i].y1]);
		best = max(best, change);
		to_add[points[i].x2].push_back({ points[i].y2,change });
	}

	cout << 2 * n - best;
}