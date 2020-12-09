#include<bits/stdc++.h>
using namespace std;

vector<int> dy = { -1, 1 };
int dfs(int x, int y, bool gravity, int flips, int& endx, int& endy, int& n, int& m, vector<string>& grid, vector<vector<bool>>& visited) {
	if (x == endx and y == endy) {
		return flips;
	}
	if (!visited[x][y]) {
		visited[x][y] = 1;
		for (int i = 0; i < 2; i++) {
			if (0 <= y + dy[i] and y + dy[i] < m
				and grid[x][y + dy[i]] == '.') {
				if (gravity) {
					for (int x2 = x + 1; x2 < n; x2++) {
						if (grid[x2][y + dy[i]] == '#') {
							int flips2 = dfs(x2 - 1, y + dy[i], gravity, flips, endx, endy, n, m, grid, visited);
							if (flips2 != -1) {
								return flips2;
							}
							break;
						}
					}
				}
				else {
					for (int x2 = x - 1; x2 >= 0; x2--) {
						if (grid[x2][y + dy[i]] == '#') {
							int flips2 = dfs(x2 + 1, y + dy[i], gravity, flips, endx, endy, n, m, grid, visited);
							if (flips2 != -1) {
								return flips2;
							}
							break;
						}
					}
				}
			}
		}
		if (gravity) {
			for (int x2 = x - 1; x2 >= 0; x2--) {
				if (grid[x2][y] == '#') {
					int flips2 = dfs(x2 + 1, y, gravity ^ 1, flips + 1, endx, endy, n, m, grid, visited);
					if (flips2 != -1) {
						return flips2;
					}
					break;
				}
			}
		}
		else {
			for (int x2 = x + 1; x2 < n; x2++) {
				if (grid[x2][y] == '#') {
					int flips2 = dfs(x2 - 1, y, gravity ^ 1, flips + 1, endx, endy, n, m, grid, visited);
					if (flips2 != -1) {
						return flips2;
					}
					break;
				}
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("gravity.in", "r", stdin); freopen("gravity.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	vector<vector<bool>> visited(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	int x = 0, y = 0;
	int endx = 0, endy = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 'C') {
				x = i; 
				y = j;
			}
			else if (grid[i][j] == 'D') {
				endx = i;
				endy = j;
			}
		}
	}
	bool gravity = 1;
	int flips = 0;
	flips = dfs(x, y, gravity, flips, endx, endy, n, m, grid, visited);
	cout << flips << '\n';
	/*for (auto i : visited) {
		for (auto j : i) {
			cout << j;
		}
		cout << '\n';
	}*/
}