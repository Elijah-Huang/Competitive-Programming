#include<bits/stdc++.h>
using namespace std;

vector<int> dx = { 0,1,0,-1 };
vector<int> dy = { -1,0,1,0 };

long long dists[100][100][3];
int fields[100][100];

struct loc {
	int x, y, d, totd;
};

struct loc_cmp {
	bool operator()(const loc& a, const loc& b) const {
		return a.totd > b.totd;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("visitfj.in", "r", stdin); freopen("visitfj.out", "w", stdout);
	int n, t; cin >> n >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> fields[i][j];
		}
	}

	long long mx = 0x7f7f7f7f7f7f7f7f;
	memset(dists, 0x7f, sizeof(dists));
	priority_queue<loc, vector<loc>, loc_cmp> pq;
	pq.push({ 0,0,0,0 });
	while (!pq.empty()) {
		loc curr = pq.top(); pq.pop();
		if (dists[curr.x][curr.y][curr.d % 3] == mx) {
			curr.totd += (curr.d % 3 == 0 and curr.d > 0) * fields[curr.x][curr.y];
			dists[curr.x][curr.y][curr.d % 3] = curr.totd;
			for (int i = 0; i < 4; i++) {
				if (0 <= curr.x + dx[i] and curr.x + dx[i] < n and
					0 <= curr.y + dy[i] and curr.y + dy[i] < n) {
					pq.push({ curr.x + dx[i], curr.y + dy[i], curr.d + 1, curr.totd + t });
				}
			}
		}
	}

	cout << min({ dists[n - 1][n - 1][0], dists[n - 1][n - 1][1], dists[n - 1][n - 1][2] });
}