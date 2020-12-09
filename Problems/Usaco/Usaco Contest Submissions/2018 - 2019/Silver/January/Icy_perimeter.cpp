#include<bits/stdc++.h>
using namespace std;

struct change {
	int dx, dy;
};
vector<change> delta = { {0,1},{1,0},{-1,0},{0,-1} };

void dfs(int i,int j, int& curr_comp, int& n, vector<vector<int>>& comp,
	vector<string>& grid) {
	comp[i][j] = curr_comp;
	for (auto d : delta) {
		if (0 <= i + d.dx and i + d.dx < n and 0 <= j + d.dy and j + d.dy < n
			and grid[i + d.dx][j + d.dy] == '#' and comp[i + d.dx][j + d.dy] == -1) {
			dfs(i + d.dx, j + d.dy, curr_comp, n, comp, grid);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("perimeter.in", "r", stdin); freopen("perimeter.out", "w", stdout);
	int n;
	cin >> n;
	vector<string> grid(n);
	vector<vector<int>> comp(n, vector<int>(n, -1));
	vector<pair<int, int>> area_perimeter;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	int curr_comp = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (comp[i][j] == -1 and grid[i][j] == '#') {
				curr_comp++;
				dfs(i, j, curr_comp, n, comp, grid);
			}
		}
	}
	area_perimeter.resize(curr_comp + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (comp[i][j] != -1) {
				area_perimeter[comp[i][j]].first++;
				for (auto d : delta) {
					if (0 <= i + d.dx and i + d.dx < n and 
						0 <= j + d.dy and j + d.dy < n) {
						if (grid[i + d.dx][j + d.dy] == '.') {
							area_perimeter[comp[i][j]].second++;
						}
					}
					else {
						area_perimeter[comp[i][j]].second++;
					}
				}
			}
		}
	}
	int mx_area = 0;
	for (int i = 0; i <= curr_comp; i++) {
		mx_area = max(mx_area, area_perimeter[i].first);
	}
	int least_perimeter = 1 << 30;
	for (int i = 0; i <= curr_comp; i++) {
		if (area_perimeter[i].first == mx_area) {
			least_perimeter = min(least_perimeter, area_perimeter[i].second);
		}
	}
	cout << mx_area << ' ' << least_perimeter;
}