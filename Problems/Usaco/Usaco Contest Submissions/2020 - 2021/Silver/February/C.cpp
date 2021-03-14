// O(n^3)
#include<bits/stdc++.h>
using namespace std;

int n;
int grid[500][500];
int col_mins[500];
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	// fix the top and bottom rows of the rectangle
	// then keep track of a column minimum and find valid left and rigth columns 
	// in O(n) time -> in total -> O(n*(n+1)/2 * n) -> O(n^3)
	for (int i = 0; i < n; i++) {
		// set col_mins to inf that way finding min is not affected
		memset(col_mins, 0x3f, sizeof(col_mins));

		for (int j = i; j < n; j++) {
			// update col_mins
			for (int col = 0; col < n; col++) {
				col_mins[col] = min(col_mins[col], grid[j][col]);
			}

			// split into segs where all elements are >= 100
			vector<pair<int, int>> segs1, segs2;
			int sz = 0;
			for (int col = 0; col < n; col++) {
				if (col_mins[col] < 100) {
					if (sz > 0) {
						segs1.push_back({ col - sz,col - 1 });
						sz = 0;
					}
				}
				else {
					sz += 1;
				}
			}
			// last segment if there is no num < 100 at the end
			if (sz > 0) {
				segs1.push_back({ n - sz, n - 1 });
				sz = 0;
			}

			// calculate # of subarrays per seg
			for (auto [l,r] : segs1) {
				ans += (r - l + 1) * (r - l + 1 + 1) / 2;

				int sz = 0;
				for (int col = l; col <= r; col++) {
					if (col_mins[col] == 100) {
						if (sz > 0) {
							segs2.push_back({ col - sz,col - 1 });
							sz = 0;
						}
					}
					else {
						sz += 1;
					}
				}
				// last segment if there is no num == 100 at the end
				if (sz > 0) {
					segs2.push_back({ r + 1 - sz, r });
					sz = 0;
				}
			}

			// subract subarrays without 100 in them
			for (auto [l, r] : segs2) {
				ans -= (r - l + 1) * (r - l + 1 + 1) / 2;

			}
		}
	}

	cout << ans;
}