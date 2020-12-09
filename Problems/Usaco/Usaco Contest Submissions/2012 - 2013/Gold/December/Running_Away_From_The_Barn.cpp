#include<bits/stdc++.h>
using namespace std;

struct edge {
	long long v, w;
};

int n;
long long l;
int t = 0;
const int maxn = 2e5 + 1;
int ans[maxn], num_furthest[maxn], sizes[maxn], tin[maxn], top_segment[maxn], parent[maxn], time_to_vertex[maxn];
long long dist[maxn], dist2[maxn];
vector<edge> adj[maxn];

void dfs_dist(int curr) {
	for (auto& neighbor : adj[curr]) {
		dist[neighbor.v] = dist[curr] + neighbor.w;
		dfs_dist(neighbor.v);
	}
}

void dfs_size(int curr) {
	for (auto& neighbor : adj[curr]) {
		dfs_size(neighbor.v);
		sizes[curr] += sizes[neighbor.v];
		if (sizes[neighbor.v] > sizes[adj[curr][0].v]) {
			swap(neighbor, adj[curr][0]);
		}
	}
	sizes[curr]++;
}

void dfs_hld (int curr) {
	tin[curr] = ++t;
	dist2[t] = dist[curr];
	time_to_vertex[t] = curr;

	for (auto& neighbor : adj[curr]) {
		top_segment[neighbor.v] = (neighbor.v == adj[curr][0].v ? top_segment[curr] : neighbor.v);
		dfs_hld(neighbor.v);
	}
}

int find_furthest(int curr) {
	int furthest = curr;
	while (furthest != 0) {
		if (top_segment[furthest] == furthest) {
			if (dist[curr] - dist[parent[furthest]] > l) {
				return furthest;
			}
			else {
				furthest = parent[furthest];
			}
		}
		else {
			int l2 = tin[top_segment[furthest]], r2 = tin[furthest];
			while (l2 != r2) {
				int m = (l2 + r2) / 2;
				if (dist[curr] - dist2[m] <= l) {
					r2 = m;
				}
				else {
					l2 = m + 1;
				}
			}
			furthest = time_to_vertex[l2];
			if (dist[curr] - dist[parent[furthest]] > l) {
				return furthest;
			}
		}
	}

	return furthest;
}

void solve(int curr) {
	for (auto& neighbor : adj[curr]) {
		solve(neighbor.v);
		ans[curr] += ans[neighbor.v] - num_furthest[neighbor.v];
	}
	ans[curr]++;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("runaway.in", "r", stdin); freopen("runaway.out", "w", stdout);
	cin >> n >> l;
	for (int i = 0; i < n-1; i++) {
		long long a, w; cin >> a >> w;
		parent[i + 2] = a;
		adj[a].push_back({ i + 2,w });
	}

	dfs_dist(1);

	dfs_size(1);
	top_segment[1] = 1;
	dfs_hld(1);

	for (int i = 1; i <= n; i++) {
		num_furthest[find_furthest(i)]++;
	}

	solve(1);

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << '\n';
	}
}