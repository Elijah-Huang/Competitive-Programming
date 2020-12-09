#include<bits/stdc++.h>
using namespace std;

int max_area = 0;
vector<string> marble;
int segment[300][300];
int up_furthesti[300][300];
int up_max[300][300], down_max[300][300][300];
int max_in_range[300][300];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("eight.in", "r", stdin); freopen("eight.out", "w", stdout);
	int n; cin >> n;
	marble.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> marble[i];
	}

	for (int i = 0; i < n; i++) {
		int curr_seg = 0;
		segment[i][0] = 0;
		for (int j = 1; j < n; j++) {
			if (marble[i][j] == '.') {
				if (marble[i][j - 1] == '*') {
					curr_seg++;
				}
			}
			else {
				curr_seg++;
			}

			segment[i][j] = curr_seg;
		}
	}

	for (int jl = 0; jl < n - 2; jl++) {
		for (int jr = jl + 2; jr < n; jr++) {

			up_furthesti[jl][jr] = n;

			int furthesti = n;
			for (int i = n-1; i >= 0; i--) {
				if (furthesti == n and segment[i][jl] == segment[i][jr]) {
					furthesti = i;
				}
				else if (!(marble[i][jl] == '.' and marble[i][jr] == '.')) {
					furthesti = n;
				}

				if (furthesti != n and furthesti - i >= 2) {
					down_max[i][jl][jr] = (furthesti - i - 1) * (jr - jl - 1);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {

		memset(up_max, 0, sizeof(up_max));
		for (int jl = 0; jl < n - 2; jl++) {
			for (int jr = jl + 2; jr < n; jr++) {
				if (up_furthesti[jl][jr] == n and segment[i][jl] == segment[i][jr]) {
					up_furthesti[jl][jr] = i;
				}
				else if (!(marble[i][jl] == '.' and marble[i][jr] == '.')) {
					up_furthesti[jl][jr] = n;
				}

				if (up_furthesti[jl][jr] != n and i - up_furthesti[jl][jr] >= 2) {
					up_max[jl][jr] = (i - up_furthesti[jl][jr] - 1) * (jr - jl - 1);
				}
			}
		}
		
		memset(max_in_range, 0, sizeof(max_in_range));
		for (int jr = 2; jr < n; jr++) {
			for (int jl = jr - 2; jl >= 0; jl--) {
				max_in_range[jl][jr] = max({ max_in_range[jl][jr - 1], max_in_range[jl + 1][jr], up_max[jl][jr] });
			}
		}

		for (int jl = 0; jl < n - 2; jl++) {
			for (int jr = jl + 2; jr < n and segment[i][jl] == segment[i][jr]; jr++) {
				max_area = max(max_area, max_in_range[jl][jr]*down_max[i][jl][jr]);
			}
		}
	}

	if (max_area == 0) {
		max_area = -1;
	}
	cout << max_area;
}