#include<bits/stdc++.h>
using namespace std;

string direction = "LDRU";
vector<int> dx = { 0,1,0,-1 };
vector<int> dy = { -1,0,1,0 };
string grid[1000];
int dists[2][1000][1000];
char parent[1000][1000];

struct loc {
	int i, j;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	queue<loc> q1, q2;
	memset(dists[1], -1, sizeof(dists[1]));
	memset(dists[0], -1, sizeof(dists[0]));
	for (int i = 0; i < n; i++) {
		fill(parent[i], parent[i] + m, '#');
	}
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'A') {
				q2.push({ i,j });
				dists[1][i][j] = 0;
			}
			else if (grid[i][j] == 'M') {
				q1.push({ i,j });
				dists[0][i][j] = 0;
			}
		}
	}

	while (!q1.empty()) {
		loc curr = q1.front(); q1.pop();

		for (int i = 0; i < 4; i++) {
			int new_i = curr.i + dx[i];
			int new_j = curr.j + dy[i];
			if (0 <= new_i and new_i < n and
				0 <= new_j and new_j < m and
				grid[new_i][new_j] != '#' and
				dists[0][new_i][new_j] == -1) {
				dists[0][new_i][new_j] = dists[0][curr.i][curr.j] + 1;
				q1.push({ new_i, new_j });
			}
		}
	}

	while (!q2.empty()) {
		loc curr = q2.front(); q2.pop();

		if (curr.i == 0 or curr.i == n - 1 or
			curr.j == 0 or curr.j == m - 1) {
			cout << "YES\n";
			string path;
			char move = parent[curr.i][curr.j];
			while (move != '#') {
				path.push_back(move);
				int i = direction.find(move);
				curr.i -= dx[i];
				curr.j -= dy[i];
				move = parent[curr.i][curr.j];
			}
			reverse(path.begin(), path.end());
			cout << path.size() << '\n';
			cout << path;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int new_i = curr.i + dx[i];
			int new_j = curr.j + dy[i];
			if (0 <= new_i and new_i < n and
				0 <= new_j and new_j < m and
				grid[new_i][new_j] != '#' and
				dists[1][new_i][new_j] == -1 and 
				(dists[0][new_i][new_j] > 1 + dists[1][curr.i][curr.j] or
				dists[0][new_i][new_j] == -1)) {
				dists[1][new_i][new_j] = dists[1][curr.i][curr.j] + 1;
				parent[new_i][new_j] = direction[i];
				q2.push({ new_i, new_j });
			}
		}
	}
	
	cout << "NO\n";
}