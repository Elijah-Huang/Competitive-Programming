/*ID: elijahj1
TASK: fence3
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

struct fence{
	int x1, y1, x2, y2;
	int a, b, c;

	fence(int x, int y, int xx, int yy) {
		x1 = x;
		y1 = y;
		x2 = xx;
		y2 = yy;
		a = y2 - y1;
		b = -(x2 - x1);
		c = y1 * (x2 - x1) - x1 * (y2 - y1);
	}

	double dist(double x0, double y0) {
		// not a line
		if (x1 == x2 and y1 == y2) {
			return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
		}
		// dot prod < 0 means line from point to one endpoint of the fence 
		// makes angle > 90 degrees with the fence
		if ((x2 - x1) * (x0 - x1) + (y2 - y1) * (y0 - y1) < 0){
			return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
		}
		else if ((x1 - x2) * (x0 - x2) + (y1 - y2) * (y0 - y2) < 0) {
			return sqrt((x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2));
		}
		else {
			return abs(a * x0 + b * y0 + c) / sqrt(a * a + b * b);
		}
	}
};

vector<fence> fences;

double check_dist(double x, double y) {
	double total_dist = 0;
	for (auto& fence : fences) {
		total_dist += fence.dist(x, y);
	}
	return total_dist;
}

double min_y(int x) {
	int ly = 0, ry = 1e9;
	while (ly != ry) {
		int m1 = (ry - ly) / 3 + ly;
		int m2 = ry - (ry - ly) / 3;
		if (check_dist(x / 1e7, m1 / 1e7) < check_dist(x / 1e7, m2 / 1e7)) {
			ry = m2 - 1;
		}
		else {
			ly = m1 + 1;
		}
	}

	return ly;
}

int main() {
	cout << fixed << setprecision(1);
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("fence3.in", "r", stdin); freopen("fence3.out", "w", stdout);
	int f; cin >> f;
	for (int i = 0; i < f; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		fences.push_back(fence(x1, y1, x2, y2));
	}

	int lx = 0, rx = 1e9;
	while (lx != rx) {
		int m1 = (rx - lx) / 3 + lx;
		int m2 = rx - (rx - lx) / 3;
		if (check_dist(m1 / 1e7, min_y(m1)/1e7) < check_dist(m2 / 1e7, min_y(m2)/1e7)) {
			rx = m2 - 1;
		}
		else {
			lx = m1 + 1;
		}
	}
	
	 cout << lx/1e7 << ' ' << min_y(lx)/1e7 << ' ' << check_dist(lx/1e7,min_y(lx)/1e7) << '\n';
}