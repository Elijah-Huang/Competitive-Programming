#include<bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, w;
};

struct query {
	int k, v, i;
};
int parent[100000];
int sizes[100000];
void make_set(int& v);
int find_set(int v);
void union_sets(int a, int b);


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("mootube.in", "r", stdin); freopen("mootube.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<edge> edges(n - 1);
	vector<query> queries(q);
	vector<int> answers(q);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges[i] = { u, v, w };
	}
	for (int i = 0; i < q; i++) {
		int v, k;
		cin >> k >> v;
		v--;
		queries[i] = { k,v,i};
	}
	sort(edges.begin(), edges.end(),
		[&](const edge& a, const edge& b) {return a.w > b.w; });
	sort(queries.begin(), queries.end(),
		[&](const query& a, const query& b) {return a.k > b.k; });

	for (int i = 0; i < n; i++) {
		make_set(i);
	}
	int idx_edges = 0;
	for (int i = 0; i < q; i++) {
		while (idx_edges < n - 1 and edges[idx_edges].w >= queries[i].k) {
			union_sets(edges[idx_edges].u, edges[idx_edges].v);
			idx_edges++;
		}
		answers[queries[i].i] = sizes[find_set(queries[i].v)] - 1;
	}
	for (auto answer : answers) {
		cout << answer << '\n';
	}
}

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

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (sizes[a] < sizes[b]) {
			swap(a, b);
		}
		parent[b] = a;
		sizes[a] += sizes[b];
	}
}