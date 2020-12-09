#include<bits/stdc++.h>
using namespace std;

struct edge {
	int i, j, d;
};

const int maxn = 250000;
long long tot_rating = 0;
int m, n, t;
vector<edge> edges;
set<int> unrated[maxn];
int parent[maxn], sizes[maxn];
int elevations[500][500], rating[500][500];

int find_parent(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = find_parent(parent[v]);
}

void union_sets(int a, int b, int d) {
	a = find_parent(a);
	b = find_parent(b);
	if (a != b) {
		if (sizes[a] < sizes[b]) {
			swap(a, b);
		}
		
		parent[b] = a;
		sizes[a] += sizes[b];

		for (auto i : unrated[b]) {
			unrated[a].insert(i);
		}

		if (sizes[a] >= t) {
			for (auto i : unrated[a]) {
				rating[i/n][i%n] = d;
			}
			unrated[a].clear();
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("skilevel.in", "r", stdin); freopen("skilevel.out", "w", stdout);

	cin >> m >> n >> t;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> elevations[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n-1; j++) {
			edges.push_back({ i*n+j, i*n+j+1, abs(elevations[i][j] - elevations[i][j + 1]) });
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m-1; i++) {
			edges.push_back({ i*n+j, (i+1)*n+j, abs(elevations[i][j] - elevations[i+1][j]) });
		}
	}

	sort(edges.begin(), edges.end(), [&](const edge& a, const edge& b) {return a.d < b.d; });
	
	iota(parent, parent + maxn, 0);
	fill(sizes, sizes + maxn, 1);
	for (int i = 0; i < m * n; i++) {
		unrated[i].insert(i);
	}
	for (auto& e : edges) {
		union_sets(e.i, e.j, e.d);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int start; cin >> start;
			if (start) {
				tot_rating += rating[i][j];
			}
		}
	}

	cout << tot_rating;
}