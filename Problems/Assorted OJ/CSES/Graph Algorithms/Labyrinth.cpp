#include<bits/stdc++.h>
using namespace std;

struct loc {
	int x, y, visited;
	char dir;
};

string direction = "DRUL";
vector<int> dx = { 1,0,-1,0 };
vector<int> dy = { 0,1,0,-1 };

int n, m;
loc locs[1000][1000];
vector<string> grid;
int startx, starty;
string path;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	grid.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'A') {
				startx = i, starty = j;
			}
		}
	}

	queue<loc> q;
	locs[startx][starty] = { 0,0,1,'#' };
	q.push({ startx, starty});
	while (!q.empty()) {
		loc curr = q.front(); q.pop();

		if (grid[curr.x][curr.y] == 'B') {
			int backx = curr.x, backy = curr.y;
			string path;
			while (locs[backx][backy].dir != '#') {
				path.push_back(locs[backx][backy].dir);
				int x2 = backx;
				backx = locs[x2][backy].x;
				backy = locs[x2][backy].y;
			}
			reverse(path.begin(), path.end());
			cout << "YES\n";
			cout << path.length() << '\n';
			cout << path;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			if (0 <= dx[i] + curr.x and dx[i] + curr.x < n and
				0 <= dy[i] + curr.y and dy[i] + curr.y < m and
				!locs[dx[i] + curr.x][dy[i] + curr.y].visited and 
				grid[dx[i] + curr.x][dy[i] + curr.y] != '#') {
				locs[dx[i] + curr.x][dy[i] + curr.y] = { curr.x, curr.y, 1, direction[i] };
				q.push({ dx[i] + curr.x,dy[i] + curr.y});
			}
		}
	}

	cout << "NO\n";
}