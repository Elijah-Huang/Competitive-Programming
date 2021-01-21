#include<bits/stdc++.h>
using namespace std;

struct loc {
	int i, j;
};

const int mod = 1e9 + 7;

const int maxn = 1000;
int n, m;
long long ans = 1, curr_ans;
string cave[maxn];
int pow2[maxn];

vector<int> dx = { 1,0,-1,0 };
vector<int> dy = { 0,1,0,-1 };
bool visited[maxn][maxn];
vector<vector<loc>> comps;

int parent[maxn * maxn], sz[maxn * maxn], num_comps;

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
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		
		parent[b] = a;
		sz[a] += sz[b];
		num_comps--;
	}
}

void dfs(int i, int j) {
	visited[i][j] = 1;
	comps.back().push_back({ i,j });

	for (int k = 0; k < 4; k++) {
		int newi = i + dx[k], newj = j + dy[k];
		if (0 <= newi and newi < n and 
			0 <= newj and newj < m and
			cave[newi][newj] == '.' and !visited[newi][newj]) {
			dfs(newi, newj);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cave.in", "r", stdin); freopen("cave.out", "w", stdout);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> cave[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cave[i][j] == '.' and !visited[i][j]) {
				comps.resize(comps.size() + 1);
				dfs(i, j);
			}
		}
	}

	pow2[0] = 1;
	for (int i = 1; i < maxn; i++) {
		pow2[i] = pow2[i - 1] * 2 % mod;
	}

	iota(parent, parent + maxn * maxn, 0);
	fill(sz, sz + maxn * maxn, 1);

	for (auto& comp : comps) {
		curr_ans = 1;
		num_comps = 0;

		sort(comp.begin(), comp.end(), [&](const loc& a, const loc& b) {return a.i > b.i; });
		
		for (int i = 0; i < comp.size(); i++) {
			num_comps++;
			for (int k = 0; k < 2; k++) {
				int newi = comp[i].i + dx[k], newj = comp[i].j + dy[k];

				if (newi < n and newj < m and cave[newi][newj] == '.') {
					union_sets(comp[i].i * 1000 + comp[i].j, newi * 1000 + newj);
				}
			}

			if (i == comp.size()-1 or comp[i].i != comp[i + 1].i) {
				curr_ans = (curr_ans + pow2[num_comps]-1 + mod) % mod;
			}
		}

		ans = (ans * curr_ans) % mod;
	}

	cout << ans;
}