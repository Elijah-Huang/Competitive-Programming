#include<bits/stdc++.h>
using namespace std;

vector<int> dx = { 1,0,-1,0 };
vector<int> dy = { 0,1,0,-1 };

int n, m;
bool visited[1000][1000];
vector<string> grid;

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		if (0 <= dx[i] + x and dx[i] + x < n and
			0 <= dy[i] + y and dy[i] + y < m and
			!visited[dx[i] + x][dy[i] +y] and grid[dx[i]+x][dy[i]+y] == '.') {
			dfs(dx[i] + x, dy[i] + y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	grid.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	int components = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] and grid[i][j] == '.') {
				components++;
				dfs(i, j);
			}
		}
	}

	cout << components;
}