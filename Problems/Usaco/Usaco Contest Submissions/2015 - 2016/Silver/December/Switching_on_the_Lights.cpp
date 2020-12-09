#include<bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("lightson.in", "r", stdin); freopen("lightson.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<point> switches[101][101];
	bool lit[101][101]{}, visited[101][101]{};
	int lit_size = 0;
	while (m--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		switches[x][y].push_back(point{ a,b });
	}
	vector<point> extended({ point{1,1} });
	lit[1][1] = true;
	vector<pair<int, int>> delta = { {1,0},{0,1},{-1,0},{0,-1} };
	bool extension = true;
	while (extension) {
		extension = false;
		vector<point> extended2;
		for (auto p : extended) {
			if (visited[p.x][p.y]) continue;
			for (auto neighbor : switches[p.x][p.y]) {
				if (!lit[neighbor.x][neighbor.y]) {
					lit[neighbor.x][neighbor.y] = true;
					for (auto d : delta) {
						if (visited[neighbor.x + d.first][neighbor.y + d.second]) {
							extension = true;
							extended2.push_back(neighbor);
							break;
						}
					}
				}
			}
		}
		for (auto p : extended) {
			if (visited[p.x][p.y]) continue;
			visited[p.x][p.y] = true;
			for (auto d : delta) {
				if (lit[p.x + d.first][p.y + d.second] and !visited[p.x + d.first][p.y + d.second]) {
					extension = true;
					extended2.push_back(point{ p.x + d.first,p.y + d.second });
				}
			}
		}
		extended = extended2;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			lit_size += lit[i][j];
		}
	}
	cout << lit_size;
	
}