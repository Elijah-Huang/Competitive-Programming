// O(n*log(bounds^2))
#include<bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
};

const int maxn = 1e5;
int n;
point points[maxn];
bool neg_y = 0, pos_y = 0, zero_y = 0;

bool test(double r) {
	double left = -1e7, right = 1e7;
	for (int i = 0; i < n; i++) {
		double y = abs(r - points[i].y);
		if (r < y) {
			return 0;
		}
		double x = sqrt(r - y) * sqrt(r + y);
		double curr_left = points[i].x - x;
		double curr_right = points[i].x + x;

		left = max(left, curr_left);
		right = min(right, curr_right);
		if (left > right) {
			return 0;
		}
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(15);

	cin >> n;

	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;

		if (y == 0) {
			zero_y = 1;
		}
		if (y > 0) {
			pos_y = 1;
		}
		if (y < 0) {
			neg_y = 1;
		}

		points[i] = { x,y };
	}

	if (zero_y) {
		if (n == 1) {
			cout << 0;
		}
		else {
			cout << -1;
		}
	}
	else if (neg_y & pos_y) {
		cout << -1;
	}
	else {
		if (neg_y) {
			for (int i = 0; i < n; i++) {
				points[i].y *= -1;
			}
		}

		double l = 0, r = 2e14 + 1;
		for (int i = 0; i < 100; i++) {
			double m = (l + r) / 2;
			if (test(m)) {
				r = m;
			}
			else {
				l = m;
			}
		}

		cout << (l + r) / 2;
	}
}