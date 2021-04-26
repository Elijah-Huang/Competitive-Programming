#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int n, m;
vector<vector<pair<int,int>>> adj(maxn);

int max_p;
vector<vector<int>> ancestor;
int t = 0;
int tin[maxn], tout[maxn], dist[maxn];
map<string, int> convert;

void dfs(int curr, int parent) {
	tin[curr] = t++;

	ancestor[curr][0] = parent;
	for (int i = 1; i <= max_p; i++) {
		ancestor[curr][i] = ancestor[ancestor[curr][i - 1]][i - 1];
	}

	for (auto neighbor : adj[curr]) {
		if (neighbor.first != parent) {
			dist[neighbor.first] = dist[curr] + neighbor.second;
			dfs(neighbor.first, curr);
		}
	}

	tout[curr] = t++;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] and tout[v] <= tout[u];
}

int lca(int u, int v) {
	if (is_ancestor(u, v)) {
		return u;
	}
	else if (is_ancestor(v, u)) {
		return v;
	}
	else {
		for (int i = max_p; i >= 0; i--) {
			if (!is_ancestor(ancestor[u][i], v)) {
				u = ancestor[u][i];
			}
		}
		return ancestor[u][0];
	}
}

void precompute(int root) {
	max_p = ilogb(maxn - 2);
	ancestor.assign(maxn, vector<int>(max_p + 1));
	dfs(root, root);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	int str = 1;
	for (int i = 0; i < n - 1; i++) {
		string a, b; cin >> a >> b;
		int w; cin >> w;
		if (!convert.count(a)) {
			convert[a] = str++;
		}
		if (!convert.count(b)) {
			convert[b] = str++;
		}

		adj[convert[a]].push_back({ convert[b], w });
		adj[convert[b]].push_back({ convert[a], -w });
	}

	precompute(1);

	while (m--) {
		string a, b; cin >> a >> b;
		int a2 = convert[a];
		int b2 = convert[b];
		
		// just realized didn't need lca since dist cancels out lol
		cout << -(dist[a2] - dist[lca(a2, b2)]) + dist[b2] - dist[lca(a2, b2)] << '\n';
	}
}