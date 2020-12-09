/*
ID: elijahj1
TASK: snail
LANG: C++14
*/
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct point {
	int i, j;
	bool operator==(const point& a) const {
		return i == a.i and j == a.j;
	}
};

struct point_hash {
	size_t operator()(const point& a) const {
		return a.i ^ a.j;
	}
};

void dfs(point curr, char direction, vector<string>& grid, 
	unordered_set<point, point_hash>& path, int& max_length) {
	vector<point> added_path;
	do {
		path.insert(curr);
		added_path.push_back(curr);
		max_length = max(max_length, (int)path.size());
		if (direction == 'L') curr.j--;
		else if (direction == 'R') curr.j++;
		else if (direction == 'D') curr.i++;
		else if (direction == 'U') curr.i--;
	} while (grid[curr.i][curr.j] != '#' and path.count(curr) == 0);
	/*
	cout << curr.i << ' ' << curr.j << '\n';
	cout << path.size() << '\n';
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (path.count(point{ i,j })) {
				cout << 'X';
			}
			else {
				cout << grid[i][j];
			}
		}
		cout << '\n';
	}
	cout << '\n';
	*/
	if (grid[curr.i][curr.j] == '#') {
		if (direction == 'L') {
			curr.j++;
			if (grid[curr.i + 1][curr.j] == '.') {
				dfs(curr, 'D', grid, path, max_length);
			}
			if (grid[curr.i - 1][curr.j] == '.') {
				dfs(curr, 'U', grid, path, max_length);
			}
		}
		else if (direction == 'R') {
			curr.j--;
			if (grid[curr.i + 1][curr.j] == '.') {
				dfs(curr, 'D', grid, path, max_length);
			}
			if (grid[curr.i - 1][curr.j] == '.') {
				dfs(curr, 'U', grid, path, max_length);
			}
		}
		else if (direction == 'D') {
			curr.i--;
			if (grid[curr.i][curr.j - 1] == '.') {
				dfs(curr, 'L', grid, path, max_length);
			}
			if (grid[curr.i][curr.j + 1] == '.') {
				dfs(curr, 'R', grid, path, max_length);
			}
		}
		else if (direction == 'U') {
			curr.i++;
			if (grid[curr.i][curr.j - 1] == '.') {
				dfs(curr, 'L', grid, path, max_length);
			}
			if (grid[curr.i][curr.j + 1] == '.') {
				dfs(curr, 'R', grid, path, max_length);
			}
		}
	}
	for (int i = 1; i < added_path.size(); i++) {
		path.erase(added_path[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("snail.in", "r", stdin); freopen("snail.out", "w", stdout);
	int n, b;
	cin >> n >> b;
	vector<string> grid(n + 2, string(n + 2, '.'));
	grid[0] = string(n + 2, '#');
	grid[n + 1] = string(n + 2, '#');
	for (int i = 1; i < n + 1; i++) {
		grid[i][0] = '#';
		grid[i][n + 1] = '#';
	}
	string curr;
	while (b--) {
		cin >> curr;
		grid[stoi(curr.substr(1,curr.size()-1))][curr[0] - 'A' + 1] = '#';
	}
	/*
	for (auto s : grid) {
		cout << s << '\n';
	}*/
	unordered_set<point, point_hash> path;
	int max_length = 0;
	dfs(point{ 1,1 }, 'R', grid, path, max_length);
	dfs(point{ 1,1 }, 'D', grid, path, max_length);
	cout << max_length << '\n';
}