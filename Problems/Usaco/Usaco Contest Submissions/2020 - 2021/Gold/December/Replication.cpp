#include<bits/stdc++.h>
using namespace std;

struct loc {
	int i, j, d;
};

struct loc_cmp {
	bool operator()(const loc& a, const loc& b) const {
		return a.d > b.d;
	}
};

const int maxn = 1000;
long long n, d, ans = 0;
vector<int> dx = { 1,0,-1,0 };
vector<int> dy = { 0,1,0,-1 };
string grid[maxn];
int max_replicate[maxn][maxn], dist[maxn][maxn], dist2[maxn][maxn];
bool visited[maxn][maxn];

void bfs_mx_r() {
	queue<loc> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '#') {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		loc c = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			int newi = c.i + dx[k], newj = c.j + dy[k];
			if (1 <= newi and newi < n - 1 and 1 <= newj and newj < n - 1 and
				grid[newi][newj] != '#' and max_replicate[newi][newj] == 0) {
				max_replicate[newi][newj] = max_replicate[c.i][c.j] + 1;
				q.push({ newi,newj });
			}
		}
	}
}

void bfs_visit() {
	queue<loc> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 'S') {
				q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		loc c = q.front(); q.pop();

		if (dist[c.i][c.j] == max_replicate[c.i][c.j] * d) {
			continue;
		}

		for (int k = 0; k < 4; k++) {
			int newi = c.i + dx[k], newj = c.j + dy[k];

			if (1 <= newi and newi < n - 1 and 1 <= newj and newj < n - 1 and
				grid[newi][newj] != '#' and dist[newi][newj] == -1 and 
				dist[c.i][c.j] < max_replicate[newi][newj]*d) {
				dist[newi][newj] = dist[c.i][c.j] + 1;
				q.push({ newi,newj });
			}
		}
	}
}

void bfs_expand_visit() {
	vector<loc> bfs_from;
	priority_queue<loc, vector<loc>, loc_cmp> pq;

	memset(dist2, 0x3f, sizeof(dist2));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] != -1) {
				pq.push({ i,j,-(max_replicate[i][j]-1) });
			}
		}
	}

	while (!pq.empty()) {
		loc c = pq.top(); pq.pop();

		if (c.d < dist2[c.i][c.j]) {
			dist2[c.i][c.j] = c.d;

			for (int k = 0; k < 4; k++) {
				int newi = c.i + dx[k], newj = c.j + dy[k];

				if (1 <= newi and newi < n - 1 and 1 <= newj and newj < n - 1 and
					grid[newi][newj] != '#') {
					pq.push({ newi,newj,c.d+1 });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	bfs_mx_r();
	bfs_visit();
	bfs_expand_visit();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist2[i][j] <= 0) {
				ans++;
			}
		}
	}

	cout << ans;
}