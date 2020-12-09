#include<bits/stdc++.h>
using namespace std;

struct point {
	int x, y, idxi;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("balancing.in", "r", stdin); freopen("balancing.out", "w", stdout);
	int n;
	cin >> n;
	int farm[1001][1001]{};
	vector<point> points;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back(point{ x,y });
	}
	sort(points.begin(), points.end(), [&](const point& a, const point& b) {return a.x < b.x; });
	for (int i = 0; i < n; i++) {
		points[i].idxi = i+1;
		int prev_i = i+1;
		while (i < n-1 and points[i].x == points[i + 1].x) {
			i++;
			points[i].idxi = prev_i;
		}
	}
	sort(points.begin(), points.end(), [&](const point& a, const point& b) {return a.y < b.y; });
	for (int j = 0; j < n; j++) {
		int prev_j = j+1;
		farm[points[j].idxi][prev_j] = 1;
		while (j < n-1 and points[j].y == points[j + 1].y) {
			j++;
			farm[points[j].idxi][prev_j] = 1;
		}
	}
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			farm[i][j] += farm[i - 1][j] + farm[i][j - 1] - farm[i - 1][j - 1];
		}
	}
	int min_M = 1000;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			int quad1 = farm[i][j];
			int quad2 = farm[1000][j] - quad1;
			int quad3 = farm[i][1000] - quad1;
			int quad4 = n - quad1 - quad2 - quad3;
			min_M = min(min_M, max({ quad1,quad2,quad3,quad4 }));
		}
	}
	cout << min_M;
}