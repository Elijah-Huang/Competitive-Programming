#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int curr_color = 0;
int sizes[maxn], parent[maxn], color[maxn];
bool in_set[maxn], visited[maxn];
vector<int> adj[maxn], same_color, same_color_next;

int find_parent(int v) {
	if (v == parent[v]) {
		return v;
	}

	return parent[v] = find_parent(parent[v]);
}

void union_sets(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);

	if (a != b) {
		if (sizes[a] < sizes[b]) {
			swap(a, b);
		}

		parent[b] = a;
		sizes[a] += sizes[b];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fcolor.in", "r", stdin); freopen("fcolor.out", "w", stdout);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}

	fill(sizes, sizes + n, 1);

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			parent[i] = i;
			visited[i] = 1;

			for (auto a : adj[i]) {
				if (parent[a] == 0) {
					parent[a] = a;
				}
				int para = find_parent(a);
				if (!in_set[para]) {
					same_color.push_back(para);
					in_set[para] = 1;
				}
			}
			for (auto a : same_color) {
				in_set[a] = 0;
			}
			
			while (same_color.size() > 1) {
				for (auto a : same_color) {
					visited[a] = 1;
				}

				// find new set of same favorite colors
				same_color_next.clear();
				for (auto a : same_color) {
					for (auto b : adj[a]) {
						if (parent[b] == 0) {
							parent[b] = b;
						}
						int parb = find_parent(b);
						if (!in_set[parb]) {
							same_color_next.push_back(parb);
							in_set[parb] = 1;
						}
					}
				}
				for (auto a : same_color_next) {
					in_set[a] = 0;
				}

				// add all of the current cows to the same set since they all have the same favorite color
				for (int j = 0; j < same_color.size() - 1; j++) {
					union_sets(same_color[j], same_color[j + 1]);
				}

				// set the current set of cows to have only 1 cow in the adj list of the parent of the set
				int par = find_parent(same_color.front());
				if (same_color_next.size()) {
					adj[par] = { same_color_next.front() };
				}
				else {
					adj[par].clear();
				}

				same_color = same_color_next;
			}
			same_color.clear();
			same_color_next.clear();
		}
	}

	for (int i = 1; i <= n; i++) {
		int pari = find_parent(i);
		if (color[pari] == 0) {
			color[pari] = ++curr_color;
		}
		
		cout << color[pari] << '\n';
	}
}