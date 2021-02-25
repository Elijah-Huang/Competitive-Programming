#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, k;
int positions[maxn];
vector<int> positions_visited_one_iter[maxn];
vector<int> adj[maxn];
vector<vector<int>> comps(1);
int comp[maxn];
vector<set<int>> positions_visited;

void dfs(int c) {
	comp[c] = comps.size() - 1;
	comps[comps.size() - 1].push_back(c);

	for (auto n : adj[c]) {
		if (!comp[n]) {
			dfs(n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		positions_visited_one_iter[i].push_back(i);
	}

	iota(positions, positions + n, 0);

	while (k--) {
		int a, b; cin >> a >> b; a--; b--;
		
		positions_visited_one_iter[positions[a]].push_back(b);
		positions_visited_one_iter[positions[b]].push_back(a);

		swap(positions[a], positions[b]);
	}

	for (int i = 0; i < n; i++) {
		adj[positions[i]].push_back(i);
	}

	for (int i = 0; i < n; i++) {
		if (!comp[i]) {
			comps.resize(comps.size() + 1);
			dfs(i);
		}
	}

	positions_visited.resize(comps.size());

	for (int i = 1; i < comps.size(); i++) {
		for (auto cow : comps[i]) {
			for (auto pos : positions_visited_one_iter[cow]) {
				positions_visited[i].insert(pos);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << positions_visited[comp[i]].size() << '\n';
	}
}