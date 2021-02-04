#include<bits/stdc++.h>
using namespace std;

int n, m, q;
vector<int> dx = { 0,1,0,-1 };
vector<int> dy = { -1,0,1,0 };
char grid[1000][1000];
bool visited[1000][1000];
vector<pair<int, int>> vis;
int comps;
int is, js, ie, je;

void dfs(int i, int j) {
	vis.push_back({ i,j });
	visited[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int newi = i + dx[k];
		int newj = j + dy[k];
		if (is <= newi and newi <= ie and
			js <= newj and newj <= je and
			!visited[newi][newj] and
			grid[i][j] == grid[newi][newj]) {
			dfs(newi, newj);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	while (q--) {
		comps = 0;
		vis.clear();

		cin >> is >> js >> ie >> je;
		is--; js--; ie--; je--;
		for (int i = is; i <= ie; i++) {
			for (int j = js; j <= je; j++) {
				if (!visited[i][j]) {
					comps++;
					dfs(i, j);
				}
			}
		}

		cout << comps << '\n';

		for (auto i : vis) {
			visited[i.first][i.second] = 0;
		}
	}
}