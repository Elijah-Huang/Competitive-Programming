#include<bits/stdc++.h>
using namespace std;

struct vertex {
	bool l = 0, r = 0, d = 0, u = 0;
};

struct location {
	int x, y;
};

void dfs(int x, int y, int& curr_comp, int comp[102][102], vertex grid[102][102]) {
	comp[x][y] = curr_comp;
	if (!grid[x][y].l and !comp[x][y - 1]) {
		dfs(x, y - 1, curr_comp, comp, grid);
	}
	if (!grid[x][y].r and !comp[x][y + 1]) {
		dfs(x, y + 1, curr_comp, comp, grid);
	}
	if (!grid[x][y].u and !comp[x - 1][y]) {
		dfs(x - 1, y, curr_comp, comp, grid);
	}
	if (!grid[x][y].d and !comp[x + 1][y]) {
		dfs(x + 1, y, curr_comp, comp, grid);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("countcross.in", "r", stdin); freopen("countcross.out", "w", stdout);
	int n, k, r, curr_comp = 0, total_distant = 0;
	cin >> n >> k >> r;
	vertex grid[102][102];
	int comp[102][102]{};
	vector<location> locations(k);
	for (int i = 0; i < r; i++) {
		int r, c, r2, c2;
		cin >> r >> c >> r2 >> c2;
		if (r == r2 - 1) {
			grid[r][c].d = 1;
			grid[r2][c2].u = 1;
		}
		else if (r == r2 + 1) {
			grid[r][c].u = 1;
			grid[r2][c2].d = 1;
		}
		else if (c == c2 - 1) {
			grid[r][c].r = 1;
			grid[r2][c2].l = 1;
		}
		else {
			grid[r][c].l = 1;
			grid[r2][c2].r = 1;
		}
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		locations[i] = { x,y };
	}
	for (int i = 1; i <= n; i++) {
		grid[i][1].l = 1;
		grid[i][n].r = 1;
		grid[1][i].u = 1;
		grid[n][i].d = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!comp[i][j]) {
				curr_comp++;
				dfs(i, j, curr_comp, comp, grid);
			}
		}
	}
	for (int i = 0; i < k-1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (comp[locations[i].x][locations[i].y]
				!= comp[locations[j].x][locations[j].y]) {
				total_distant++;
			}
		}
	}
	cout << total_distant;
}