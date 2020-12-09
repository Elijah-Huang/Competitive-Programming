#include<bits/stdc++.h>
using namespace std;

struct change {
	int dx, dy;
};
vector<change> delta = { {0,1},{0,-1},{1,0},{-1,0} };

struct pcl {
	int l, r, d, u;
};

void dfs(int x, int y, int& l, int& r, int& u, int& d, int& curr_comp,
	vector<vector<int>>& comp, vector<string>& grid) {
	comp[x][y] = curr_comp;
	for (auto e : delta) {
		if (u <= x + e.dx and x + e.dx <= d and l <= y + e.dy and y + e.dy <= r
			and grid[x][y] == grid[x + e.dx][y + e.dy] and !comp[x + e.dx][y + e.dy]) {
			dfs(x + e.dx, y + e.dy, l, r, u, d, curr_comp, comp, grid);
		}
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("where.in", "r", stdin); freopen("where.out", "w", stdout);
	int n;
	cin >> n;
	vector<string> grid(n);
	vector<vector<int>> comp(n, vector<int>(n));
	vector<pcl> pcls;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	for (int u = 0; u < n; u++) {
		for (int d = n - 1; d >= u; d--) {
			for (int l = 0; l < n; l++) {
				for (int r = n - 1; r >= l; r--) {
					bool subset = false;
					for (auto pclo : pcls) {
						if (pclo.l <= l and pclo.r >= r and pclo.d >= d and pclo.u <= u) {
							subset = true;
						}
					}
					if (!subset) {
						unordered_map<char, int> colors;
						for (int x = u; x <= d; x++) {
							for (int y = l; y <= r; y++) {
								colors[grid[x][y]] = 0;
							}
						}
						if (colors.size() == 2) {
							int curr_comp = 0;
							for (int x = u; x <= d; x++) {
								for (int y = l; y <= r; y++) {
									if (!comp[x][y]) {
										curr_comp++;
										colors[grid[x][y]]++;
										dfs(x, y, l, r, u, d, curr_comp, comp, grid);
									}
								}
							}
							vector<int> comp_amounts;
							for (auto c : colors) {
								comp_amounts.push_back(c.second);
							}
							if (comp_amounts[0] > comp_amounts[1]) {
								swap(comp_amounts[0], comp_amounts[1]);
							}
							if (comp_amounts[0] == 1 and comp_amounts[1] > 1) {
								pcls.push_back({ l,r,d,u });
							}
							for (int x = u; x <= d; x++) {
								for (int y = l; y <= r; y++) {
									comp[x][y] = 0;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << pcls.size();
}