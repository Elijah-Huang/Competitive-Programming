/*
ID: elijahj1
TASK: schlnet
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
void topdfs(int curr, vector<bool>& visited, vector<vector<int>>& adj, stack<int>& topsort) {
	visited[curr] = 1;
	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor]) {
			topdfs(neighbor, visited, adj, topsort);
		}
	}
	topsort.push(curr);
}
void flooddfs(int curr, vector<int>& comp, vector<vector<int>>& radj, int& curr_comp) {
	comp[curr] = curr_comp;
	for (auto neighbor : radj[curr]) {
		if (comp[neighbor] == 0) {
			flooddfs(neighbor, comp, radj, curr_comp);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("schlnet.in","r",stdin); freopen("schlnet.out","w",stdout);
	int n, curr_comp = 0, noins = 0, noouts = 0;
	cin >> n;
	vector<vector<int>> adj(n), radj(n);
	vector<int> comp(n);
	stack<int> topsort;
	vector<bool> visited(n), noin, noout;
	for (int u = 0; u < n; u++) {
		int v;
		while (true) {
			cin >> v; v--;
			if (v == -1) {
				break;
			}
			else {
				adj[u].push_back(v);
				radj[v].push_back(u);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			topdfs(i, visited, adj, topsort);
		}
	}
	while (!topsort.empty()) {
		int curr = topsort.top();
		topsort.pop();
		if (comp[curr] == 0) {
			curr_comp++;
			flooddfs(curr, comp, radj, curr_comp);
		}
	}
	if (curr_comp == 1) {
		cout << 1 << '\n';
		cout << 0 << '\n';
		return 0;
	}
	noin.resize(curr_comp,1);
	noout.resize(curr_comp,1);
	for (int i = 0; i < n; i++) {
		for (auto neighbor : adj[i]) {
			if (comp[neighbor] != comp[i]) {
				noout[comp[i] - 1] = 0;
			}
		}
		for (auto neighbor : radj[i]) {
			if (comp[neighbor] != comp[i]) {
				noin[comp[i] - 1] = 0;
			}
		}
	}
	noins = accumulate(noin.begin(), noin.end(), noins);
	noouts = accumulate(noout.begin(), noout.end(), noouts);
	cout << noins << '\n';
	cout << max(noins, noouts) << '\n';
}