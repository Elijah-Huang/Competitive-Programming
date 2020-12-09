#include<bits/stdc++.h>
using namespace std;

struct loc {
	int dist, curr_island, left;
};

struct loc_cmp {
	bool operator()(const loc& a, const loc& b) const {
		return a.dist > b.dist;
	}
};

vector<int> dx = { 1,0,-1,0 };
vector<int> dy = { 0,1,0,-1 };
int ans = 1e9;
int r, c;
int dist[15][1 << 15], island_dist[15][15], dist2[50][50];
bool visited[50][50];
vector<string> grid;
vector<pair<int, int>> comps;

void dfs_comp(int i, int j) {
	visited[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		if (0 <= i + dx[k] and i + dx[k] < r and
			0 <= j + dy[k] and j + dy[k] < c and 
			!visited[i + dx[k]][j + dy[k]]
			and grid[i + dx[k]][j + dy[k]] == 'X') {
			dfs_comp(i + dx[k], j + dy[k]);
		}
	}
}

void bfs(int starti, int startj) {
	deque<pair<int,int>> dq;
	dq.push_back({ starti, startj });
	while (!dq.empty()) {
		int i = dq.front().first, j = dq.front().second; dq.pop_front();
		for (int k = 0; k < 4; k++) {			
			if (0 <= i + dx[k] and i + dx[k] < r and
				0 <= j + dy[k] and j + dy[k] < c and
				dist2[i + dx[k]][j + dy[k]] == -1) {
				if (grid[i + dx[k]][j + dy[k]] == 'X') {
					dist2[i + dx[k]][j + dy[k]] = dist2[i][j];
					dq.push_front({ i + dx[k], j + dy[k] });
				}
				else if (grid[i + dx[k]][j + dy[k]] == 'S') {
					dist2[i + dx[k]][j + dy[k]] = dist2[i][j] + 1;
					dq.push_back({ i + dx[k], j + dy[k] });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("island.in", "r", stdin); freopen("island.out", "w", stdout);
	cin >> r >> c;
	grid.resize(r);
	for (int i = 0; i < r; i++) {
		cin >> grid[i];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visited[i][j] and grid[i][j] == 'X') {
				comps.push_back({ i,j });
				dfs_comp(i,j);
			}
		}
	}

	for (int i = 0; i < comps.size(); i++) {
		memset(dist2, -1, sizeof(dist2));
		dist2[comps[i].first][comps[i].second] = 0;
		bfs(comps[i].first, comps[i].second);
		for (int j = 0; j < comps.size(); j++) {
			island_dist[i][j] = dist2[comps[j].first][comps[j].second];
		}
	}

	memset(dist, 0x3f, sizeof(dist));
	priority_queue<loc,vector<loc>, loc_cmp> pq;
	for (int i = 0; i < comps.size(); i++) {
		pq.push({ 0,i,((1 << comps.size()) - 1) ^ (1 << i) });
	}
	while (!pq.empty()) {
		loc curr = pq.top(); pq.pop();
		if (dist[curr.curr_island][curr.left] > curr.dist) {
			dist[curr.curr_island][curr.left] = curr.dist;
			for (int i = 0; i < comps.size(); i++) {
				if ((1 << i) & curr.left) {
					pq.push({ curr.dist + island_dist[curr.curr_island][i], i, curr.left ^ (1 << i) });
				}
			}
		}
	}

	for (int i = 0; i < comps.size(); i++) {
		ans = min(ans, dist[i][0]);
	}
	cout << ans;
}