#include<bits/stdc++.h>
using namespace std;
struct cow {
	int x, y;
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
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cows.push_back({ x,y });
	}
	/* If there are not alot of cows, the max distance will be greater, but when there
	are alot of cows the max distance is less so reduce it to reduce the search space */
	int L = 0, R = (cows.size() > 500 ? 2*(1250*1250) : 2*(25000 * 25000));
	while (L != R) {
		vector<vector<int>> adj(n);
		int m = (L + R) / 2;
		bool all_visited = true;
		for (int i = 0; i < n; i++) {
			cow cow1 = cows[i];
			for (int j = 0; j < n; j++) {
				cow cow2 = cows[j];
				int dist = ((cow1.x - cow2.x) * (cow1.x - cow2.x) +
					(cow1.y - cow2.y) * (cow1.y - cow2.y));
				if (m >= dist) {
					adj[i].push_back(j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			vector<bool> visited(n); 
			dfs(i, visited, adj);
			for (auto c : visited) {
				if (!c) {
					all_visited = false;
					goto a;
				}
			}
		}
	a:
		if (all_visited) {
			R = m;
		}
		else {
			L = m + 1;
		}

	}
	cout << L;
}