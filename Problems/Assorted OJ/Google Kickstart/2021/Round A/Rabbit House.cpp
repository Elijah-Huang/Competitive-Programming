#include<bits/stdc++.h>
using namespace std;

vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,-1,0,1 };

const int maxn = 300, maxg = 2e6 + 1;

int t, r, c;
int g[maxn][maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int i = 1; i <= t; i++) {
		long long added = 0;
		vector<vector<pair<int,int>>> a(maxg);

		cin >> r >> c;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> g[i][j];
				a[g[i][j]].push_back({ i,j });
			}
		}

		for (int h = maxg-1; h >= 2; h--) {
			for (auto b : a[h]) {
				int i = b.first, j = b.second;

				if (g[i][j] == h) {
					for (int k = 0; k < 4; k++) {
						int i2 = i + dy[k], j2 = j + dx[k];

						if (0 <= i2 and i2 < r and 0 <= j2 and j2 < c
							and g[i2][j2] < h-1) {
							added += (h - 1 - g[i2][j2]);
							g[i2][j2] = h - 1;
							a[h - 1].push_back({ i2,j2 });
						}
					}
				}
			}
		}

		cout << "Case #" << i << ": " << added << '\n';
	}
}