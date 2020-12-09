#include<bits/stdc++.h>
using namespace std;

vector<int> dx = { 0,1,0,-1 };
vector<int> dy = { -1,0,1,0 };

vector<string> grid;
int dists[20][20][20][20][4][4];

struct loc {
	int x1, y1, x2, y2, dir1, dir2, dist;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cownav.in", "r", stdin); freopen("cownav.out", "w", stdout);
	int n; cin >> n;
	grid.resize(n,string(n,' '));
	for (int i = 0; i < n; i++) {
		string col; cin >> col;
		for (int i2 = 0; i2 < n; i2++) {
			grid[i2][n - 1 - i] = col[i2];
		}
	}

	int most = 0x7f7f7f7f;
	memset(dists, 0x7f, sizeof(dists));
	queue<loc> q;
	q.push({ 0,0,0,0,1,2,0 });
	while (!q.empty()) {
		loc curr = q.front(); q.pop();
		//cout << curr.x1 << ' ' << curr.y1 << ' ' << curr.x2 << ' ' << curr.y2 << ' ' << curr.dir1 << ' ' << curr.dir2 << ' ' << curr.dist << '\n';
		if (dists[curr.x1][curr.y1][curr.x2][curr.y2][curr.dir1][curr.dir2] == most) {
			dists[curr.x1][curr.y1][curr.x2][curr.y2][curr.dir1][curr.dir2] = curr.dist;
			
			q.push({ curr.x1,curr.y1,curr.x2,curr.y2,(curr.dir1 + 1) % 4,(curr.dir2 + 1) % 4, curr.dist + 1 });
			q.push({ curr.x1,curr.y1,curr.x2,curr.y2,(curr.dir1 - 1 + 4) % 4,(curr.dir2 - 1 + 4) % 4, curr.dist + 1 });

			if ((curr.x1 != n - 1 or curr.y1 != n - 1) and 
				0 <= curr.x1 + dx[curr.dir1] and curr.x1 + dx[curr.dir1] < n and
				0 <= curr.y1 + dy[curr.dir1] and curr.y1 + dy[curr.dir1] < n and
				grid[curr.x1 + dx[curr.dir1]][curr.y1 + dy[curr.dir1]] == 'E') {
				curr.x1 += dx[curr.dir1];
				curr.y1 += dy[curr.dir1];
			}
			if ((curr.x2 != n - 1 or curr.y2 != n - 1) and
				0 <= curr.x2 + dx[curr.dir2] and curr.x2 + dx[curr.dir2] < n and
				0 <= curr.y2 + dy[curr.dir2] and curr.y2 + dy[curr.dir2] < n and
				grid[curr.x2 + dx[curr.dir2]][curr.y2 + dy[curr.dir2]] == 'E') {
				curr.x2 += dx[curr.dir2];
				curr.y2 += dy[curr.dir2];
			}
			curr.dist++;
			q.push(curr);
		}
	}

	int best = 1 << 30;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			//cout << dists[n - 1][n - 1][n - 1][n - 1][i][j] << '\n';
			best = min(best, dists[n - 1][n - 1][n - 1][n - 1][i][j]);
		}
	}
	
	cout << best << '\n';
}