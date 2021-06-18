#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
int n, j, k;
vector<int> adj[maxn];
int sz[maxn]; // subtree size

long double ans = 0, tot_prob = 0;

void dfs_sz(int c, int p) {
	for (auto ne : adj[c]) {
		if (ne != p) {
			dfs_sz(ne, c);
			sz[c] += sz[ne];
		}
	}

	sz[c]++;
}

void dfs(int c, int p, long double prob = 1, int depth = 0) {
	//cout << c << ' ' << adj[c].size() << ' ' << prob << '\n';
	tot_prob += prob;
	ans += prob * depth;

	for (auto ne : adj[c]) {
		dfs(ne, c, prob / adj[c].size(), depth + 1);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> j >> k;

	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;

		adj[a].push_back(b);
		//adj[b].push_back(a);
	}

	//dfs_sz(1, 1);

	dfs(1, 1);

	cout << fixed << setprecision(15) << ans/tot_prob;
}