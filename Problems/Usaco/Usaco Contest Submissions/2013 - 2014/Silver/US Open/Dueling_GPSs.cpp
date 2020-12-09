#include<bits/stdc++.h>
using namespace std;

struct edge {
	int a, b, w, other;
};

struct edge2 {
	int a, b, p, q;
};
struct edge_cmp {
	bool operator()(const edge& a, const edge& b) const {
		return a.w > b.w;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("gpsduel.in", "r", stdin); freopen("gpsduel.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<edge2> edges;
	vector<vector<edge2>> radj1(n);
	vector<vector<edge2>> radj2(n);
	for (int i = 0; i < m; i++) {
		int a, b, p, q; cin >> a >> b >> p >> q;
		a--; b--;
		edges.push_back({ a,b,p,q });
		radj1[b].push_back({ b,a,p,q });
		radj2[b].push_back({ b,a,p,q });
	}
	
	priority_queue<edge, vector<edge>, edge_cmp> pq1;
	pq1.push({ n-1,n-1,0 });
	priority_queue<edge, vector<edge>, edge_cmp> pq2;
	pq2.push({ n-1,n-1,0 });
	vector<int> dists1(n, 1 << 30);
	vector<int> dists2(n, 1 << 30);
	vector<set<pair<int,int>>> next1(n);
	vector<set<pair<int,int>>> next2(n);

	while (!pq1.empty()) {
		edge curr = pq1.top(); pq1.pop();
		if (curr.w == dists1[curr.a]) {
			next1[curr.a].insert({ curr.b,curr.other });
		}
		if (curr.w < dists1[curr.a]) {
			dists1[curr.a] = curr.w;
			next1[curr.a].insert({ curr.b,curr.other });
			for (auto& neighbor : radj1[curr.a]) {
				pq1.push({ neighbor.b, curr.a, neighbor.p + curr.w,neighbor.q });
			}
		}
	}
	while (!pq2.empty()) {
		edge curr = pq2.top(); pq2.pop();
		if (curr.w == dists2[curr.a]) {
			next2[curr.a].insert({ curr.b,curr.other });
		}
		if (curr.w < dists2[curr.a]) {
			dists2[curr.a] = curr.w;
			next2[curr.a].insert({ curr.b,curr.other });
			for (auto& neighbor : radj2[curr.a]) {
				pq2.push({ neighbor.b, curr.a, neighbor.q + curr.w, neighbor.p });
			}
		}
	}

	vector<vector<edge>> complaints(n);
	for (auto& e : edges) {
		int complaint = (!next1[e.a].count({ e.b,e.q }) + !next2[e.a].count({ e.b,e.p }));
		complaints[e.a].push_back({ e.a,e.b,complaint });
	}

	priority_queue<edge, vector<edge>, edge_cmp> pq3;
	pq3.push({ 0,0,0 });
	vector<int> dists3(n, 1 << 30);
	while (!pq3.empty()) {
		edge curr = pq3.top(); pq3.pop();
		if (curr.w < dists3[curr.a]) {
			dists3[curr.a] = curr.w;
			for (auto& neighbor : complaints[curr.a]) {
				pq3.push({ neighbor.b, 0, neighbor.w + curr.w });
			}
		}
	}

	cout << dists3[n - 1] << '\n';
}