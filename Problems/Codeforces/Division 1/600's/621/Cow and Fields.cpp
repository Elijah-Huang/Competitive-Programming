#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> adj(n+1);
	vector<int> special;
	for (int i = 0; i < k; i++) {
		int curr;
		cin >> curr;
		special.push_back(curr);
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u;
		cin >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> dist1(n + 1);
	vector<int> distn(n + 1);
	queue<int> q({ 1 });
	while (!q.empty()){
		int curr = q.front();
		q.pop();
		for (auto neighbor : adj[curr]) {
			if (!dist1[neighbor] and neighbor != 1) {
				dist1[neighbor] = dist1[curr] + 1;
				q.push(neighbor);
			}
		}
	}
	queue<int> q2({ n });
	while (!q2.empty()) {
		int curr = q2.front();
		q2.pop();
		for (auto neighbor : adj[curr]) {
			if (!distn[neighbor] and neighbor != n) {
				distn[neighbor] = distn[curr] + 1;
				q2.push(neighbor);
			}
		}
	}
	int smallest = dist1[n];
	vector<pair<int, int>> diffs;
	for (auto i : special) {
		diffs.push_back({ dist1[i] - distn[i],i });
	}
	sort(diffs.begin(), diffs.end());
	int mx = 0, mx_yb = 0;
	for (int i = diffs.size() - 2; i >= 0; i--) {
		mx_yb = max(mx_yb, distn[diffs[i+1].second]);
		mx = max(mx, mx_yb + dist1[diffs[i].second]);
	}
	cout << min(smallest, 1 + mx);
}