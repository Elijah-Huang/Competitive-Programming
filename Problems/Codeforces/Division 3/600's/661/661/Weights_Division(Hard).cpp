#include<bits/stdc++.h>
using namespace std;

struct edge {
	int v, w, c;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		long long n, s; cin >> n >> s;
		vector<vector<edge>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v, w, c; cin >> u >> v >> w >> c;
			u--;
			v--;
			adj[u].push_back({ v,w,c });
			adj[v].push_back({ u,w,c });
		}

		vector<int> leaves_in_subtree(n);
		stack<int> sk; sk.push(0);
		vector<bool> visited(n);
		vector<int> parent(n);
		while (!sk.empty()) {
			int curr = sk.top();
			if (!visited[curr]) {
				visited[curr] = 1;
				for (auto neighbor : adj[curr]) {
					if (neighbor.v != parent[curr]) {
						parent[neighbor.v] = curr;
						sk.push(neighbor.v);
					}
				}
			}
			else {
				if (adj[curr].size() == 1) {
					leaves_in_subtree[curr] = 1;
				}
				else {
					for (auto neighbor : adj[curr]) {
						leaves_in_subtree[curr] += leaves_in_subtree[neighbor.v];
					}
				}
				sk.pop();
			}
		}

		vector<long long> weight_delta1;
		vector<long long> weight_delta2;
		long long total_weight = 0;
		for (int u = 1; u < n; u++) {
			for (auto neighbor : adj[u]) {
				if (neighbor.v == parent[u]) {
					if (neighbor.c == 1) {
						long long weight = neighbor.w;
						total_weight += weight * leaves_in_subtree[u];
						while (weight) {
							weight_delta1.push_back((weight - weight / 2) * leaves_in_subtree[u]);
							weight /= 2;
						}
					}
					else {
						long long weight = neighbor.w;
						total_weight += weight * leaves_in_subtree[u];
						while (weight) {
							weight_delta2.push_back((weight - weight / 2) * leaves_in_subtree[u]);
							weight /= 2;
						}
					}
				}
			}
		}

		sort(weight_delta1.begin(), weight_delta1.end(), greater<long long>());
		sort(weight_delta2.begin(), weight_delta2.end(), greater<long long>());

		vector<long long> psum1(weight_delta1.size() + 1);
		vector<long long> psum2(weight_delta2.size() + 1);
		for (int i = 0; i < weight_delta1.size(); i++) {
			psum1[i + 1] = psum1[i] + weight_delta1[i];
		}
		for (int i = 0; i < weight_delta2.size(); i++) {
			psum2[i + 1] = psum2[i] + weight_delta2[i];
		}

		int min_cost = 1e9;
		for (int i = 0; i < psum2.size(); i++) {
			int cost = 2 * i;
			long long needed = total_weight - psum2[i] - s;
			if (needed <= 0) {
				min_cost = min(min_cost, cost);
				break;
			}
			else {
				int L = 0;
				int R = psum1.size() - 1;
				while (L != R) {
					int m = (L + R) / 2;
					if (psum1[m] >= needed) {
						R = m;
					}
					else {
						L = m + 1;
					}
				}
				if (needed <= psum1[L]) {
					cost += L;
					min_cost = min(min_cost, cost);
				}
			}
		}

		cout << min_cost << '\n';

	}
}