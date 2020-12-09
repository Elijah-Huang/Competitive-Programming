#include<bits/stdc++.h>
using namespace std;

struct change {
	int dx, dy;
};
vector<change> delta = { {0,1},{1,0},{-1,0}, {0,-1} };

struct point {
	int x, y;
};

void dfs(int i, int j, int& n, int& curr_comp, vector<string>& grid,
	vector<vector<bool>>& visited, vector<vector<point>>& comps) {
	visited[i][j] = 1;
	comps[curr_comp].push_back({ i,j });
	for (auto d : delta) {
		if (0 <= i + d.dx and i + d.dx < n and 0 <= j + d.dy and j + d.dy < 10
			and !visited[i + d.dx][j + d.dy] and 
			grid[i + d.dx][j + d.dy] == grid[i][j]) {
			dfs(i + d.dx, j + d.dy, n, curr_comp, grid, visited, comps);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("mooyomooyo.in", "r", stdin); freopen("mooyomooyo.out", "w", stdout);
	int n, k; 
	cin >> n >> k;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	while (true) {
		vector<vector<bool>> visited(n, vector<bool>(10));
		vector<vector<point>> comps;
		int curr_comp = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				if (!visited[i][j] and grid[i][j] != '0') {
					curr_comp++;
					comps.resize(curr_comp + 1);
					dfs(i, j, n, curr_comp, grid, visited, comps);
				}
			}
		}
		bool disappeared = false;
		for (int i = 0; i < comps.size(); i++) {
			if (comps[i].size() >= k) {
				disappeared = true;
				for (auto p : comps[i]) {
					grid[p.x][p.y] = '0';
				}
			}
		}
		if (disappeared) {
			vector<string> new_gridt(10);
			vector<string> new_grid(n, string(10,'0'));
			for (int j = 0; j < 10; j++) {
				for (int i = n - 1; i >= 0; i--) {
					if (grid[i][j] != '0') {
						new_gridt[j].push_back(grid[i][j]);
					}
				}
			}
			for (int j = 0; j < 10; j++) {
				for (int i = n - 1; i >= n - new_gridt[j].size(); i--) {
					new_grid[i][j] = new_gridt[j][n - 1 - i];
				}
			}
			grid = new_grid;
		}
		else {
			break;
		}
	}
	for (auto row : grid) {
		cout << row << '\n';
	}
}