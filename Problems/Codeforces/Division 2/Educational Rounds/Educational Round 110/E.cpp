#include<bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 1;

int par[maxn][21];
int depth[maxn];
int amt[maxn];
long long cost[maxn];

int main() {
	int q, a, c; cin >> q >> a >> c;
	amt[0] = a;
	cost[0] = c;

	par[0][0] = 0;
	for (int j = 1; j <= 20; j++) {
		par[0][j] = par[par[0][j - 1]][j - 1];
	}

	for (int i = 1; i <= q; i++) {
		int t; cin >> t;

		if (t == 1) {
			int p, a, c; cin >> p >> a >> c;

			amt[i] = a;
			cost[i] = c;

			depth[i] = depth[p] + 1;

			par[i][0] = p;
			for (int j = 1; j <= 20; j++) {
				par[i][j] = par[par[i][j - 1]][j - 1];
			}
		}
		else {
			int v, w; cin >> v >> w;

			// blifting to find first non zero amount on path
			int v2 = v;
			for (int j = 20; j >= 0; j--) {
				if (amt[par[v2][j]]) {
					v2 = par[v2][j];
				}
			}

			int d = depth[v2];
			long long bought = 0, tot_cost = 0;

			while (1) {
				// buy as much as possible
				if (amt[v2] >= (w - bought)) {
					amt[v2] -= (w - bought);
					tot_cost += (w - bought) * cost[v2];
					bought = w;
					break;
				}
				else {
					tot_cost += amt[v2] * cost[v2];
					bought += amt[v2];
					amt[v2] = 0;
				}

				if (v2 == v) {
					// end of path
					break;
				}
				else {
					// next child on current path
					d++;
					v2 = v;
					for (int j = 20; j >= 0; j--) {
						if (depth[par[v2][j]] >= d) {
							v2 = par[v2][j];
						}
					}
				}
			}

			cout << bought << ' ' << tot_cost << endl;
		}
	}
}