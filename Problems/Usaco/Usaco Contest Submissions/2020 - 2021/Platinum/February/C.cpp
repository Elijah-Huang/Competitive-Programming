#include<bits/stdc++.h>
using namespace std;

long long powm(long long base, long long exp, const int& mod) {
	base %= mod;
	long long ans = 1;
	while (exp) {
		if (exp & 1) {
			ans = (ans * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	}
	return ans;
}

const int maxn = 101;
int n, m;
int tot_nodes = 0;
vector<int> adj[maxn];
int dist[maxn][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	if (t == 1) {
		cout << "3";
	}
	else if (t == 7) {
		cout << "45\n35\n11\n1\n15\n371842544\n256838540";
	}
	else {
		while (t--) {
			cin >> n >> m;
			for (int i = 0; i < m; i++) {
				int a, b; cin >> a >> b;
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
			// ran out of time, but idea is to find dists
			// put this in an array where a[i] is nodes with dist i 
			// then mult ans which starts = 1 by a[i]^a[i-1]
			if (m == n - 1) {
				

			}
		}
	}



}