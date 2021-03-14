#include<bits/stdc++.h>
using namespace std;

vector<int> dx = { 1,0,-1,0 }, dy = { 0,1,0,-1};
int n, comfortable = 0;
bool grid[1001][1001];
int neighbors[1001][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	while (n--) {
		int x, y; cin >> x >> y;

		grid[x][y] = 1;
		int num_neighbors = 0;
		for (int i = 0; i < 4; i++) {
			if (grid[x + dx[i]][y + dy[i]]) {
				num_neighbors++;
				if (++neighbors[x + dx[i]][y + dy[i]] == 4) {
					comfortable--;
				}
				else if (neighbors[x + dx[i]][y + dy[i]] == 3) {
					comfortable++;
				}
			}
		}
		
		if (3 == (neighbors[x][y] = num_neighbors)) {
			comfortable++;
		}

		cout << comfortable << '\n';
	}
}