#include<bits/stdc++.h>
using namespace std;

const int maxn = 20210424;
bool dp[maxn + 200];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	dp[maxn] = 1;

	for (int i = maxn; i >= 1; i--) {
		if (dp[i+123] == 0 or dp[i + 1] == 0) {
			dp[i] = 1;
		}
		else {
			dp[i] = 0;
		}
		//cout << i << ' ' << dp[i] << '\n';
	}

	int n; cin >> n;

	while (n--) {
		int a; cin >> a;
		if (dp[a]) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
}