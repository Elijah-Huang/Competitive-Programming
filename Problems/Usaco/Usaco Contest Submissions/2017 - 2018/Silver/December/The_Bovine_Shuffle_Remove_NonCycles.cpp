#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("shuffle.in", "r", stdin); freopen("shuffle.out", "w", stdout);
	int n; cin >> n;
	int total = n;
	int parent[100000]{};
	int adj[100000]{};
	for (int i = 0; i < n; i++) {
		int loc;
		cin >> loc;
		--loc;
		adj[i] = loc;
		parent[loc]++;
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!parent[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		total--;
		if (!--parent[adj[curr]]) {
			q.push(adj[curr]);
		}
	}
	cout << total;
}