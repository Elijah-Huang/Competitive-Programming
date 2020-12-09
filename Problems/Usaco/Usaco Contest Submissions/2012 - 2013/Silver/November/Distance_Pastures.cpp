#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("distant.in", "r", stdin); freopen("distant.out", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	vector<string> grid(n);
	int largest = n * n;
	vector<vector<int>> dist(largest, vector<int>(largest, 1 << 30));
	vector<vector<pair<int,int>>> adj(n * n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (grid[i][j] != grid[i][j + 1]) {
				adj[n * i + j].push_back({ n * i + j + 1, b });
				adj[n * i + j + 1].push_back({ n * i + j, b });
			}
			else {
				adj[n * i + j].push_back({ n * i + j + 1, a });
				adj[n * i + j + 1].push_back({ n * i + j, a });
			}
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (grid[i][j] != grid[i + 1][j]) {
				adj[n * i + j].push_back({ n * (i + 1) + j, b });
				adj[n * (i + 1) + j].push_back({ n * i + j, b });
			}
			else {
				adj[n * i + j].push_back({ n * (i + 1) + j , a });
				adj[n * (i + 1) + j].push_back({ n * i + j , a });
			}
		}
	}
	for (int start = 0; start < largest; start++) {
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
		pq.push({ 0,start });
		while (!pq.empty()) {
			pair<int,int> curr = pq.top();
			pq.pop();
			if (dist[start][curr.second] > curr.first) {
				dist[start][curr.second] = curr.first;
				for (auto neighbor : adj[curr.second]) {
					if (curr.first + neighbor.second < dist[start][neighbor.first]) {
						pq.push({ curr.first + neighbor.second, neighbor.first });
					}
				}
			}
		}
	}
	int mx_distance = 0;
	for (int i = 0; i < largest; i++) {
		for (int j = 0; j < largest; j++) {
			if (i != j) {
				mx_distance = max(mx_distance, dist[i][j]);
			}
		}
	}
	cout << mx_distance;
}