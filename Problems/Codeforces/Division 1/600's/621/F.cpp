#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n, k, r, v;
vector<int> adj[2 * maxn];
int last_rest[2 * maxn]; // acts as visited and stores rest stop that reached vertex first
int dist[2 * maxn];

struct DSU {
	int n;
	vector<int> parent;
	vector<int> sizes;

	DSU() {}
	DSU(int n) {
		this->n = n;
		parent.resize(n + 1);
		iota(parent.begin(), parent.end(), 0);
		sizes.resize(n + 1);
		fill(sizes.begin(), sizes.end(), 1);
	}

	int find_parent(int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = find_parent(parent[x]);
	}

	bool union_sets(int a, int b) {
		a = find_parent(a);
		b = find_parent(b);

		if (a != b) {
			if (sizes[a] < sizes[b]) {
				swap(a, b);
			}

			parent[b] = a;
			sizes[a] += sizes[b];

			return 1;
		}

		return 0;
	}
};

DSU rest_comps(maxn);

int ancestor[2 * maxn][20];
int tin[2 * maxn], tout[2 * maxn], t = 0;
int depth[2 * maxn];

void dfs(int c, int p, int d = 0) {
	tin[c] = t++;

	depth[c] = d;

	ancestor[c][0] = p;
	for (int i = 1; i < 20; i++) {
		ancestor[c][i] = ancestor[ancestor[c][i - 1]][i - 1];
	}

	for (auto ne : adj[c]) {
		if (ne != p) {
			dfs(ne, c, d+1);
		}
	}

	tout[c] = t++;
}

bool is_ancestor(int a, int b) {
	return tin[a] <= tin[b] and tout[b] <= tout[a];
}

int lca(int a, int b) {
	if (is_ancestor(a, b)) {
		return a;
	}
	
	if (is_ancestor(b, a)) {
		return b;
	}

	for (int i = 19; i >= 0; i--) {
		if (!is_ancestor(ancestor[a][i], b)) {
			a = ancestor[a][i];
		}
	}
	return ancestor[a][0];
}

// proof for why walking k works is to consider the optimal path
// if it does not exist then comps will def be diff since we limit bfs to k and we walk k
// if it does exist, the comp must be the same because the path consists edges length at most k between 
// the start, rest stops, and end. Every edge must be connected either by the bfs or by walking k 
// from start or end to the component formed from the bfs
int walk(int a, int b) {
	int c = lca(a, b);
	
	int amt = k;
	if (depth[a] - depth[c] < k) {
		amt = depth[b] - depth[c] - (k - (depth[a] - depth[c]));
		a = b;
	}
	
	for (int i = 19, curr = 0; i >= 0; i--) {
		if (curr + (1 << i) <= amt) {
			a = ancestor[a][i];
			curr += (1 << i);
		}
	}

	return a;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> k >> r;

	for (int i = 0; i < n-1; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(maxn + i);
		adj[maxn + i].push_back(x);
		adj[maxn + i].push_back(y);
		adj[y].push_back(maxn + i);
	}

	// setup lca
	dfs(1, 1);

	queue<int> q;
	for (int i = 0; i < r; i++) {
		int x; cin >> x;
		last_rest[x] = x;
		q.push(x);
	}

	// create components where rest stops can reach all other rest stops in the component
	while (!q.empty()) {
		int curr = q.front(); q.pop();

		if (dist[curr] < k) {
			for (auto ne : adj[curr]) {
				if (last_rest[ne]) {
					rest_comps.union_sets(last_rest[curr], last_rest[ne]);
				}
				else {
					dist[ne] = dist[curr] + 1;
					last_rest[ne] = last_rest[curr];
					q.push(ne);
				}
			}
		}
	}

	cin >> v;
	while (v--) {
		int a, b; cin >> a >> b;

		if (depth[a] + depth[b] - 2 * depth[lca(a, b)] <= 2*k) {
			cout << "YES" << '\n';
		}
		else {
			int compa = rest_comps.find_parent(last_rest[walk(a, b)]);
			int compb = rest_comps.find_parent(last_rest[walk(b, a)]);
			if (compa == compb and compa != 0) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
}