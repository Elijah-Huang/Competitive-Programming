#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
vector<int> adj[maxn];
int comp[maxn];
vector<long long> comps(1);

int n, m;

void dfs(int c) {
	comp[c] = comps.size()-1;
	comps.back() += 1;
	
	for (auto ne : adj[c]) {
		if (comp[ne] == 0) {
			dfs(ne);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		adj[x1 * n + y1].push_back(x2 * n + y2);
		adj[x2 * n + y2].push_back(x1 * n + y1);
	}

	for (int i = 0; i < n * n; i++) {
		if (comp[i] == 0) {
			comps.resize(comps.size()+1);
			dfs(i);
		}
	}

	long long ans = 0;
	for (auto & sz: comps) {
		ans += sz * sz;
	}

	cout << ans;
}