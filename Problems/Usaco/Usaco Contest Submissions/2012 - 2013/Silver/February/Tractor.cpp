#include<bits/stdc++.h>
using namespace std;

vector<int> dx = { 1, 0, -1 ,0 };
vector<int> dy = { 0 , 1,  0, -1 };

struct edge {
	int u, v, w;
};
vector<edge> weights[int(1e6 + 1)];

int sizes[250000];
int parent[250000];

void make_set(int& v) {
	sizes[v] = 1;
	parent[v] = v;
}

int find_set(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b, int& half) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (sizes[a] < sizes[b]) {
			swap(a, b);
		}
		parent[b] = a;
		sizes[a] += sizes[b];
		return sizes[a] >= half;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("tractor.in", "r", stdin); freopen("tractor.out", "w", stdout);
	int n;
	cin >> n;
	int half = ceil(n*n / 2.0);
	vector<vector<int>> field(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if (0 <= i + dx[k] and i + dx[k] < n
					and 0 <= j + dy[k] and j + dy[k] < n) {
					int w = abs(field[i + dx[k]][j + dy[k]] - field[i][j]);
					weights[w].push_back({ i*n + j,(i + dx[k])*n + j + dy[k],w });
				}
			}
		}
	}
	for (int i = 0; i < n * n; i++) {
		make_set(i);
	}
	for (int w = 0; w <= 1000000; w++) {
		for (auto e : weights[w]) {
			if (union_sets(e.u, e.v, half)) {
				cout << w;
				return 0;
			}
		}
	}
}