#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("msched.in", "r", stdin); freopen("msched.out", "w", stdout);
	int n; cin >> n;
	int mx_milk = 0;
	vector<vector<int>> dp(int(1e5 + 1));
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int g, x;
		cin >> g >> x;
		x--;
		dp[x].push_back(g);
	}

	for (int loc = 1e5; loc >= 0; loc--) {
		for (auto milk : dp[loc]) {
			pq.push(milk);
		}
		if (!pq.empty()) {
			mx_milk += pq.top();
			pq.pop();
		}
	}

	cout << mx_milk;

}