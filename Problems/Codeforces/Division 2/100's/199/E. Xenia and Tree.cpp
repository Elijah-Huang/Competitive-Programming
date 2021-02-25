// handle offline via processing blocks of sqrt(n) at a time
#include<bits/stdc++.h>
using namespace std;

const int bsz = 1400; // minimizes the amortized 1e5/bsz + log(1e5)*(bsz/2)^2 per query
const int maxn = 1e5+1;
int n, m;
vector<int> adj[maxn];
pair<int, int> queries[maxn];

// lca stuff
int t, tin[maxn], tout[maxn], depth[maxn];
int ancestor[maxn][20];

void dfs_lca(int c, int p, int d = 0) {
	tin[c] = t++;
	depth[c] = d;

	ancestor[c][0] = p;
	for (int i = 1; i < 20; i++) {
		ancestor[c][i] = ancestor[ancestor[c][i - 1]][i - 1];
	}

	for (auto n : adj[c]) {
		if (n != p) {
			dfs_lca(n, c, d+1);
		}
	}

	tout[c] = t++;
}

bool is_ancestor(int b, int a) {
	return tin[b] <= tin[a] and tout[a] <= tout[b];
}

int lca(int a, int b) {
	if (is_ancestor(a, b)) {
		return a;
	}
	else if (is_ancestor(b, a)) {
		return b;
	}
	else {
		for (int i = 19; i >= 0; i--) {
			if (!is_ancestor(ancestor[a][i], b)) {
				a = ancestor[a][i];
			}
		}
		return ancestor[a][0];
	}
}

// sqrt block optimization stuff
vector<int> red = { 1 };
bool is_red[maxn];
int dist[maxn];
vector<int> updated;

void recompute() {	
	updated.clear();
	
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	for (auto v : red) {
		q.push(v);
		dist[v] = 0;
	}
	while (!q.empty()) {
		int c = q.front(); q.pop();
		for (auto n : adj[c]) {
			if (dist[n] == -1) {
				dist[n] = dist[c] + 1;
				q.push(n);
			}
		}
	}
}

void update(int v) {
	red.push_back(v);
	is_red[v] = 1;
	updated.push_back(v);
}

int answer(int v) {
	int min_dist = dist[v];
	for (auto u : updated) {
		int a = lca(u, v);
		min_dist = min(min_dist, depth[u] + depth[v] - 2 * depth[lca(u, v)]);
	}

	return min_dist;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < m; i++) {
		cin >> queries[i].first >> queries[i].second;
	}

	is_red[1] = 1;
	dfs_lca(1, 1);

	
	for (int i = 0; i < m;) {
		recompute();
			
		for (int end = min(i + bsz, m); i < end; i++) {
			if (queries[i].first == 1) {
				update(queries[i].second);
			}
			else {
				cout << answer(queries[i].second) << '\n';
			}
		}
	}
}