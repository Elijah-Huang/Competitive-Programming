#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

long long dp[5000][5000];
int a[int(1e5)];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("threesum.in", "r", stdin); freopen("threesum.out", "w", stdout);
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		gp_hash_table<int, int> appearances({}, {}, {}, {}, { 1<<13 });
		for (int j = i + 2; j < n; j++) {
			appearances[a[j - 1]]++;
			auto it = appearances.find(-(a[i] + a[j]));
			if (it != appearances.end()) { 
				dp[i][j] = it->second; 
			}
		}
	}
	for (int j = 2; j < n; j++) {
		for (int i = j - 2; i >= 0; i--) {
			dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
		}
	}

	while (q--) {
		int a, b; cin >> a >> b;
		cout << dp[a - 1][b - 1] << '\n';
	}
}