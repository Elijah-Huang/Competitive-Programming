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

void dfs(point curr, int& curr_comp, vector<vector<point>>& comps,
	vector<vector<int>>& comp, vector<vector<int>>& grid, int& n) {
	comp[curr.x][curr.y] = curr_comp;
	comps[curr_comp].push_back(curr);
	for (auto d : delta) {
		if (0 <= curr.x + d.dx and curr.x + d.dx < n and
			0 <= curr.y + d.dy and curr.y + d.dy < n and
			grid[curr.x][curr.y] == grid[curr.x + d.dx][curr.y + d.dy]
			and comp[curr.x + d.dx][curr.y + d.dy] == -1) {
			dfs(point{ curr.x + d.dx, curr.y + d.dy }, curr_comp, comps, comp, grid, n);
		}
	}
}

void dfs2(int curr, int second_color,
	int& original_color, unordered_set<int>& visited, vector<bool>& visited_already,
	vector<unordered_set<int>>& adj, vector<int>& color,
	vector<vector<point>>& comps, unordered_map<int, int>& sizes, 
	unordered_map<int,vector<int>>& color_to_idx) {
	if (second_color != -1) {
		sizes[second_color] += comps[curr].size();
	}
	visited.insert(curr);
	if (color[curr] == original_color and second_color == -1) {
		for (auto neighbor : adj[curr]) {
			if (!visited.count(neighbor) and !visited_already[neighbor]) {
				dfs2(neighbor, color[neighbor], original_color,
					visited, visited_already, adj, color, comps, sizes, color_to_idx);
			}
		}
	}
	else if (color[curr] == original_color) {
		if (adj[curr].size() < color_to_idx[second_color].size()) {
			for (auto neighbor : adj[curr]) {
				if (color[neighbor] == second_color and !visited.count(neighbor)
					and !visited_already[neighbor]) {
					dfs2(neighbor, second_color, original_color,
						visited, visited_already, adj, color, comps, sizes, color_to_idx);
				}
			}
		}
		else {
			for (auto neighbor : color_to_idx[second_color]) {
				if (adj[curr].count(neighbor) and !visited.count(neighbor)
					and !visited_already[neighbor]) {
					dfs2(neighbor, second_color, original_color,
						visited, visited_already, adj, color, comps, sizes, color_to_idx);
				}
			}
		}
	}
	else {
		if (adj[curr].size() < color_to_idx[original_color].size()) {
			for (auto neighbor : adj[curr]) {
				if (color[neighbor] == original_color and !visited.count(neighbor)
					and !visited_already[neighbor]) {
					dfs2(neighbor, second_color, original_color,
						visited, visited_already, adj, color, comps, sizes, color_to_idx);
				}
			}
		}
		else {
			for (auto neighbor : color_to_idx[original_color]) {
				if (adj[curr].count(neighbor) and !visited.count(neighbor)
					and !visited_already[neighbor]) {
					dfs2(neighbor, second_color, original_color,
						visited, visited_already, adj, color, comps, sizes, color_to_idx);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("multimoo.in", "r", stdin); freopen("multimoo.out", "w", stdout);
	int n, curr_comp = -1;
	cin >> n;
	vector<vector<int>> grid(n);
	vector<vector<int>> comp(n, vector<int>(n, -1));
	vector<vector<point>> comps;
	vector<int> color;
	unordered_map<int, vector<int>> color_to_idx;
	vector<unordered_set<int>> adj;
	vector<vector<int>> adjv;
	vector<bool> visited_already;
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
				color_to_idx[grid[i][j]].push_back(curr_comp);
				comps.resize(curr_comp + 1);
				dfs(point{ i,j }, curr_comp, comps, comp, grid, n);
			}
		}
	}
	int mx_size = 0;
	for (auto& i : comps) {
		mx_size = max(mx_size, (int)i.size());
	}
	cout << mx_size << '\n';

	adj.resize(comps.size());
	visited_already.resize(comps.size());
	for (int i = 0; i < comps.size(); i++) {
		for (auto& curr : comps[i]) {
			for (auto d : delta) {
				if (0 <= curr.x + d.dx and curr.x + d.dx < n and
					0 <= curr.y + d.dy and curr.y + d.dy < n and
					grid[curr.x][curr.y] != grid[curr.x + d.dx][curr.y + d.dy]) {
					adj[i].insert(comp[curr.x + d.dx][curr.y + d.dy]);
				}
			}
		}
	}
	mx_size = 0;
	for (int i = 0; i < comps.size(); i++) {
		unordered_set<int> visited;
		unordered_map<int, int> sizes;
		dfs2(i, -1, color[i], visited, visited_already, adj, color, comps, sizes, color_to_idx);
		for (auto sz : sizes) {
			mx_size = max(mx_size, (int)comps[i].size() + sz.second);
		}
		//visited_already[i] = 1;
	}
	cout << mx_size;
}