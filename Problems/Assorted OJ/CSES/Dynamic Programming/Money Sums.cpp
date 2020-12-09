#include<bits/stdc++.h>
using namespace std;

bool dp[2][int(1e5 + 1)];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	dp[0][0] = 1;
	while (n--) {
		int a; cin >> a;
		for (int i = 0; i <= 1e5 - a; i++) {
			if (dp[0][i]) {
				dp[1][i + a] = 1;
			}
		}
		for (int i = 0; i <= 1e5; i++) {
			dp[0][i] |= dp[1][i];
		}
	}

	vector<int> output;
	for (int i = 1; i <= 1e5; i++) {
		if (dp[0][i]) {
			output.push_back(i);
		}
	}

	cout << output.size() << '\n';
	for (auto i : output) {
		cout << i << ' ';
	}
}