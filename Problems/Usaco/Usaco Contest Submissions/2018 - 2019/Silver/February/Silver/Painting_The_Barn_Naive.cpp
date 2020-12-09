#include <bits/stdc++.h>
using namespace std;
struct point {
	int x1, y1, x2, y2;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k, layers[1001][1001]{};
	freopen("paintbarn.in", "r", stdin); freopen("paintbarn.out", "w", stdout);
	cin >> n >> k;
	vector<point> points(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].x1 >> points[i].y1 >> points[i].x2 >> points[i].y2;
		points[i].y2--; points[i].x2--;
	}
	for (auto p : points) {
		for (int x = p.x1; x <= p.x2; x++) {
			for (int y = p.y1; y <= p.y2; y++) {
				layers[x][y]++;
			}
		}
	}
	int k_layers = 0;
	for (int x = 0; x <= 1000; x++) {
		for (int y = 0; y <= 1000; y++) {
			k_layers += (layers[x][y] == k);
		}
	}
	cout << k_layers;
}