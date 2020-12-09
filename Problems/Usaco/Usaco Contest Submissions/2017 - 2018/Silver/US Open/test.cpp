#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
struct change {
	int dx, dy;
};
vector<change> delta = { {0,1},{1,0},{0,-1},{-1,0} };

struct point {
	int x, y;
	bool operator==(const point& b) const {
		return b.x == x and b.y == y;
	}
};

struct point_cmp {
	size_t operator()(const point& a) const {
		return a.x ^ a.y;
	}
};

void dfs(point curr, int& curr_comp, vector<vector<point>>& comps,
	vector<vector<int>>& comp, vector<vector<int>>& grid, int& n) {
	comp[curr.x][curr.y] = curr_comp;
	comps[curr_comp].push_back(curr);
	for (auto d : delta) {
		if (0 < curr.x + d.dx and curr.x + d.dx < n and
			0 < curr.y + d.dy and curr.y + d.dy < n and
			grid[curr.x][curr.y] == grid[curr.x + d.dx][curr.y + d.dy]
			and comp[curr.x + d.dx][curr.y + d.dy] == -1) {
			dfs(point{ curr.x + d.dx, curr.y + d.dy }, curr_comp, comps, comp, grid, n);
		}
	}
}

void dfs2(int curr, int curr_size, int& mx_size, int& original_color, unordered_set<int>& visited,
	vector<unordered_set<int>>& adj, vector<int>& color, vector<vector<point>>& comps) {
	curr_size += comps[curr].size();
	mx_size = max(curr_size, mx_size);
	visited.insert(curr);
	if (color[curr] == original_color) {
		for (auto neighbor : adj[curr]) {
			if (!visited.count(neighbor)) {
				dfs2(neighbor, curr_size, mx_size, original_color, visited, adj, color, comps);
			}
		}
	}
	else {
		for (auto neighbor : adj[curr]) {
			if (color[neighbor] == original_color and !visited.count(neighbor)) {
				dfs2(neighbor, curr_size, mx_size, original_color, visited, adj, color, comps);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("multimoo.in", "r", stdin); freopen("multimoo.out", "w", stdout);
	int n, curr_comp = -1;
	cin >> n;
	vector<vector<int>> grid(n);
	vector<vector<int>> comp(n, vector<int>(n, -1));
	vector<vector<point>> comps;
	vector<int> color;
	vector<unordered_set<int>> adj;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			grid[i].push_back(a);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (comp[i][j] == -1) {
				curr_comp++;
				color.push_back(grid[i][j]);
				comps.resize(curr_comp + 1);
				dfs(point{ i,j }, curr_comp, comps, comp, grid, n);
			}
		}
	}
	for (auto i : comp) {
		for (auto j : i) {
			cout << j;
		}
		cout << '\n';
	}
	int mx_size = 0;
	for (auto& i : comps) {
		mx_size = max(mx_size, (int)i.size());
	}
	cout << mx_size << '\n';
	adj.resize(comps.size());
	for (int i = 0; i < comps.size(); i++) {
		for (auto& curr : comps[i]) {
			for (auto d : delta) {
				if (0 < curr.x + d.dx and curr.x + d.dx < n and
					0 < curr.y + d.dy and curr.y + d.dy < n and
					grid[curr.x][curr.y] != grid[curr.x + d.dx][curr.y + d.dy]) {
					adj[i].insert(comp[curr.x + d.dx][curr.y + d.dy]);
				}
			}
		}
	}
	mx_size = 0;
	for (int i = 0; i < comps.size(); i++) {
		unordered_set<int> visited;
		dfs2(i, 0, mx_size, color[i], visited, adj, color, comps);
	}
	cout << mx_size;
}