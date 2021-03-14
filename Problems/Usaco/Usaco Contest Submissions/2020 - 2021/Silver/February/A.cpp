// O(max_x*max_y + n)
#include<bits/stdc++.h>
using namespace std;

vector<int> dx = { 0,0,1,0,-1 };
vector<int> dy = { 0,-1,0,1,0 };

int n, added_cows = 0;
int bufferx = 750, buffery = 750;
// 0-> empty   1-> we need to add this   2-> this is one of the N cows
int grid[2500][2500];

// call dfs function each time we add a new point
void dfs(int x, int y) {
	for (int i = 0; i < 5; i++) {
		// coords of point affected by adding current point
		int nx = x + dx[i], ny = y + dy[i];

		if (grid[nx][ny] != 0) {
			// find # of neighbors and an empty neighboring point if possible
			int ex, ey, tot_neighbors = 0;
			for (int j = 1; j < 5; j++) {
				if (grid[nx + dx[j]][ny + dy[j]] == 0) {
					ex = nx + dx[j], ey = ny + dy[j];
				}
				else {
					tot_neighbors += 1;
				}
			}

			// if tot neighbors = 3 add cow in empty neighboring point and dfs from it
			if (tot_neighbors == 3) {
				grid[ex][ey] = 1;
				added_cows += 1;
				dfs(ex, ey);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	while (n--) {
		int x, y; cin >> x >> y;
		x += bufferx, y += buffery;

		if (grid[x][y] == 0) {
			grid[x][y] = 2;
			dfs(x, y);
		}
		else if (grid[x][y] == 1) {
			// cow has walked in and we don't need to add it anymore (it's already there)
			added_cows -= 1;
			grid[x][y] = 2;
		}

		cout << added_cows << '\n';
	}
}