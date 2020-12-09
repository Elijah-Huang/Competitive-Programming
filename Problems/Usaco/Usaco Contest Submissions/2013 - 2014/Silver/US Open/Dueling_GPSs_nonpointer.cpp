#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct edge {
	int a, b, w;
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
	map<pair<int, int>, pair<int, int>> edges;
	vector<vector<edge>> radj1(n);
	vector<vector<edge>> radj2(n);
	for (int i = 0; i < m; i++) {
		int a, b, p, q; cin >> a >> b >> p >> q;
		a--; b--;
		if (!edges.count({ a,b })) {
			edges.insert({ { a,b }, { p,q } });
		}
		else {
			edges[{a, b}].first = min(edges[{a, b}].first, p);
			edges[{a, b}].second = min(edges[{a, b}].second, q);
		}
	}

	for (auto& e : edges) {
		radj1[e.first.second].push_back({ e.first.second,e.first.first,e.second.first });
		radj2[e.first.second].push_back({ e.first.second,e.first.first,e.second.second });
	}

	priority_queue<edge, vector<edge>, edge_cmp> pq1;
	pq1.push({ n - 1,n - 1,0 });
	priority_queue<edge, vector<edge>, edge_cmp> pq2;
	pq2.push({ n - 1,n - 1,0 });
	vector<int> dists1(n, 1 << 30);
	vector<int> dists2(n, 1 << 30);

	while (!pq1.empty()) {
		edge curr = pq1.top(); pq1.pop();
		if (curr.w < dists1[curr.a]) {
			dists1[curr.a] = curr.w;
			for (auto& neighbor : radj1[curr.a]) {
				pq1.push({ neighbor.b, curr.a, neighbor.w + curr.w });
			}
		}
	}
	while (!pq2.empty()) {
		edge curr = pq2.top(); pq2.pop();
		if (curr.w < dists2[curr.a]) {
			dists2[curr.a] = curr.w;
			for (auto& neighbor : radj2[curr.a]) {
				pq2.push({ neighbor.b, curr.a, neighbor.w + curr.w });
			}
		}
	}

	vector<vector<edge>> complaints(n);
	for (auto& e : edges) {
		int complaint = !(dists1[e.first.first] - dists1[e.first.second] == e.second.first) +
			!(dists2[e.first.first] - dists2[e.first.second] == e.second.second);
		complaints[e.first.first].push_back({ e.first.first,e.first.second,complaint });
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
	int a;
	/*freopen("8.out", "r", stdin);
	cin >> a;
	cout << a;*/
}