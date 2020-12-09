#include<bits/stdc++.h>
using namespace std;

vector<int> dy = { -1, 1 };

struct location {
	int x, y, gravity, flips;
};

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
		for (int j = 0; j < m; j++) {
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

	bool found = false;
	for (int x2 = x + 1; x2 < n; x2++) {
		if (grid[x2][y] == '#') {
			x = x2 - 1;
			found = true;
			break;
		}
		else if (grid[x2][y] == 'D') {
			cout << 0;
			return 0;
		}
	}
	if (!found) {
		cout << -1;
		return 0;
	}

	int possible_best = 1 << 30;
	deque<location> q;
	q.push_back({ x,y,1,0 });
	while (!q.empty()) {
		location curr = q.front();
		if (curr.flips == possible_best) {
			cout << curr.flips;
			return 0;
		}
		q.pop_front();
		if (!visited[curr.x][curr.y]) {
			visited[curr.x][curr.y] = 1;
			for (int i = 0; i < 2; i++) {
				if (0 <= curr.y + dy[i] and curr.y + dy[i] < m
					and (grid[curr.x][curr.y + dy[i]] == '.' or grid[curr.x][curr.y + dy[i]] == 'D')) {
					if (curr.gravity) {
						for (int x2 = curr.x; x2 < n; x2++) {
							if (grid[x2][curr.y + dy[i]] == '#') {
								q.push_front({ x2 - 1,curr.y + dy[i],curr.gravity,curr.flips });
								break;
							}
							else if (grid[x2][curr.y + dy[i]] == 'D') {
								cout << curr.flips;
								return 0;
							}
						}
					}
					else {
						for (int x2 = curr.x; x2 >= 0; x2--) {
							if (grid[x2][curr.y + dy[i]] == '#') {
								q.push_front({ x2 + 1,curr.y + dy[i],curr.gravity,curr.flips });
								break;
							}
							else if (grid[x2][curr.y + dy[i]] == 'D') {
								cout << curr.flips;
								return 0;
							}
						}
					}
				}
			}
			if (curr.gravity) {
				for (int x2 = curr.x - 1; x2 >= 0; x2--) {
					if (grid[x2][curr.y] == '#') {
						q.push_back({ x2 + 1,curr.y,curr.gravity ^ 1,curr.flips + 1 });
						break;
					}
					else if (grid[x2][curr.y] == 'D') {
						possible_best = curr.flips + 1;
						break;
					}
				}
			}
			else {
				for (int x2 = curr.x + 1; x2 < n; x2++) {
					if (grid[x2][curr.y] == '#') {
						q.push_back({ x2 - 1,curr.y,curr.gravity ^ 1,curr.flips + 1 });
						break;
					}
					else if (grid[x2][curr.y] == 'D') {
						possible_best = curr.flips + 1;
						break;
					}
				}
			}
		}
	}

	cout << -1 << '\n';
}