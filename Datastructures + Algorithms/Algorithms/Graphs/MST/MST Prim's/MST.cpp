#include<bits/stdc++.h>
using namespace std;

struct edge {
	int w, u, v;
};

struct cmp {
	const bool operator()(const edge& a, const edge& b) const {
		return a.w > b.w;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<edge>> adj(n);
	vector<bool> in_mst(n);
	priority_queue<edge, vector<edge>, cmp> pq;
	int added_points = 0;
	int mx_edge = 0;
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		adj[u].push_back({ w,u,v });
		adj[v].push_back({ w,v,u });
	}

	pq.push({ 0,0,0 });
	while (added_points != n) {
		edge curr = pq.top();
		pq.pop();
		if (!in_mst[curr.v]) {
			in_mst[curr.v] = 1;
			added_points++;
			for (auto neighbor : adj[curr.v]) {
				if (!in_mst[neighbor.v]) {
					pq.push(neighbor);
				}
			}
		}
	}
}