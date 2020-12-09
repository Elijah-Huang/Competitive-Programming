#include<bits/stdc++.h>
using namespace std;
struct cow {
	int x, y, p2;
};
void dfs(int curr, vector<bool>& visited, vector<vector<int>>& adj) {
	visited[curr] = 1;
	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor]) {
			dfs(neighbor, visited, adj);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("moocast.in", "r", stdin); freopen("moocast.out", "w", stdout);
	int n, mx = 0;
	cin >> n;
	vector<cow> cows;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		int x, y, p;
		cin >> x >> y >> p;
		cows.push_back({ x,y,p * p });
	}
	for (int i = 0; i < n; i++) {
		cow cow1 = cows[i];
		for (int j = 0; j < n; j++) {
			cow cow2 = cows[j];
			int dist = ((cow1.x - cow2.x) * (cow1.x - cow2.x) +
				(cow1.y - cow2.y) * (cow1.y - cow2.y));
			if (cow1.p2 >= dist) {
				adj[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		vector<bool> visited(n);
		int total = 0;
		dfs(i, visited, adj);
		for (auto c : visited) {
			total += c;
		}
		mx = max(mx, total);
	}
	cout << mx;
}