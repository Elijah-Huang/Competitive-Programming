#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 1;
int n, m;
vector<int> adj[maxn];
int comp[maxn];
vector<int> comps(1);

void dfs(int c) {
	comp[c] = comps.size() - 1;
	comps.back()++;
	for (auto n : adj[c]) {
		if (comp[n] == 0) {
			dfs(n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int k; cin >> k;

		vector<int> group;
		for (int i = 0; i < k; i++) {
			int a; cin >> a;
			group.push_back(a);
		}

		for (int i = 0; i < k - 1; i++) {
			adj[group[i]].push_back(group[i + 1]);
			adj[group[i + 1]].push_back(group[i]);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (comp[i] == 0) {
			comps.resize(comps.size() + 1);
			dfs(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << comps[comp[i]] << ' ';
	}
}