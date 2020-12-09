/*
ID: elijahj1
TASK: frameup
LANG: C++14
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
struct sides {
	int xmin = 30, xmax = -1, ymin = 30, ymax = -1;
};
void dfs(vector<string>& m, vector<string>& orderings, string& ordering, int& h, int& w) {
	unordered_map<char, sides> locations;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char curr = m[i][j];
			if (curr != '.') {
				locations[curr].xmin = min(locations[curr].xmin, i);
				locations[curr].xmax = max(locations[curr].xmax, i);
				locations[curr].ymin = min(locations[curr].ymin, j);
				locations[curr].ymax = max(locations[curr].ymax, j);
			}
		}
	}
	if (locations.empty()) {
		orderings.push_back(ordering);
	}
	else {
		string can_remove;
		for (auto letter : locations) {
			bool fail = false;
			for (int i = letter.second.xmin; i <= letter.second.xmax; i++) {
				if ((m[i][letter.second.ymin] != '.' and m[i][letter.second.ymin] != letter.first)
					or (m[i][letter.second.ymax] != '.' and m[i][letter.second.ymax] != letter.first)) {
					fail = true;
					break;
				}
			}
			for (int i = letter.second.ymin; i <= letter.second.ymax; i++) {
				if ((m[letter.second.xmin][i] != '.' and m[letter.second.xmin][i] != letter.first)
					or (m[letter.second.xmax][i] != '.' and m[letter.second.xmax][i] != letter.first)) {
					fail = true;
					break;
				}
			}
			if (!fail) {
				can_remove.push_back(letter.first);
			}
		}
		for (auto l : can_remove) {
			vector<pair<int, int>> removed;
			sides letter = locations[l];
			for (int i = letter.xmin; i <= letter.xmax; i++) {
				if (m[i][letter.ymin] == l) {
					m[i][letter.ymin] = '.';
					removed.push_back({ i,letter.ymin });
				}
				if (m[i][letter.ymax] == l) {
					m[i][letter.ymax] = '.';
					removed.push_back({ i,letter.ymax });
				}
			}
			for (int i = letter.ymin; i <= letter.ymax; i++) {
				if (m[letter.xmin][i] == l) {
					m[letter.xmin][i] = '.';
					removed.push_back({ letter.xmin, i });
				}
				if (m[letter.xmax][i] == l) {
					m[letter.xmax][i] = '.';
					removed.push_back({ letter.xmax,i });
				}
			}
			ordering.push_back(l);
			dfs(m, orderings, ordering, h, w);
			ordering.pop_back();
			for (auto coord : removed) {
				m[coord.first][coord.second] = l;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("frameup.in","r",stdin); freopen("frameup.out","w",stdout);
	int h, w;
	cin >> h >> w;
	vector<string> m(h);
	vector<string> orderings;
	for (int i = 0; i < h; i++) {
		cin >> m[i];
	}
	string ordering;
	dfs(m, orderings, ordering, h, w);
	for (auto& ordering : orderings) {
		reverse(ordering.begin(), ordering.end());
	}
	sort(orderings.begin(), orderings.end());
	for (auto ordering : orderings) {
		cout << ordering << '\n';
	}
}