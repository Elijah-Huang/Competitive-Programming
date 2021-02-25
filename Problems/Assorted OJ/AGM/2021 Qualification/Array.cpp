#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5, maxk = 100, maxd = 500;
int n, k, d, q;
int col[maxn], costt[maxn];
long long cost[maxk][maxd], tot_cost[maxk], change[maxk][maxd],
// front and back // excluding i | rest sum % mod = j
dp[2][maxk][maxd], min_cost_change[maxk][maxd];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> d;

	for (int i = 0; i < n; i++) {
		cin >> col[i];
		col[i] %= d;
	}

	for (int i = 0; i < n; i++) {
		cin >> costt[i];
	}

	cin >> q;
	

	for (int i = 0; i < n; i++) {
		cost[i % k][col[i]] += costt[i];
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < d; j++) {
			tot_cost[i] += cost[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < d; j++) {
			change[i][j] = tot_cost[i] - cost[i][j];
		}
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 1; i < k; i++) {
		vector<long long> temp(d, 1e18);
		for (int j = 0; j < d; j++) {
			for (int j2 = 0; j2 < d; j2++) {
				temp[j] = min(temp[j], dp[0][i - 1][j2] + change[i - 1][(j + d - j2) % d]);
			}
		}
		for (int j = 0; j < d; j++) {
			dp[0][i][j] = temp[j];
		}
	}
	dp[1][k - 1][0] = 0;
	for (int i = k-2; i >=0; i--) {
		vector<long long> temp(d, 1e18);
		for (int j = 0; j < d; j++) {
			for (int j2 = 0; j2 < d; j2++) {
				temp[j] = min(temp[j], dp[1][i + 1][j2] + change[i + 1][(j + d - j2) % d]);
			}
		}
		for (int j = 0; j < d; j++) {
			dp[1][i][j] = temp[j];
		}
	}

	memset(min_cost_change, 0x3f, sizeof(min_cost_change));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < d; j++) {
			for (int j2 = 0; j2 < d; j2++) {
				min_cost_change[i][(j + j2) % d] = min(min_cost_change[i][(j+j2)%d], dp[0][i][j] + dp[1][i][j2]);
			}
		}
	}


	while (q--) {
		int pos; cin >> pos; pos--;
		cout << change[pos % k][col[pos]] + min_cost_change[pos % k][(d - col[pos]) % d] << '\n';
	}
}