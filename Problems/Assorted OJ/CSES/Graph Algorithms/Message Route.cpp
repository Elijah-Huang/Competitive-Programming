#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int parent[maxn], visited[maxn];
vector<vector<int>> adj(maxn);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		for (auto neighbor : adj[curr]) {
			if (!visited[neighbor]) {
				parent[neighbor] = curr;
				visited[neighbor] = 1;
				q.push(neighbor);
			}
		}
	}

	if (parent[n] != 0) {
		int curr = n;
		vector<int> path;
		while (curr != 0) {
			path.push_back(curr);
			curr = parent[curr];
		}
		reverse(path.begin(), path.end());
		cout << path.size() << '\n';
		for (auto i : path) {
			cout << i << ' ';
		}
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
}