#include<bits/stdc++.h>
using namespace std;

vector<int> dx = { 1,0,-1,0 };
vector<int> dy = { 0,1,0,-1 };
void dfs(int i, int j, vector<vector<int>>& course, vector<vector<bool>>& visited,
	int n, int m, int d) {
	visited[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int i2 = i + dx[k];
		int j2 = j + dy[k];
		if (0 <= i2 and i2 < n and 0 <= j2 and j2 < m and !visited[i2][j2] and
			abs(course[i2][j2] - course[i][j]) <= d) {
			dfs(i2, j2, course, visited, n, m, d);
		}
	}
}

bool test(int d, pair<int,int> awaypoint, vector<vector<int>>& course, 
	vector<vector<bool>>& waypoint, int n, int m) {
	vector<vector<bool>> visited(n, vector<bool>(m));

	dfs(awaypoint.first, awaypoint.second, course, visited, n, m, d);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (waypoint[i][j]) {
				if (!visited[i][j]) {
					return false;
				}
			}
		}
	}

	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("ccski.in", "r", stdin); freopen("ccski.out", "w", stdout);
	int m, n; cin >> m >> n; swap(m, n);
	vector<vector<int>> course(n,vector<int>(m));
	vector<vector<bool>> waypoint(n,vector<bool>(m));
	pair<int, int> awaypoint;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			course[i][j] = a;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			waypoint[i][j] = a;
			if (a) {
				awaypoint = { i,j };
			}
		}
	}

	int L = 0, R = 1e9;
	while (L != R) {
		int d = (L + R) / 2;
		if (test(d, awaypoint, course,waypoint,n,m)) {
			R = d;
		}
		else {
			L = d + 1;
		}
	}

	cout << L;
}