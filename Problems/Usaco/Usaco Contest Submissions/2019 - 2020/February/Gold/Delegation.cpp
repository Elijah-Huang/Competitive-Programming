#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int n;
vector<unordered_set<int>> adj(1e5);
int subtree[int(1e5)];
vector<int> paths[int(1e5)];

void dfs(int curr, int parent) {
	for (auto neighbor : adj[curr]) {
		if (neighbor == parent) continue;
		dfs(neighbor, curr);
		subtree[curr] += subtree[neighbor];
		paths[curr].push_back(subtree[neighbor]);
	}
	subtree[curr] += 1;
	if (curr != 0) {
		paths[curr].push_back(n - subtree[curr]);
	}
}

bool test(int k) {
	vector<int> counts(k);
	for (int i = 0; i < n; i++) {
		int unpaired = 0;
		for (auto path : paths[i]) {
			if (path % k == 0) continue;
			if (!counts[k - path % k]) {
				counts[path % k]++;
				unpaired++;
			}
			else {
				counts[k - path % k]--;
				unpaired--;
			}
		}
		if (unpaired) {
			return 0;
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("deleg.in", "r", stdin); freopen("deleg.out", "w", stdout);
	cin >> n;
	string partitionable(n - 1, '0');
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	
	dfs(0, -1);

	for (int k = 1; k < n; k++) {
		if ((n - 1) % k == 0 and test(k)) {
			partitionable[k - 1] = '1';
		}
	}

	cout << partitionable;
}