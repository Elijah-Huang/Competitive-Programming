#include<bits/stdc++.h>
using namespace std;

struct edge {
	long long c;
	int l;
};

edge adj[1000][1000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowroute.in", "r", stdin); freopen("cowroute.out", "w", stdout);
	memset(adj, 0x3f, sizeof(adj));
	int a, b, n; cin >> a >> b >> n; a--; b--;
	for (int i = 0; i < n; i++) {
		int w, L; cin >> w >> L;
		vector<int> route;
		for (int j = 0; j < L; j++) {
			int a; cin >> a; a--;
			route.push_back(a);
		}
		for (int j = 0; j < L - 1; j++) {
			for (int k = j + 1; k < L; k++) {
				if (adj[route[j]][route[k]].c > w) {
					adj[route[j]][route[k]] = { w, k - j };
				}
				else if(adj[route[j]][route[k]].c == w) {
					adj[route[j]][route[k]].l = min(adj[route[j]][route[k]].l, k - j);
				}
			}
		}
	}

	vector<edge> costs(1000, { 1ll << 50, 0 });
	vector<bool> shortest(1000);
	costs[a] = { 0,0};
	for (int i = 0; i < 999; i++) {
		int least_idx = -1;
		long long least_cost = 1ll << 50;
		for (int j = 0; j < 1000; j++) {
			if (!shortest[j] and costs[j].c < least_cost) {
				least_idx = j;
				least_cost = costs[j].c;
			}
		}
		if (least_idx == -1) {
			break;
		}
		shortest[least_idx] = 1;
		for (int j = 0; j < 1000; j++) {
			if (costs[j].c > costs[least_idx].c + adj[least_idx][j].c) {
				costs[j].c = costs[least_idx].c + adj[least_idx][j].c;
				costs[j].l = costs[least_idx].l + adj[least_idx][j].l;
			}
			else if (costs[j].c == costs[least_idx].c + adj[least_idx][j].c) {
				costs[j].l = min(costs[j].l, costs[least_idx].l + adj[least_idx][j].l);
			}
		}
	}

	if (costs[b].c == 1ll << 50) {
		cout << "-1 -1\n";
	}
	else {
		cout << costs[b].c << ' ' << costs[b].l << '\n';
	}
}