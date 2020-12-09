#include<bits/stdc++.h>
using namespace std;

vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,1,0,-1 };

struct loc {
	int x, y, d, o, dir;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("dream.in", "r", stdin); freopen("dream.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	vector<vector<vector<int>>> dists(n, vector<vector<int>>(m, vector<int>(2, 1e9)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	
	queue<loc> q({ { 0,0,0,0,0 } });
	while (!q.empty()) {
		loc curr = q.front(); q.pop();
		if (dists[curr.x][curr.y][curr.o] == 1e9) {
			bool finished_sliding = 1;
			if (grid[curr.x][curr.y] == 4) {
				switch (curr.dir) {
				case 0:
					if (curr.x > 0 and grid[curr.x-1][curr.y] != 0 and grid[curr.x - 1][curr.y] != 3) {
						q.push({ curr.x - 1,curr.y, curr.d + 1, curr.o, curr.dir });
						finished_sliding = 0;
					}
					break;
				case 1:
					if (curr.y < m - 1 and grid[curr.x][curr.y+1] != 0 and grid[curr.x][curr.y+1] != 3) {
						q.push({ curr.x, curr.y + 1, curr.d + 1, curr.o, curr.dir });
						finished_sliding = 0;
					}
					break;
				case 2:
					if (curr.x < n - 1 and grid[curr.x+1][curr.y] != 0 and grid[curr.x+1][curr.y] != 3) {
						q.push({ curr.x + 1, curr.y, curr.d + 1, curr.o, curr.dir });
						finished_sliding = 0;
					}
					break;
				case 3:
					if (curr.y > 0 and grid[curr.x][curr.y-1] != 0 and grid[curr.x][curr.y-1] != 3) {
						q.push({ curr.x,curr.y - 1, curr.d + 1, curr.o, curr.dir });
						finished_sliding = 0;
					}
					break;
				}
			}
			if (!finished_sliding) {
				continue;
			}
			dists[curr.x][curr.y][curr.o] = curr.d;
			for (int i = 0; i < 4; i++) {
				if (0 <= curr.x + dx[i] and curr.x + dx[i] < n and
					0 <= curr.y + dy[i] and curr.y + dy[i] < m) {
					switch (grid[curr.x + dx[i]][curr.y + dy[i]]) {
					case 0:
						break;
					case 1:
						q.push({ curr.x + dx[i], curr.y + dy[i], curr.d + 1, curr.o, i });
						break;
					case 2:
						q.push({ curr.x + dx[i], curr.y + dy[i], curr.d + 1, 1, i });
						break;
					case 3:
						if (curr.o == 1) {
							q.push({ curr.x + dx[i], curr.y + dy[i], curr.d + 1, curr.o, i});
						}
						break;
					case 4:
						q.push({ curr.x + dx[i], curr.y + dy[i], curr.d + 1, 0, i });
						break;
					}
					
				}
			}
		}
	}

	if (dists[n - 1][m - 1][0] == 1e9 and dists[n - 1][m - 1][1] == 1e9) {
		cout << -1;
	}
	else {
		cout << min(dists[n - 1][m - 1][0], dists[n - 1][m - 1][1]) << '\n';
	}
}