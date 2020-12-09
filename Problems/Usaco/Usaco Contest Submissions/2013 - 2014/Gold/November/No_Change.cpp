#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int k, n, ans = -1;
int coins[16];
int purchases[maxn];
int purchased[maxn];

int val(vector<bool>& bitmask) {
	int ret = 0;
	for (int i = 0; i < bitmask.size(); i++) {
		if (bitmask[i]) {
			ret += (1 << i);
		}
	}

	return ret;
}

int max_purchased(int already_purchased, int coin_amt) {
	int total = purchases[already_purchased] + coin_amt;
	return int(upper_bound(purchases, purchases + n + 1, total) - purchases) - 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("nochange.in", "r", stdin); freopen("nochange.out", "w", stdout);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> coins[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> purchases[i];
		purchases[i] += purchases[i - 1];
	}

	vector<bool> bitmask(k);
	for (int i = k-1; i >= 0; i--) {
		bitmask[i] = 1;
		do {
			int a = val(bitmask);
			for (int i = 0; i < k; i++) {
				if (a & (1 << i)) {
					purchased[a] = max(purchased[a], max_purchased(purchased[a - (1 << i)], coins[i]));
				}
			}

			if (purchased[a] == n) {
				int leftover = 0;
				for (int i = 0; i < k; i++) {
					if (!bitmask[i]) {
						leftover += coins[i];
					}
				}
				ans = max(ans, leftover);
			}
		} while (next_permutation(bitmask.begin(), bitmask.end()));
	}

	cout << ans;
}