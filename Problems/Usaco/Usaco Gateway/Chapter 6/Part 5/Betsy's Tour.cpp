/*
ID: elijahj1
TASK: betsy
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> dx = { 0,1,0,-1 };
vector<int> dy = { -1,0,1,0 };
int ans = 0;
bool visited[9][9];
int total_visited = 0;

void dfs(int x, int y) {
	visited[x][y] = 1;
	total_visited++;

	if (x == n and y == 1) {
		ans += total_visited == n * n;
		total_visited--;
		visited[x][y] = 0;
		return;
	}

	int total_go = 0;
	int place_go = 0;
	bool bad = 0;
	for (int i = 0; i < 4; i++) {
		if (!(x + dx[i] == n and y + dy[i] == 1) and 
			1 <= x + dx[i] and x + dx[i] <= n and
			1 <= y + dy[i] and y + dy[i] <= n and
			!visited[x + dx[i]][y + dy[i]]) {
			int num_visited = 0;
			for (int j = 0; j < 4; j++) {
				num_visited += visited[x + dx[i] + dx[j]][y + dy[i] + dy[j]];
			}
			if (num_visited >= 3) {
				if (num_visited == 4) {
					bad = 1;
				}
				if (total_go == 1) {
					total_go++;
					break;
				}
				total_go += num_visited >= 3;
				place_go = i;
			}
		}
	}
	if (total_go > 1 or bad) {
		total_visited--;
		visited[x][y] = 0;
		return;
	}
	else if (total_go == 1) {
		dfs(x + dx[place_go], y + dy[place_go]);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (1 <= x + dx[i] and x + dx[i] <= n and
				1 <= y + dy[i] and y + dy[i] <= n and
				!visited[x + dx[i]][y + dy[i]]) {
				if (!(x + dx[i] == n and y + dy[i] == 1) and visited[x + 2 * dx[i]][y + 2 * dy[i]]) {
					continue;
				}
				dfs(x + dx[i], y + dy[i]);
			}
		}
	}

	total_visited--;
	visited[x][y] = 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("betsy.in", "r", stdin); freopen("betsy.out", "w", stdout);
	cin >> n;

	for (int i = 0; i < n + 2; i++) {
		visited[0][i] = visited[i][0] = visited[n + 1][i] = visited[i][n + 1] = 1;
	}
	dfs(1,1);
	cout << ans << '\n';
}