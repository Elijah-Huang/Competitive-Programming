#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> moves;
// adj_p is an edge from the product needed to the shop that has a duplicate of it
// adj_s is an edge from the shop to the product that it needs (has none of)
vector<int> adj_p[400], adj_s[400];
int row[400 * 400+1];

int shop(int x) {
	return (x - 1) / m;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<vector<int>> counts(m);

		for (int j = 0; j < m; j++) {
			int a; cin >> a; a--;
			row[i * m + j] = a;
			counts[a].push_back(i*m+j+1);
		}
		
		for (int j = 0; j < m; j++) {
			if (counts[j].size() == 0) {
				adj_s[i].push_back(j);
			}
			else if (counts[j].size() > 1) {
				for (int k = 1; k < counts[j].size(); k++) {
					adj_p[j].push_back(counts[j][k]);
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (!adj_p[i].empty()) {
			// 1 if shop else 0 if product request
			vector<pair<int, int>> s = { {1,adj_p[i].back()} };
			vector<int> path = { n * m + 1 };
			adj_p[i].pop_back();

			while (!s.empty()) {
				pair<int,int> c = s.back();

				if (c.first) {
					if (adj_s[shop(c.second)].empty()) {
						path.push_back(s.back().second);
						s.pop_back();
					}
					else {
						s.push_back({ 0,adj_s[shop(c.second)].back() });
						adj_s[shop(c.second)].pop_back();
					}
				}
				else {
					if (adj_p[c.second].empty()) {
						s.pop_back();
					}
					else {
						s.push_back({ 1,adj_p[c.second].back() });
						adj_p[c.second].pop_back();
					}
				}
			}
			path.push_back(n * m + 1);

			for (int i = path.size() - 2; i >= 0; i--) {
				moves.push_back({ path[i],path[i + 1] });
			}
		}
	}
	
	cout << moves.size() << '\n';
	for (auto i : moves) {
		swap(row[i.first - 1], row[i.second - 1]);
		cout << i.first << ' ' << i.second << '\n';
	}

	/*
	for (int i = 0; i < n; i++) {
		sort(row + i * m, row + (i + 1) * m);
		for (int j = 0; j < m; j++) {
			assert(row[i * m + j] == j);
		}
	}
	*/
}