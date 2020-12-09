#include<bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
};

struct edge {
	int w, a;
};

struct edge_cmp {
	bool operator()(const edge& a, const edge& b) {
		return a.w > b.w;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("irrigation.in", "r", stdin); freopen("irrigation.out", "w", stdout);
	int n, c; cin >> n >> c;
	vector<point> points(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	}

	vector<bool> in_mst(n);
	priority_queue<edge, vector<edge>, edge_cmp> pq;
	pq.push({ 0,0 });
	unsigned int total_cost = 0;
	int added = 0;
	while (!pq.empty() and added != n) {
		auto to_add = pq.top(); pq.pop();
		if (not in_mst[to_add.a]) {
			total_cost += to_add.w;
			in_mst[to_add.a] = true;
			added += 1;
			for (int i = 0; i < n; i++) {
				point p = points[i];
				int weight = (points[to_add.a].x - p.x) * (points[to_add.a].x - p.x)
					+ (points[to_add.a].y - p.y) * (points[to_add.a].y - p.y);
				if (weight >= c) {
					pq.push({ weight , i });
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (not in_mst[i]) {
			cout << -1;
			return 0;
		}
	}

	cout << total_cost;
}