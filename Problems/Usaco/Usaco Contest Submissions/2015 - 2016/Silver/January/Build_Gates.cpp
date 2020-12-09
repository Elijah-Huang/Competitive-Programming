#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> delta = { {1,0},{0,1},{-1,0},{0,-1} };
void dfs(int x, int y, bool fences[2005][2005]) {
	fences[x][y] = 1;
	for (auto d : delta) {
		int new_x = x + d.first;
		int new_y = y + d.second;
		if (2005 > new_x and new_x >= 0 and 2005 > new_y and new_y >= 0
			and !fences[new_x][new_y]) {
			dfs(new_x, new_y, fences);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("gates.in", "r", stdin); freopen("gates.out", "w", stdout);
	int components = -1;
	bool fences[2005][2005]{};
	int n;
	cin >> n;
	int x = 1002, y = 1002;
	while (n--) {
		char direction;
		cin >> direction;
		if (direction == 'N') {
			y++;
			fences[x][y] = 1;
			y++;
			fences[x][y] = 1;
		}
		else if (direction == 'S') {
			y--;
			fences[x][y] = 1;
			y--;
			fences[x][y] = 1;
		}
		else if (direction == 'E') {
			x++;
			fences[x][y] = 1;
			x++;
			fences[x][y] = 1;
		}
		if (direction == 'W') {
			x--;
			fences[x][y] = 1;
			x--;
			fences[x][y] = 1;
		}
	}
	for (int x = 0; x < 2005; x++) {
		for (int y = 0; y < 2005; y++) {
			if (!fences[x][y]) {
				components++;
				dfs(x, y, fences);
			}
		}
	}
	cout << components;
}