#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int t, r, c;
bool grid[maxn][maxn];
int mx[4][maxn][maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int i = 1; i <= t; i++) {
		long long tot = 0;

		cin >> r >> c;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> grid[i][j];
			}
		}

		// left
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (j == 0) {
					mx[0][i][j] = grid[i][j];
				}
				else {
					if (grid[i][j] == 0) {
						mx[0][i][j] = 0;
					}
					else {
						mx[0][i][j] = mx[0][i][j - 1] + 1;
					}
				}
			}
		}

		// up
		for (int j = 0; j < c; j++) {
			for (int i = 0; i < r; i++) {
				if (i == 0) {
					mx[1][i][j] = grid[i][j];
				}
				else {
					if (grid[i][j] == 0) {
						mx[1][i][j] = 0;
					}
					else {
						mx[1][i][j] = mx[1][i - 1][j] + 1;
					}
				}
			}
		}

		// right
		for (int i = 0; i < r; i++) {
			for (int j = c - 1; j >= 0; j--) {
				if (j == c-1) {
					mx[2][i][j] = grid[i][j];
				}
				else {
					if (grid[i][j] == 0) {
						mx[2][i][j] = 0;
					}
					else {
						mx[2][i][j] = mx[2][i][j + 1] + 1;
					}
				}
			}
		}

		// down
		for (int j = 0; j < c; j++) {
			for (int i = r - 1; i >= 0; i--) {
				if (i == r - 1) {
					mx[3][i][j] = grid[i][j];
				}
				else {
					if (grid[i][j] == 0) {
						mx[3][i][j] = 0;
					}
					else {
						mx[3][i][j] = mx[3][i + 1][j] + 1;
					}
				}
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				for (int k = 0; k < 4; k++) {
					for (int t = 0; t < 2; t++) {
						tot += max(0, min(mx[k][i][j], mx[(k + 4 + (1-2*t))%4][i][j]/2) - 1);
					}
				}
			}
		}

		cout << "Case #" << i << ": " << tot << '\n';
	}
}