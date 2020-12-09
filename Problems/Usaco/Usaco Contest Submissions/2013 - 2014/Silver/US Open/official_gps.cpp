#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<cstring>
#include<stack>
#include<queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> edge;

const int maxn = 10003, inf = 1 << 29;
int N, M;
vector<pii> va[maxn];
vector<pii> vb[maxn];
vector<pii> v[maxn];
int dist[3][maxn];

int dij(vector<pii> v[maxn], int a, int src) {
	for (int i = 0; i < maxn; i++) {
		dist[a][i] = inf;
	}
	dist[a][src] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(pii(0, src));
	while (pq.size()) {
		int cur = pq.top().second;
		int dst = pq.top().first;
		pq.pop();
		if (dst != dist[a][cur]) {
			continue;
		}
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i].first;
			int c = v[cur][i].second + dist[a][cur];
			if (c < dist[a][nxt]) {
				dist[a][nxt] = c;
				pq.push(pii(dist[a][nxt], nxt));
			}
		}
	}
	return dist[a][N - 1];
}
int main() {
	freopen("8.in", "r", stdin);
	//freopen("gpsduel.out", "w", stdout);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b, p, q;
		scanf("%d%d%d%d", &a, &b, &p, &q);
		a--; b--;
		va[b].push_back(pii(a, p));
		vb[b].push_back(pii(a, q));
	}
	dij(va, 0, N - 1);
	dij(vb, 1, N - 1);

	for (int cur = 0; cur < N; cur++) {
		for (int j = 0; j < va[cur].size(); j++) {
			int nxt = va[cur][j].first;
			int c = 0;
			int dst1 = va[cur][j].second, dst2 = vb[cur][j].second;
			if (dist[0][nxt] - dist[0][cur] != dst1) c++;
			if (dist[1][nxt] - dist[1][cur] != dst2) c++;
			v[nxt].push_back(pii(cur, c));
		}
	}

	int ans = dij(v, 2, 0);
	printf("%d\n", ans);
}