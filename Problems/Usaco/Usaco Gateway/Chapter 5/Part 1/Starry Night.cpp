/*
ID: elijahj1
TASK: starry
LANG: C++14
*/
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
struct point {
	int x, y;
	bool operator==(const point& b) const {
		return x == b.x and y == b.y;
	}
};
struct point_hash {
	size_t operator()(const point& a) const {
		return a.x ^ a.y;
	}
};
void dfs(point curr, vector<vector<int>>& taken, unordered_set<point, point_hash>& visited,
	vector<string>& sky, int& h, int& w) {
	visited.insert(curr);
	taken[curr.x][curr.y] = 1;
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			point neighbor = point{ curr.x + x, curr.y + y };
			if (0 <= neighbor.x and neighbor.x < h and 0 <= neighbor.y 
				and neighbor.y <= w and sky[neighbor.x][neighbor.y] == '1' 
				and visited.count(neighbor) == 0) {
				dfs(point{ curr.x + x, curr.y + y }, taken, visited, sky, h, w);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("starry.in", "r", stdin); freopen("starry.out", "w", stdout);
	int h, w;
	cin >> w >> h;
	vector<string> sky(h);
	vector<string> sky_lettered(h, string(w, ' '));
	vector<vector<int>> taken(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		cin >> sky[i];
	}
	vector<vector<vector<int>>> clusters;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (sky[i][j] == '1' and !taken[i][j]) {
				unordered_set<point, point_hash> visited;
				dfs(point{ i,j }, taken, visited, sky, h, w);
				int mn_x = 101;
				int mx_x = 0;
				int mn_y = 101;
				int mx_y = 0;
				for (point p : visited) {
					mn_x = min(mn_x, p.x);
					mx_x = max(mx_x, p.x);
					mn_y = min(mn_y, p.y);
					mx_y = max(mx_y, p.y);
				}
				vector<vector<vector<int>>> cluster;
				vector<vector<int>> curr(mx_x - mn_x + 1, vector<int>(mx_y - mn_y + 1));
				for (point p : visited) {
					curr[p.x - mn_x][p.y - mn_y] = 1;
				}
				vector<vector<int>> curr2(mx_y - mn_y + 1, vector<int>(mx_x - mn_x + 1));
				for (int j = 0; j <= mx_y - mn_y; j++) {
					for (int i = mx_x - mn_x; i >= 0; i--) {
						curr2[j][mx_x-mn_x-i] = curr[i][j];
					}
				}
				for (int i = 0; i < 2; i++) {
					cluster.push_back(curr);
				}
				for (auto &row : cluster[1]) {
					reverse(row.begin(), row.end());
				}
				cluster.push_back(cluster[0]); 
				cluster.push_back(cluster[1]);
				reverse(cluster[2].begin(), cluster[2].end());
				reverse(cluster[3].begin(), cluster[3].end());
				for (int i = 0; i < 2; i++) {
					cluster.push_back(curr2);
				}
				for (auto &row : cluster[5]) {
					reverse(row.begin(), row.end());
				}
				cluster.push_back(cluster[4]);
				cluster.push_back(cluster[5]);
				reverse(cluster[6].begin(), cluster[6].end());
				reverse(cluster[7].begin(), cluster[7].end());
				/*
				for (auto c : cluster) {
					for (auto r : c) {
						for (auto i : r) {
							cout << i;
						}
						cout << '\n';
					}
					cout << '\n';
				}
				*/
				bool same = false;
				char letter;
				for (int a = 0; a < clusters.size(); a++) {
					if (same) break;
					auto d = clusters[a];
					for (auto c : cluster) {
						if (c.size() == d.size() and c[0].size() == d[0].size()) {
							bool all_same = true;
							for (int i = 0; i < c.size(); i++) {
								if (!all_same) break;
								for (int j = 0; j < c[0].size(); j++) {
									if (c[i][j] != d[i][j]) {
										all_same = false;
										break;
									}
								}
							}
							if (all_same) {
								letter = char('a' + a);
								same = true;
								break;
							}
						}
					}
				}
				if (!same) {
					clusters.push_back(cluster[0]);
					letter = char('a' + clusters.size() - 1);
				}
				for (auto p : visited) {
					sky_lettered[p.x][p.y] = letter;
				}
			}
		}
	}
	/*
	for (auto c : clusters) {
		for (auto row : c) {
			for (auto i : row) {
				cout << i;
			}
			cout << '\n';
		}
		cout << '\n';
	}
	*/
	for (auto row : sky_lettered) {
		cout << row << '\n';
	}
}