#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, maxn = 1000;
int n, m;
long long ans = 1, curr_comp_ans;
string cave[maxn];

vector<int> dx = { 1,0,-1,0 };
vector<int> dy = { 0,1,0,-1 };
bool visited[maxn][maxn];
int top, bot;
vector<int> curr_comp[maxn];

int p[maxn * maxn], sz[maxn * maxn];
long long paintings[maxn * maxn];
vector<int> parents;
bool seen[maxn * maxn];

int find_parent(int a) {
	if (a == p[a]) {
		return a;
	}
	return p[a] = find_parent(p[a]);
}

void union_sets(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	
	if (a != b) {
		if (sz[a] < sz[b]) {
			swap(a, b);
		}

		p[b] = a;
		sz[a] += sz[b];
		paintings[a] = paintings[a] * paintings[b] % mod;
	}
}

void dfs(int i, int j) {
	visited[i][j] = 1;
	curr_comp[i].push_back(j);
	top = min(top, i);
	bot = max(bot, i);
	
	for (int k = 0; k < 4; k++) {
		int newi = i + dx[k];
		int newj = j + dy[k];
		if (0 <= newi and newi < n and
			0 <= newj and newj < m and
			!visited[newi][newj] and
			cave[newi][newj] == '.') {
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

	iota(p, p + maxn * maxn, 0);
	fill(sz, sz + maxn * maxn, 1);
	fill(paintings, paintings + maxn * maxn, 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] and cave[i][j] == '.') {
				top = maxn + 1;
				bot = -1;
				dfs(i, j);

				for (int i = bot; i >= top; i--) {
					for (auto j: curr_comp[i]){
						for (int k = 0; k < 4; k++) {
							int newi = i + dx[k];
							int newj = j + dy[k];
							if (newi >= i and
								0 <= newi and newi < n and
								0 <= newj and newj < m and
								cave[newi][newj] == '.') {
								union_sets(1000 * i + j, 1000 * newi + newj);
							}
						}
					}

					while (!curr_comp[i].empty()) {
						parents.push_back(find_parent(1000 * i + curr_comp[i].back()));
						curr_comp[i].pop_back();
					}
					for (auto curr_p : parents) {
						if (!seen[curr_p]) {
							paintings[curr_p]++;
							seen[curr_p] = 1;
						}
					}
					
					if (i == top) {
						curr_comp_ans = paintings[parents[0]];
						ans = (ans * curr_comp_ans) % mod;
					}

					while (!parents.empty()) {
						seen[parents.back()] = 0;
						parents.pop_back();
					}
				}
			}
		}
	}

	cout << ans;
}