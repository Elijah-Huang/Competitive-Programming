#include<bits/stdc++.h>
using namespace std;

struct edge {
	int v;
	long long c;
	int l;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("cowroute.in", "r", stdin); freopen("cowroute.out", "w", stdout);
	//freopen("12.in", "r", stdin);
	int a, b, n; cin >> a >> b >> n; a--; b--;
	/*cout << n << '\n';
	cout << a << ' ' <<  b << '\n';*/
	vector<vector<edge>> adj(1000);
	for (int i = 0; i < n; i++) {
		int w, L; cin >> w >> L;
		vector<int> route;
		for (int j = 0; j < L; j++) {
			int a; cin >> a; a--;
			route.push_back(a);
		}
		for (int j = 0; j < L - 1; j++) {
			for (int k = j + 1; k < L; k++) {
				adj[route[j]].push_back({ route[k], w, k-j });
			}
		}
	}

	vector<edge> costs(1000, { 0, 1ll << 60, 0 });
	vector<bool> shortest(1000);
	costs[a] = { 0,0,0};
	for (int i = 0; i < 999; i++) {
		int least_idx = -1;
		long long least_cost = 1ll << 60;
		for (int j = 0; j < 1000; j++) {
			if (!shortest[j] and costs[j].c < least_cost) {
				least_idx = j;
				least_cost = costs[j].c;
			}
		}
		if (least_cost == 1ll << 60) {
			break;
		}
		shortest[least_idx] = 1;
		for (auto& neighbor : adj[least_idx]) {
			if (costs[neighbor.v].c > costs[least_idx].c + neighbor.c) {
				costs[neighbor.v].l = costs[least_idx].l + neighbor.l;
				costs[neighbor.v].c = costs[least_idx].c + neighbor.c;
			}
			else if (costs[neighbor.v].c == costs[least_idx].c + neighbor.c) {
				costs[neighbor.v].l = min(costs[least_idx].l + neighbor.l, costs[neighbor.v].l);
			}
		}
	}

	if (costs[b].c == 1ll << 60) {
		cout << "-1 -1\n";
	}
	else {
		cout << costs[b].c << ' ' << costs[b].l << '\n';
	}
	/*freopen("12.out", "r", stdin);
	long long aa, ab; cin >> aa >> ab;
	cout << aa << ' ' << ab;*/
}