#include<bits/stdc++.h>
using namespace std;

struct cow {
	int x, y;
};

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
	freopen("moocast.in", "r", stdin); freopen("moocast.out", "w", stdout);
	int n, mx = 0;
	cin >> n;
	vector<cow> cows;
	vector<edge> edges;
	vector<vector<edge>> adj(n);
	vector<bool> in_mst(n);
	priority_queue<edge, vector<edge>, cmp> pq;
	int added_points = 0;
	int mx_edge = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cows.push_back({ x,y });
	}
	for (int i = 0; i < n; i++) {
		cow curr = cows[i];
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			cow cow2 = cows[j];
			int dist = ((curr.x - cow2.x) * (curr.x - cow2.x) +
				(curr.y - cow2.y) * (curr.y - cow2.y));
			adj[i].push_back({ dist,i,j });
		}
	}
	edge curr;
	pq.push({ 0,0,0 });
	while (added_points != n) {
		curr = pq.top();
		pq.pop();
		if (!in_mst[curr.v]) {
			in_mst[curr.v] = 1;
			added_points++;
			mx_edge = max(mx_edge, curr.w);
			for (auto neighbor: adj[curr.v]){
				if (!in_mst[neighbor.v]) {
					pq.push(neighbor);
				}
			}
		}
	}
	cout << mx_edge;
}