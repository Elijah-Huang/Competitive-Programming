#include<bits/stdc++.h>
using namespace std;

struct cow{
	int x, y;
	char t;
};

int n;
const int maxn = 501;
int grid[2][maxn][maxn];
int compress[2][1001], expand[2][501];
cow cows[maxn];
vector<int> x_coords, y_coords;
int max_h = 0, min_area = 1 << 30;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("cowrect.in", "r", stdin); freopen("cowrect.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cows[i].x >> cows[i].y >> cows[i].t;
		x_coords.push_back(cows[i].x);
		y_coords.push_back(cows[i].y);
	}

	sort(x_coords.begin(), x_coords.end());
	sort(y_coords.begin(), y_coords.end());
	x_coords.resize(unique(x_coords.begin(), x_coords.end())-x_coords.begin());
	y_coords.resize(unique(y_coords.begin(), y_coords.end())-y_coords.begin());
	
	for (int i = 0; i < x_coords.size(); i++) {
		compress[0][x_coords[i]] = i;
		expand[0][i] = x_coords[i];
	}

	for (int i = 0; i < y_coords.size(); i++) {
		compress[1][y_coords[i]] = i;
		expand[1][i] = y_coords[i];
	}

	for (int i = 0; i < n; i++) {
		if (cows[i].t == 'H') {
			grid[0][compress[1][cows[i].y]][compress[0][cows[i].x]] = 1;
		}
		else {
			grid[1][compress[1][cows[i].y]][compress[0][cows[i].x]] = 1;
		}
	}

	for (int j = 0; j < x_coords.size(); j++) {
		vector<int> a(y_coords.size());
		
		for (int j2 = j; j2 < x_coords.size(); j2++) {
			for (int i = 0; i < y_coords.size(); i++) {
				a[i] = (a[i] != -1 and grid[1][i][j2] == 0 ? a[i] + grid[0][i][j2] : -1);
			}

			int start = 0, tot = 0;
			for (int i = 0; i < y_coords.size(); i++) {
				if (a[i] == -1) {
					tot = 0;
				}
				else {
					if (tot == 0) {
						start = i;
					}
					tot += a[i];
				}

				if (tot != 0) {
					if (max_h < tot) {
						max_h = tot;
						min_area = (expand[0][j2] - expand[0][j]) * (expand[1][i] - expand[1][start]);
					}
					else if (max_h == tot) {
						min_area = min(min_area, (expand[0][j2] - expand[0][j]) * (expand[1][i] - expand[1][start]));
					}
				}
			}
		}
	}

	cout << max_h << '\n' << min_area;
}