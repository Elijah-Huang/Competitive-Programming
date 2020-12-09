#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("msched.in", "r", stdin); freopen("msched.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> time(n);
	vector<int> dp(n);
	vector<int> indegree(n);
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		indegree[v]++;
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		dp[curr] += time[curr];
		for (auto neighbor : adj[curr]) {
			dp[neighbor] = max(dp[neighbor], dp[curr]);
			indegree[neighbor]--;
			if (indegree[neighbor] == 0) {
				q.push(neighbor);
			}
		}
	}
	cout << *max_element(dp.begin(), dp.end());
}