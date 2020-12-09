#include<bits/stdc++.h>
using namespace std;

struct edge {
	int w, u, v;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<edge>> adj(n);
	vector<int> dists(n, 1e9);
	vector<bool> in_mst(n);
	int added_points = 0;
	int mx_edge = 0;
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		adj[u].push_back({ w,u,v });
		adj[v].push_back({ w,v,u });
	}

	dists[0] = 0;
	for (int i = 0; i < n; i++) {
		int closest = 0;
		int dist = 1e9;
		for (int j = 0; j < n; j++) {
			if (!in_mst[j] and dists[j] < dist){
				closest = j;
				dist = dists[j];
			}
		}
		in_mst[closest] = 1;
		for (auto& neighbor: adj[closest]){
			dists[neighbor.v] = min(dists[neighbor.v], neighbor.w);
		}
	}
}