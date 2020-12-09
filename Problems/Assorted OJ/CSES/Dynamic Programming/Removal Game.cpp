#include<bits/stdc++.h>
using namespace std;

long long dp[5000][5000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> list(n);
	vector<long long> psum(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < n; i++) {
		psum[i + 1] = psum[i] + list[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i][i] = list[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			dp[j][i] = max(list[j] + psum[i + 1] - psum[j + 1] - dp[j + 1][i],
				list[i] + psum[i] - psum[j] - dp[j][i - 1]);
		}
	}

	cout << dp[0][n - 1];
}