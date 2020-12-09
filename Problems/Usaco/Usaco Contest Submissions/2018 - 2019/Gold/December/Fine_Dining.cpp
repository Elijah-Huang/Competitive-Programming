#include<bits/stdc++.h>
using namespace std;

struct loc {
	int v, d, t;
};

struct edge {
	int v, w;
};

bool operator <(const loc& a,const loc& b) {
	return a.d > b.d;
}

struct cmp {
	bool operator ()(const loc& a, const loc& b) const {
		return a.d > b.d;
	}
};

int dists[(int)5e4][2];
vector<edge> adj[(int)5e4];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("dining.in", "r", stdin); freopen("dining.out", "w", stdout);
	int n, m, k; cin >> n >> m >> k;
	vector<int> special(n);
	for (int i = 0; i < m; i++) {
		int a, b, t; cin >> a >> b >> t;
		a--; b--;
		adj[a].push_back({ b,t });
		adj[b].push_back({ a,t });
	}
	for (int i = 0; i < k; i++) {
		int a, y; cin >> a >> y;
		a--;
		special[a] = max(special[a], y);
	}

	memset(dists, 0x7f, sizeof(dists));
	priority_queue<loc, vector<loc>> pq;
	pq.push({ n - 1,0,special[n-1] > 0 });
	while (!pq.empty()) {
		loc curr = pq.top(); pq.pop();
		if (dists[curr.v][curr.t] > curr.d) {
			dists[curr.v][curr.t] = curr.d;
			for (auto neighbor : adj[curr.v]) {
				if (curr.t) {
					pq.push({ neighbor.v, curr.d + neighbor.w, 1 });
				}
				else {
					if (special[neighbor.v] > 0) {
						pq.push({ neighbor.v, curr.d + neighbor.w - special[neighbor.v],1 });
					}
					pq.push({ neighbor.v, curr.d + neighbor.w, 0 });
				}
			}
		}
	}

	for (int i = 0; i < n-1; i++) {
		cout << (dists[i][0] >= dists[i][1]) << '\n';
	}
}