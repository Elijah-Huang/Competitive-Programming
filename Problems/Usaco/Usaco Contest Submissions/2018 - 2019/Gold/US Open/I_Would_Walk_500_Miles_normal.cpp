#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("walk.in", "r", stdin); freopen("walk.out", "w", stdout);
	int n, k; cin >> n >> k;
	vector<int> dists(n, 21e8);
	vector<bool> in_mst(n);
	vector<int> edges_in_mst;

	dists[0] = 0;
	for (int i = 0; i < n; i++) {
		int closest = 0;
		int dist = 21e8;
		for (int j = 0; j < n; j++) {
			if (!in_mst[j] and dists[j] < dist) {
				closest = j;
				dist = dists[j];
			}
		}
		if (dist != 0) {
			edges_in_mst.push_back(dist);
		}
		in_mst[closest] = 1;
		for (int j = 0; j < n; j++) {
			long long x = min(closest, j);
			long long y = max(closest, j);
			dists[j] = min(dists[j], int((2019201913 * (x+1) + 2019201949 * (y+1)) % 2019201997));
		}
	}
	sort(edges_in_mst.begin(), edges_in_mst.end());
	cout << edges_in_mst[edges_in_mst.size() - (k - 1)];
}