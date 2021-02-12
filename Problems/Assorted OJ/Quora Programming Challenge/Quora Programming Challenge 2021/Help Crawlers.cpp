#include<bits/stdc++.h>
using namespace std;

vector<int> comps;

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

	int n, m, curr_comp = 0;
	cin >> n >> m;

	vector<vector<int>> adj(n), radj(n);
	vector<int> comp(n);
	stack<int> topsort;
	vector<bool> visited(n), noin, noout;
	vector<int> needs_in, needs_out, needs_both, idx_in, idx_out;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		radj[v].push_back(u);
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
			comps.push_back(curr + 1);
			flooddfs(curr, comp, radj, curr_comp);
		}
	}

	if (curr_comp == 1) {
		cout << 0 << '\n';
		return 0;
	}

	noin.resize(curr_comp, 1);
	noout.resize(curr_comp, 1);
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

	for (int i = 0; i < curr_comp; i++) {
		if (noin[i] and noout[i]) {
			needs_both.push_back(comps[i]);
		}
		else if (noin[i]) {
			needs_in.push_back(comps[i]);
			idx_in.push_back(i);
		}
		else if (noout[i]) {
			needs_out.push_back(comps[i]);
			idx_out.push_back(i);
		}
		
	}

	cout << max(needs_both.size() + needs_in.size(), needs_both.size() +needs_out.size()) << '\n';
	
	if (needs_both.size()) {
		needs_both.push_back(needs_both[0]);
	}

	for (int i = 0; i < int(needs_both.size()) - 1; i++) {
		cout << needs_both[i] << ' ' << needs_both[i+1] << '\n';
	}
	int idx = 0;
	while (idx < needs_in.size() and idx < needs_out.size()) {
		cout << needs_out[idx] << ' ' << needs_in[idx] << '\n';
		idx++;
	}

	if (needs_in.size() > needs_out.size()) {
		while (idx < needs_in.size()) {
			cout << comps[(idx_in[idx] + 1) % curr_comp] << ' ' << needs_in[idx] << '\n';
			idx++;
		}
	}
	else {
		while (idx < needs_out.size()) {
			cout << needs_out[idx] << ' ' << comps[(idx_out[idx] + 1) % curr_comp] << '\n';
			idx++;
		}
	}
	
}