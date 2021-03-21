#include<bits/stdc++.h>
using namespace std;

const int maxn = 500;
// 0 -> row maxes 1 -> col
int a[maxn][maxn], b[maxn][maxn];
int t, n;

// for mst
vector<pair<int,int>> adj[2*maxn];
bool visited[2*maxn];
vector<vector<int>> comps;
// idx in original graph -> idx in comp
int convert[2*maxn];
vector<int> dist;

void dfs(int c) {
	visited[c] = 1;
	comps.back().push_back(c);
	convert[c] = comps.back().size() - 1;

	for (auto n : adj[c]) {
		if (!visited[n.first]) {
			dfs(n.first);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int i = 1; i <= t; i++) {
		fill(adj, adj + 2 * maxn, vector<pair<int, int>>());
		fill(visited, visited + 2 * maxn, 0);
		comps.resize(0);
		int tot = 0, tot_msts_weight = 0;

		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> b[i][j];
				tot += b[i][j];

				if (b[i][j]) {
					adj[i].push_back({ n + j, b[i][j] });
					adj[n + j].push_back({ i, b[i][j] });
				}
			}
		}

		// don't need R or C
		for (int i = 0; i < 2 * n; i++) {
			int c; cin >> c;
		}


		// find connected components
		for (int i = 0; i < 2 * n; i++) {
			if (!visited[i]) {
				comps.resize(comps.size() + 1);
				dfs(i);
			}
		}


		// find msts for connected components
		for (auto& comp : comps) {
			dist = vector<int>(comp.size(), -1);
			dist[0] = 0;

			for (int i = 0; i < comp.size(); i++) {
				int nxt = -1, d = -1;
				for (int j = 0; j < comp.size(); j++) {
					if (dist[j] > d) {
						nxt = j;
						d = dist[j];
					}
				}

				tot_msts_weight += d;
				dist[nxt] = -2;
				for (auto n : adj[comp[nxt]]) {
					if (dist[convert[n.first]] == -2) continue;
					dist[convert[n.first]] = max(dist[convert[n.first]], n.second);
				}
			}
		}

		cout << "Case #" << i << ": " << tot - tot_msts_weight << '\n';
	}
}