#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 1;
int n; 
vector<int> adj[maxn];
int sub_leaves[maxn];
int leaves = 0, center;
priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
vector<vector<int>> curr_leaves;

int find_center(int c, int p) {
	int mx_sub = 0;

	for (auto n : adj[c]) {
		if (n != p) {
			if (center = find_center(n, c)) {
				return center;
			}

			sub_leaves[c] += sub_leaves[n];
			mx_sub = max(mx_sub, sub_leaves[n]);
		}
	}

	if (mx_sub <= leaves / 2 and leaves - sub_leaves[c] <= leaves / 2 and adj[c].size() > 1) {
		return c;
	}
	else {
		return 0;
	}
}

void dfs_leaves(int c, int p) {
	if (adj[c].size() == 1) {
		curr_leaves.back().push_back(c);
	}

	for (auto n : adj[c]) {
		if (n != p) {
			dfs_leaves(n, c);
		}
	}
}

void repush(pair<int, int>& curr) {
	curr_leaves[curr.second].pop_back();
	if (curr.first > 1) {
		pq.push({ curr.first - 1, curr.second });
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			leaves += 1;
			sub_leaves[i] = 1;
		}
	}

	center = find_center(1, 0);

	for (auto n : adj[center]) {
		curr_leaves.resize(curr_leaves.size() + 1);
		dfs_leaves(n, center);
		pq.push({ curr_leaves.back().size(), curr_leaves.size() - 1 });
	}

	cout << (leaves + 1) / 2 << '\n';
	// pair up leaves with other leaves or the center for the last leaf if n is odd
	// it is guaranteed that the path on the tree with these endpoints goes through the center
	// at the end of the pairing all nodes are covered by some added edge (in a cycle) 
	while (!pq.empty()) {
		if (pq.size() == 1) {
			auto curr = pq.top(); pq.pop();
			assert(curr.first == 1);

			cout << curr_leaves[curr.second].back() << ' ' << center << '\n';
		}
		else {
			auto curr = pq.top(); pq.pop();
			auto curr2 = pq.top(); pq.pop();

			cout << curr_leaves[curr.second].back() << ' ' << curr_leaves[curr2.second].back() << '\n';

			repush(curr);
			repush(curr2);
		}
	}
}