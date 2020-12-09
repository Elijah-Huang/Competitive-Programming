#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cbarn2.in", "r", stdin); freopen("cbarn2.out", "w", stdout);
	int n, k; cin >> n >> k;
	if (k >= n) {
		cout << 0;
		return 0;
	}
	vector<int> rooms(n);
	for (int i = 0; i < n; i++) {
		cin >> rooms[n - 1 - i];
	}
	rooms.insert(rooms.end(), rooms.begin(), rooms.end());

	long long mn_move = 1ll << 62;
	for (int start = 0; start < n; start++) {
		vector<int> curr_rooms(rooms.begin() + start, rooms.begin() + start + n);
		vector<int> psum(1);
		for (int i = 0; i < n; i++) {
			psum.push_back(psum.back() + curr_rooms[i]);
		}
		long long dp[100][8];
		memset(dp, 0x3f, sizeof(dp));
		dp[0][1] = 0;
		// if k is one
		long long mn_cost_one = 0;
		for (int loc2 = n - 1; loc2 >= 1; loc2--) {
			mn_cost_one += (n - loc2) * (curr_rooms[loc2]);
		}
		mn_move = min(mn_move, mn_cost_one);
		for (int loc = 0; loc < n; loc++) {
			for (int last = 1; last < k; last++) {
				long long cost = 0;
				long long finish_cost = 0;
				for (int loc2 = n-1; loc2 >= loc + 1; loc2--) {
					finish_cost += (n - loc2) * (curr_rooms[loc2]);
				}
				for (int next_loc = loc + 1; next_loc < n; next_loc++) {
					cost += psum[next_loc] - psum[loc + 1];
					finish_cost -= curr_rooms[next_loc] * (n - next_loc);
					dp[next_loc][last + 1] = min(dp[next_loc][last + 1], dp[loc][last] + cost);
					if (last + 1 == k) {
						dp[next_loc][last + 1] += finish_cost;
						mn_move = min(mn_move, dp[next_loc][last + 1]);
					}
				}
			}
		}
	}

	cout << mn_move << '\n';
}