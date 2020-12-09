#include<bits/stdc++.h>
using namespace std;

int dp[2][int(1e5 + 1)];

struct book {
	int price, pages;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, x; cin >> n >> x;
	vector<book> books(n);
	for (int i = 0; i < n; i++) {
		cin >> books[i].price;
	}
	for (int i = 0; i < n; i++) {
		cin >> books[i].pages;
	}

	for (auto& b : books) {
		for (int i = 0; i <= x-b.price; i++) {
			dp[1][i + b.price] = max(dp[0][i + b.price], dp[0][i] + b.pages);
		}
		for (int i = 0; i <= x; i++) {
			dp[0][i] = dp[1][i];
		}
	}

	cout << dp[0][x];
}