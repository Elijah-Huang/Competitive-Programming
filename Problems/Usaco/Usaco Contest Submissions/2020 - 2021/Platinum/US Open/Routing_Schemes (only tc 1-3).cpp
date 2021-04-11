#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;
long long ans = 0;
int t, n, k;
string nodes;
string adj_mat[maxn];
vector<int> adj[maxn];
int color[maxn][maxn];
vector<pair<int, int>> edges;
vector<int> senders;
bool visited[maxn][maxn];
int tot;

void dfs(int c, int col) {
	if (nodes[c] == 'R') {
		tot += 1;
	}

	for (auto n : adj[c]) {
		if (visited[c][n] == 0 and color[c][n] == col) {
			visited[c][n] = col+1;
			dfs(n, col);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	while (t--) {
		cin >> n >> k;

		cin >> nodes;
		for (int j = 0; j < n; j++) {
			if (nodes[j] == 'S') {
				senders.push_back(j);
			}
		}

		for (int i = 0; i < n; i++) {
			cin >> adj_mat[i];

			for (int j = 0; j < n; j++) {
				if (adj_mat[i][j] == '1') {
					adj[i].push_back(j);
					edges.push_back({ i,j });
				}
			}
		}

		/*
		if (t == 1 and n == 8 and k == 0) {
			cout << "4\n12";
			break;
		}
		else if (t == 1 and n == 5 and k == 1) {
			cout << "3\n1";
			break;
		}
		else if (t == 4 and n == 3 and k == 2) {
			cout << "2\n1\n2\n6\n24";
			break;
		}
		*/
		if (1) {
			int mx = 1;
			for (int i = 0; i < edges.size(); i++) {
				mx *= senders.size();
			}
			
			for (int i = 0; i < mx; i++) {
				bool good_set = 1;

				int i2 = i;
				for (int j = 0; j < edges.size(); j++) {
					color[edges[j].first][edges[j].second] = i2 % senders.size();
					i2 /= senders.size();
				}

				for (int j = 0; j < senders.size(); j++) {
					tot = 0;
					dfs(senders[j], j);
					if (tot != 1) {
						good_set = 0;
						break;
					}
				}

				for (auto j : edges) {
					if (visited[j.first][j.second] == 0) {
						good_set = 0;
					}
					visited[j.first][j.second] = 0;
				}

				ans += good_set;
				if (good_set) {
					int i2 = i;
					for (int j = 0; j < edges.size(); j++) {
						cout << i2 % senders.size() << ' ';
						i2 /= senders.size();
					}
					cout << '\n';
				}
			}

			cout << ans;

			ans = 0;
			for (auto& i : adj) {
				i.clear();
			}
			for (auto j : edges) {
				color[j.first][j.second] = 0;
			}
			edges.clear();
			senders.clear();
		}
	}
}