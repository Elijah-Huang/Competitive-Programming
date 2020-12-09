#include<bits/stdc++.h>
using namespace std;

long long min_tot = 1e30, curr_tot;
int n, tot_leaves = 0;
vector<string> names(1e5);
vector<vector<int>> adj(1e5);
vector<int> dists(1e5), leaf_size(1e5);

void dfs1(int curr) {
	for (auto child: adj[curr]) {
		dists[child] = dists[curr] + (curr != 0) + names[child].length();
		dfs1(child);
		leaf_size[curr] += leaf_size[child];
	}
	if (adj[curr].size() == 0) {
		leaf_size[curr] = 1;
	}
}

void dfs2(int curr) {
	for (auto child : adj[curr]) {
		if (adj[child].size() > 0) {
			curr_tot += (3) * (tot_leaves - leaf_size[child]);
			curr_tot -= (1 + names[child].length()) * leaf_size[child];
			min_tot = min(min_tot, curr_tot);
			dfs2(child);
			curr_tot -= (3) * (tot_leaves - leaf_size[child]);
			curr_tot += (1 + names[child].length()) * leaf_size[child];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("dirtraverse.in", "r", stdin); freopen("dirtraverse.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int neighbors;
		cin >> names[i] >> neighbors;
		while (neighbors--) {
			int v; cin >> v; v--;
			adj[i].push_back(v);
		}
	}

	dfs1(0);
	for (int i = 0; i < n; i++) {
		if (adj[i].size() == 0) {
			curr_tot += dists[i];
			tot_leaves++;
		}
	}
	min_tot = min(min_tot, curr_tot);
	dfs2(0);
	
	cout << min_tot;
}