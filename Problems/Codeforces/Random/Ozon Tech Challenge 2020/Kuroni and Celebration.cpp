#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); 
	}
	vector<int> leaves;
	for (int query = 1; query <= n / 2; query++) {
		for (int i = 1; i <= n; i++) {
			if (leaves.size() == 2) {
				break;
			}
			if (adj[i].size() == 1) {
				leaves.push_back(i);
			}
		}
		cout << "? " << leaves[0] << ' ' << leaves[1] << endl;
		int lca;
		cin >> lca;
		if ((lca == leaves[0] or lca == leaves[1]) or query == n / 2) {
			cout << "! " << lca << endl;
			return 0;
		}
		else {
			int first = adj[leaves[0]][0];
			swap(*find(adj[first].begin(), adj[first].end(), leaves[0]),adj[first].back());
			adj[first].pop_back();
			int second = adj[leaves[1]][0];
			swap(*find(adj[second].begin(), adj[second].end(), leaves[1]),adj[second].back());
			adj[second].pop_back();
			adj[leaves[0]].clear();
			adj[leaves[1]].clear();
			leaves.clear();
		}
	}
}