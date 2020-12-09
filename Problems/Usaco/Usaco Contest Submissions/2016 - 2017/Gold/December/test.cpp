#include<bits/stdc++.h>
using namespace std;

struct cow {
	int x, y;
};

int parent[1000];
int sizes[1000];
void make_set(int& v) {
	parent[v] = v;
	sizes[v] = 1;
}

int find_set(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b, int& added_edges, int& n) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (sizes[a] < sizes[b]) {
			swap(a, b);
		}
		parent[b] = a;
		sizes[a] += sizes[b];
		added_edges++;
		if (added_edges == n - 1) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

struct edge {
	int w, u, v;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("moocast.in", "r", stdin); freopen("moocast.out", "w", stdout);
	int n, mx = 0;
	cin >> n;
	vector<cow> cows;
	vector<edge> edges;
	vector<bool> in_mst(n);
	int added_edges = 0;
	int mx_edge;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cows.push_back({ x,y });
	}
	for (int i = 0; i < n; i++) {
		cow cow1 = cows[i];
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			cow cow2 = cows[j];
			int dist = ((cow1.x - cow2.x) * (cow1.x - cow2.x) +
				(cow1.y - cow2.y) * (cow1.y - cow2.y));
			edges.push_back({ dist, i, j });
		}
	}
	sort(edges.begin(), edges.begin() + n, [&](edge& a, edge& b) {return a.w < b.w; });
	for (int i = 0; i < n; i++) {
		make_set(i);
	}
	for (int i = 0; i < edges.size(); i++) {
		if (union_sets(edges[i].u, edges[i].v, added_edges, n)) {
			mx_edge = edges[i].v;
			break;
		}
	}
	cout << mx_edge;
}