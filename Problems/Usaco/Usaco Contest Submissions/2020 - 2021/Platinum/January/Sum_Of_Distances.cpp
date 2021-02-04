#include<bits/stdc++.h>
using namespace std;

const int maxk = 5e4;
int k, n, m;
vector<vector<int>> adj[maxk];
vector<int> dist[maxk], num_dist[maxk];
vector<int> res;

void bfs(int i) {
	dist[i][0] = 1;
	num_dist[i][dist[i][0]] += 1;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int c = q.front(); q.pop();
		for (auto n : adj[i][c]) {
			if (dist[i][n] == -1) {
				dist[i][n] = dist[i][c] + 1;
				num_dist[i][dist[i][n]] += 1;
				q.push(n);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n >> m;
		dist[i].resize(n,-1);
		for (int j = 0; j < m; j++) {
			int a, b; cin >> a >> b; a--; b--;
			adj[i][a].push_back(b);
			adj[i][b].push_back(a);
		}
	}

	for (int i = 0; i < k; i++) {
		bfs(i);
	}

	for (int i = 0; i < n; i++) {
		
	}
}