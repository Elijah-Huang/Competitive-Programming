#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("lazy.in", "r", stdin); freopen("lazy.out", "w", stdout);
	int n, k; cin >> n >> k;
	vector<vector<int>> grid(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		int curr_tot = 0;
		//base case
		for (int j = 0; j <= min(n-1,k); j++) {
			for (int i2 = i; i2 >= max(0, i - (k-j)); i2--) {
				curr_tot += grid[i2][j];
			}
			for (int i2 = i + 1; i2 <= min(n-1, i + (k - j)); i2++) {
				curr_tot += grid[i2][j];
			}
		}
		mx = max(mx, curr_tot);

		for (int j = 1; j < n; j++) {
			//adding if exists
			for (int j2 = j; j2 <= min(n - 1, j + k); j2++) {
				if (i + (k - (j2 - j)) < n) {
					curr_tot += grid[i + (k - (j2 - j))][j2];
				}
				if (i - (k - (j2 - j)) >= 0 and j2 != j + k) {
					curr_tot += grid[i - (k - (j2 - j))][j2];
				}
			}
			//removing if exists
			for (int j2 = j - 1; j2 >= max(0, j - k - 1); j2--) {
				if (i + (k - (j - 1 - j2)) < n) {
					curr_tot -= grid[i + (k - (j - 1 - j2))][j2];
				}
				if (i - (k - (j - 1 - j2)) >= 0 and j2 != j - k - 1) {
					curr_tot -= grid[i - (k - (j - 1 - j2))][j2];
				}
			}
			mx = max(mx, curr_tot);
		}
	}

	cout << mx;
}