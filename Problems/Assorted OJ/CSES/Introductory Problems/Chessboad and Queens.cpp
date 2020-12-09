#include<bits/stdc++.h>
using namespace std;

int ans = 0;
bool col_filled[8];
int row_to_col[8];
bool diag_filled[2][15];
bool unvisitable[8][8];

void solve(int row) {
	if (row == 8) {
		ans++;
		return;
	}

	for (int j = 0; j < 8; j++) {
		if (!unvisitable[row][j] and !col_filled[j] and !diag_filled[0][j + row] and !diag_filled[1][8 - 1 - row + j]) {
			col_filled[j] = 1;
			diag_filled[0][j + row] = 1;
			diag_filled[1][8 - 1 - row + j] = 1;
			row_to_col[row] = j;
			solve(row + 1);
			col_filled[j] = 0;
			diag_filled[0][j + row] = 0;
			diag_filled[1][8 - 1 - row + j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 8; i++) {
		string s; cin >> s;
		for (int j = 0; j < 8; j++) {
			if (s[j] == '*') {
				unvisitable[i][j] = 1;
			}
		}
	}

	solve(0);

	cout << ans << '\n';
}