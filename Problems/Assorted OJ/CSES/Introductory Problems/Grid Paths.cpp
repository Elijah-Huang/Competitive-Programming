#include<bits/stdc++.h>
using namespace std;

string desired;
string dir = "LDRU";
vector<int> dx = { 0,1,0,-1 };
vector<int> dy = { -1,0,1,0 };
int ans = 0;
bool visited[9][9];
int total_visited = 0;

void dfs(int x, int y) {
	visited[x][y] = 1;
	total_visited++;

	if (x == 7 and y == 1) {
		ans += total_visited == 49;
		total_visited--;
		visited[x][y] = 0;
		return;
	}

	int total_go = 0;
	int place_go = 0;
	bool bad = 0;
	for (int i = 0; i < 4; i++) {
		if (!(x + dx[i] == 7 and y + dy[i] == 1) and
			1 <= x + dx[i] and x + dx[i] <= 7 and
			1 <= y + dy[i] and y + dy[i] <= 7 and
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
		if (desired[total_visited - 1] == '?' or desired[total_visited - 1] == dir[place_go]) {
			dfs(x + dx[place_go], y + dy[place_go]);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (desired[total_visited - 1] != '?' and desired[total_visited - 1] != dir[i]) continue;
			if (1 <= x + dx[i] and x + dx[i] <= 7 and
				1 <= y + dy[i] and y + dy[i] <= 7 and
				!visited[x + dx[i]][y + dy[i]]) {
				if (!(x + dx[i] == 7 and y + dy[i] == 1) and visited[x + 2 * dx[i]][y + 2 * dy[i]]) {
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
	cin >> desired;

	for (int i = 0; i < 9; i++) {
		visited[0][i] = visited[i][0] = visited[8][i] = visited[i][8] = 1;
	}
	dfs(1, 1);

	cout << ans << '\n';
}