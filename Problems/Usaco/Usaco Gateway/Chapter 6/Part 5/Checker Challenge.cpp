/*
ID: elijahj1
TASK: checker
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
bool col_filled[13];
int row_to_col[13];
bool diag_filled[2][25];
vector<vector<int>> three_sols;

void solve(int row) {
	if (row == n) {
		ans++;
		if (ans <= 3) {
			vector<int> sol;
			for (int i = 0; i < n; i++) {
				sol.push_back(row_to_col[i] + 1);
			}
			three_sols.push_back(sol);
		}
		return;
	}

	for (int j = 0; j < n; j++) {
		if (!col_filled[j] and !diag_filled[0][j + row] and !diag_filled[1][n - 1 - row + j]) {
			col_filled[j] = 1;
			diag_filled[0][j + row] = 1;
			diag_filled[1][n - 1 - row + j] = 1;
			row_to_col[row] = j;
			solve(row + 1);
			col_filled[j] = 0;
			diag_filled[0][j + row] = 0;
			diag_filled[1][n - 1 - row + j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("checker.in", "r", stdin); freopen("checker.out", "w", stdout);
	cin >> n;

	for (int j = 0; j < (n == 6 ? n : n/2); j++) {
		col_filled[j] = 1;
		diag_filled[0][j] = 1;
		diag_filled[1][n - 1 + j] = 1;
		row_to_col[0] = j;
		solve(1);
		col_filled[j] = 0;
		diag_filled[0][j] = 0;
		diag_filled[1][n - 1 + j] = 0;
	}

	if (n != 6) {
		ans *= 2;
	}
	if (n & 1) {
		col_filled[n / 2] = 1;
		diag_filled[0][n / 2] = 1;
		diag_filled[1][n - 1 + n / 2] = 1;
		row_to_col[0] = n / 2;
		solve(1);
		col_filled[n / 2] = 0;
		diag_filled[0][n / 2] = 0;
		diag_filled[1][n - 1 + n / 2] = 0;
	}

	for (auto& sol : three_sols) {
		for (int i = 0; i < sol.size(); i++) {
			cout << sol[i] << (i != sol.size() - 1 ? ' ' : '\n');
		}
	}
	cout << ans << '\n';
}