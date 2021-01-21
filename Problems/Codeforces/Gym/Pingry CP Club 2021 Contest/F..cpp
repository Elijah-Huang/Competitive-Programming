#include<bits/stdc++.h>
using namespace std;

struct edge {
	int v, w;
};

int n, m; 
long long min_dist[10001], min_path[1001];
int type[10001];
int type_want = 0;
vector<edge> adj[10001];

void dfs(int c, int p) {
	pair<long long, long long> best_dists{ 1ll << 60,1ll << 60 };

	for (auto& n : adj[c]) {
		if (n.v != p) {
			dfs(n.v, c);

			long long dist = n.w + min_dist[n.v];
			if (dist < best_dists.first) {
				best_dists.second = best_dists.first;
				best_dists.first = dist;
			}
			else if (dist < best_dists.second) {
				best_dists.second = dist;
			}
		}
	}

	if (type[c] == type_want) {
		min_dist[c] = 0;
		min_path[type_want] = min(min_path[type_want], best_dists.first);
	}
	else {
		min_dist[c] = best_dists.first;
		min_path[type_want] = min(min_path[type_want], best_dists.first + best_dists.second);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> type[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}

	memset(min_path, 0x3f, sizeof(min_path));
	for (int i = 1; i <= m; i++) {
		type_want = i;
		memset(min_dist, 0x1f, sizeof(min_dist));
		dfs(1, 0);
	}

	for (int i = 1; i <= m; i++) {
		if (min_path[i] >= 1e13) {
			cout << -1 << ' ';
		}
		else {
			cout << min_path[i] << ' ';
		}
	}
}