// O(n*log^2(bounds)) Not enough time to get enough precision
#include<bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
};

const int maxn = 1e5;
int n;
point points[maxn];
bool neg_y = 0, pos_y = 0, zero_y = 0;
double max_x = -1e7, min_x = 1e7, max_y = -1e7;
double max_r = 0;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(15);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;

		min_x = min(min_x, x);
		max_x = max(max_x, x);
		max_y = max(max_y, y);

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
		
		max_r = max(max_x - min_x, max_y);
		// more like 1/2 of this, but just to be safe
		max_r = max_r * max_r;

		// find min radius for given x -> check_if_r_works(r) is a monotonous function
		auto min_radius = [&](double x_coord, int max_iters = 40) {
			double lr = 0, rr = max_r;
			
			for (int iters = 0; iters < max_iters; iters++) {
				double mr = (lr + rr) / 2;
				
				bool worked = 1;
				for (int i = 0; i < n; i++)	{

					double x = abs(x_coord - points[i].x), y = abs(mr - points[i].y);
					if (mr<y or sqrt(mr-y)*sqrt(mr+y)<x) {
						worked = 0;
						break;
					}
				}

				if (worked) {
					rr = mr;
				}
				else {
					lr = mr;
				}
			}

			return (lr + rr) / 2;
		};

		// find best x coord -> min_radius(x) is a unimodal function
		double lx = min_x, rx = max_y;
		for (int iters = 0; iters < 40; iters++) {
			double dx = (rx - lx) / 10;
			double mx = (rx + lx) / 2;
			//cout << lx << ' ' << rx << '\n';
			if (min_radius(mx) > min_radius(mx + dx)) {
				lx = mx;
			}
			else {
				rx = mx + dx;
			}
		}

		cout << min_radius((rx + lx) / 2, 60);
	}
}