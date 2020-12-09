#include<bits/stdc++.h>
using namespace std;

struct edge {
	int v, w, u;
};

vector<vector<edge>> adj(10001);
vector<vector<int>> adj2(10001);
int dists[10001], amt[10001];

bool operator <(const edge& a, const edge& b) {
	if (a.w == b.w) {
		return a.u > b.u;
	}
	return a.w > b.w;
}

void dfs(int curr) {
	for (auto neighbor : adj2[curr]) {
		dfs(neighbor);
		amt[curr] += amt[neighbor];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("shortcut.in", "r", stdin); freopen("shortcut.out", "w", stdout);
	int n, m, t; cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		cin >> amt[i];
	}
	for (int i = 0; i < m; i++) {
		int u, v, t2; cin >> u >> v >> t2;
		adj[u].push_back({ v,t2,u });
		adj[v].push_back({ u,t2,v });
	}

	memset(dists, 0x3f, sizeof(dists));
	priority_queue<edge, vector<edge>> pq;
	pq.push({ 1,0,0 });
	while (!pq.empty()) {
		auto curr = pq.top(); pq.pop();
		if (dists[curr.v] > curr.w) {
			adj2[curr.u].push_back(curr.v);
			dists[curr.v] = curr.w;
			for (auto neighbor : adj[curr.v]) {
				pq.push({ neighbor.v,curr.w + neighbor.w,curr.v });
			}
		}
	}

	dfs(1);

	long long ans = 0;
	for (int end = 1; end <= n; end++) {
		ans = max(ans, amt[end] * ((long long) dists[end] - t));
	}

	cout << ans << '\n';
}