#include<bits/stdc++.h>
using namespace std;

vector<int> dx = { 1,0,-1,0 };
vector<int> dy = { 0,1,0,-1 };

struct loc {
	int i, j;
};

int n, m, k;
int ans = 1e6;
vector<string> grid;
pair<int, int> closest_to_border = { 1e6,1e6 };
vector<vector<pair<int, int>>> closest_rams;
vector<vector<int>> dists;
vector<loc> rams;

void update_min(pair<int, int>& a, int min_dist) {
	if (min_dist < a.first) {
		a.second = a.first;
		a.first = min_dist;
	}
	else if (min_dist < a.second) {
		a.second = min_dist;
	}
}

int bfs_ram(int i2, int j2) {
	int ret = 1e6;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dists[i][j] = -1;
		}
	}
	dists[i2][j2] = 0;

	deque<loc> dq;
	dq.push_back({ i2, j2});
	while (!dq.empty()) {
		loc curr = dq.front(); dq.pop_front();
		if ((curr.i == 0 or curr.i == n - 1 or curr.j == 0 or curr.j == m - 1) and ret == 1e6) {
			ret = dists[curr.i][curr.j];
		}
		for (int i = 0; i < 4; i++) {
			if (0 <= curr.i + dx[i] and curr.i + dx[i] < n and
				0 <= curr.j + dy[i] and curr.j + dy[i] < m and
				dists[curr.i + dx[i]][curr.j + dy[i]] == -1) {
				if (grid[curr.i + dx[i]][curr.j + dy[i]] == '.') {
					dists[curr.i + dx[i]][curr.j + dy[i]] = dists[curr.i][curr.j];
					dq.push_front({ curr.i + dx[i],curr.j + dy[i] });

				}
				else {
					dists[curr.i + dx[i]][curr.j + dy[i]] = dists[curr.i][curr.j] + 1;
					dq.push_back({ curr.i + dx[i],curr.j + dy[i] });
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			update_min(closest_rams[i][j], dists[i][j]);
		}
	}

	return ret;
}

void bfs_borders() {
	deque<loc> dq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dists[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		dists[i][0] = (grid[i][0] == '#');
		if (grid[i][0] == '.') {
			dq.push_front({ i,0 });
		}
		else {
			dq.push_back({ i,0 });
		}
		dists[i][m-1] = (grid[i][m-1] == '#');
		if (grid[i][m-1] == '.') {
			dq.push_front({ i,m-1 });
		}
		else {
			dq.push_back({ i,m-1 });
		}
	}
	for (int j = 0; j < m; j++) {
		dists[0][j] = (grid[0][j] == '#');
		if (grid[0][j] == '.') {
			dq.push_front({ 0,j });
		}
		else {
			dq.push_back({ 0,j });
		}
		dists[n - 1][j] = (grid[n - 1][j] == '#');
		if (grid[n-1][j] == '.') {
			dq.push_front({ n - 1,j });
		}
		else {
			dq.push_back({ n - 1,j });
		}
	}

	while (!dq.empty()) {
		loc curr = dq.front(); dq.pop_front();
		for (int i = 0; i < 4; i++) {
			if (0 <= curr.i + dx[i] and curr.i + dx[i] < n and
				0 <= curr.j + dy[i] and curr.j + dy[i] < m and 
				dists[curr.i + dx[i]][curr.j + dy[i]] == -1) {
				if (grid[curr.i + dx[i]][curr.j + dy[i]] == '.') {
					dists[curr.i + dx[i]][curr.j + dy[i]] = dists[curr.i][curr.j];
					dq.push_front({ curr.i + dx[i],curr.j + dy[i] });
					
				}
				else {
					dists[curr.i + dx[i]][curr.j + dy[i]] = dists[curr.i][curr.j] + 1;
					dq.push_back({ curr.i + dx[i],curr.j + dy[i] });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	grid.resize(n);
	dists.resize(n, vector<int>(m));
	closest_rams.resize(n, vector <pair<int, int>>(m, { 1e6,1e6 }));
	rams.resize(k);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> rams[i].i >> rams[i].j;
		rams[i].i--, rams[i].j--;
	}

	for (auto& ram : rams) {
		update_min(closest_to_border, bfs_ram(ram.i, ram.j));
	}
	ans = closest_to_border.first + closest_to_border.second;

	bfs_borders();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = min(ans, closest_rams[i][j].first + closest_rams[i][j].second + dists[i][j] - 2 * (grid[i][j] == '#'));
		}
	}

	cout << ans << '\n';
}