// O(n) 
// maximum distance must be one of the endpoints of the diameter via proof by contradiction
#include<bits/stdc++.h>
using namespace std;

int n;
const int maxn = 2e5 + 1;
vector<int> adj[maxn];
int dist[maxn], max_dist[maxn];
int furthest, dist_furthest;

// dfs to find the dist from root to every other node
void dfs(int c, int p) {
	for (auto n : adj[c]) {
		if (n != p) {
			dist[n] = dist[c] + 1;
			dfs(n, c);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// find first endpoint of diameter
	dfs(1, 1);
	dist_furthest = -1;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > dist_furthest) {
			furthest = i;
			dist_furthest = dist[i];
		}
	}

	// find second endpoint of diameter
	dist[furthest] = 0;
	dfs(furthest, furthest);
	dist_furthest = -1;
	for (int i = 1; i <= n; i++) {
		max_dist[i] = dist[i];
		if (dist[i] > dist_furthest) {
			furthest = i;
			dist_furthest = dist[i];
		}
	}

	dist[furthest] = 0;
	dfs(furthest, furthest);

	for (int i = 1; i <= n; i++) {
		max_dist[i] = max(max_dist[i], dist[i]);
	}

	for (int i = 1; i <= n; i++) {
		cout << max_dist[i] << ' ';
	}
}