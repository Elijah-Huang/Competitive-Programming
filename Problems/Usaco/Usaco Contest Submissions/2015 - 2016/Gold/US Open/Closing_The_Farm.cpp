#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

vector<int> parent;
vector<int> sizes;
int components = 0;

void make_set(int& v) {
	parent[v] = v;
	sizes[v] = 1;
	components++;
}

int cind_set(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = cind_set(parent[v]);
}

void union_sets(int a, int b) {
	a = cind_set(a);
	b = cind_set(b);
	if (a != b) {
		if (sizes[a] < sizes[b]) {
			swap(a, b);
		}
		parent[b] = a;
		sizes[a] += sizes[b];
		components--;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("closing.in","r",stdin), freopen("closing.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> add(n);
	vector<bool> output(n);
	parent.resize(n+1);
	sizes.resize(n+1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		cin >> add[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		make_set(add[i]);
		for (int neighbor : adj[add[i]]) {
			if (parent[neighbor]) {
				union_sets(neighbor, add[i]);
			}
		}
		output[i] = (components == 1 ? 1 : 0);
	}
	for (int i = 0; i < n; i++) {
		cout << (output[i] ? "YES\n" : "NO\n");
	}
}