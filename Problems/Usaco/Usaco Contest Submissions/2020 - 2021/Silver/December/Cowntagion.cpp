#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int n, moves = 0;
vector<int> adj[maxn];

void dfs(int c, int p) {
	int dbl = 0;
	while (1 << dbl < adj[c].size()) {
		dbl++;
	}

	moves += dbl + adj[c].size() - 1;

	for (auto n : adj[c]) {
		if (n != p) {
			dfs(n, c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);

	cin >> n;
	adj[1].push_back(0);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1,0);

	cout << moves;
}
