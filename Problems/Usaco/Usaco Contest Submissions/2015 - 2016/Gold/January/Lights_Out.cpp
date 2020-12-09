#include<bits/stdc++.h>
using namespace std;

struct point {
	int x, y;

	bool operator ==(const point& b) const {
		return x == b.x and y == b.y;
	}

	int operator -(const point& b) const {
		return abs(x - b.x) + abs(y - b.y);
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("lightsout.in", "r", stdin); freopen("lightsout.out", "w", stdout);
	int n; cin >> n;
	vector<point> points(n);
	vector<bool>  degree(n);
	vector<int> left_shortest(n + 1);
	vector<int> right_shortest(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	}
	points.push_back(points[0]);

	int length = 0;
	for (int i = 1; i <= n; i++) {
		length += points[i] - points[i - 1];
		left_shortest[i] = length;
	}
	length = 0;
	for (int i = n - 1; i >= 0; i--) {
		length += points[i] - points[i + 1];
		right_shortest[i] = length;
	}

	for (int i = 1; i < n; i++) {
		int x1 = points[i].x - points[i - 1].x;
		int y1 = points[i].y - points[i - 1].y;
		int x2 = points[i + 1].x - points[i].x;
		int y2 = points[i + 1].y - points[i].y;
		if (x1 * y2 - x2 * y1 > 0) {
			degree[i] = 1;
		}
	}

	multiset<vector<int>> paths;
	int w_270 = 1e6;
	for (int i = 1; i < n; i++) {
		vector<int> path = { degree[i]*w_270 };
		paths.insert(path);
		for (int j = i + 1; j < n; j++) {
			path.push_back(points[j] - points[j - 1] + degree[j]*w_270);
			paths.insert(path);
		}
	}

	int mx_change = 0;
	for (int i = 1; i < n; i++) {
		vector<int> path = { degree[i] * w_270 };
		int j = i + 1;
		while (true) {
			auto range = paths.equal_range(path);
			--range.second;
			if (range.first == range.second) {
				j--;
				break;
			}
			else if (j == n) {
				break;
			}
			else {
				path.push_back(points[j] - points[j - 1] + degree[j] * w_270);
				j++;
			}
		}
		
		mx_change = max(mx_change, (left_shortest[j] - left_shortest[i] + min(left_shortest[j], right_shortest[j])
			- min(left_shortest[i], right_shortest[i])));
	}

	cout << mx_change;
}