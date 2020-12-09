#include<bits/stdc++.h>
using namespace std;

const int maxn = 4e4 + 1;
unsigned int left_val[maxn], right_val[maxn], lft[maxn], rght[maxn];
vector<int> adj[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("route.in", "r", stdin); freopen("route.out", "w", stdout);
	int n, m, r; cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> left_val[i];
		lft[i] = left_val[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> right_val[i];
		rght[i] = right_val[i];
	}
	for (int i = 0; i < r; i++) {
		int a, b; cin >> a >> b;
		adj[b].push_back(a);
	}

	for (int i = 1; i <= m; i++) {
		sort(adj[i].begin(), adj[i].end());
		for (auto j : adj[i]) {
			rght[i] = max(rght[i], right_val[i] + lft[j]);
		}
		
		unsigned int curr_mx = right_val[i];
		for (auto j : adj[i]) {
			unsigned int new_mx = max(curr_mx, lft[j] + right_val[i]);
			lft[j] = max(lft[j], curr_mx + left_val[j]);
			curr_mx = new_mx;
		}
	}

	cout << max(*max_element(lft, lft + maxn), *max_element(rght, rght + maxn));
}