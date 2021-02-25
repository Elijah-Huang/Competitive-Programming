#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
long long n, k, m;
// cows positions
int cows[maxn];
// idx i stores the cow at position i's new position after k swaps
int pos_after_k_swaps[maxn];
// positions visited by a cow after k swaps
vector<int> positions_visited[maxn];
// positions visited after m % k swaps
vector<int> positions_visited_end[maxn];
vector<vector<int>> cycles(1);
int cycle[maxn];
map<int, int> mp;
int ans[maxn];

void erase_m(int a) {
	mp[a]--;
	if (mp[a] == 0) {
		mp.erase(a);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k >> m;
	
	iota(cows, cows + n, 0);
	for (int i = 0; i < n; i++) {
		positions_visited[i].push_back(i);
	}

	for (int i = 0; i < k; i++) {
		if (i == m % k) {
			// ??? got a runtime error 
			//memcpy(positions_visited_end, positions_visited, sizeof(positions_visited));
			copy(positions_visited, positions_visited + n, positions_visited_end);
		}

		int a, b; cin >> a >> b; a--; b--;
		positions_visited[cows[a]].push_back(b);
		positions_visited[cows[b]].push_back(a);
		swap(cows[a], cows[b]);
	}

	for (int i = 0; i < n; i++) {
		pos_after_k_swaps[cows[i]] = i;
	}

	// compute cycles
	for (int i = 0; i < n; i++) {
		if (!cycle[i]) {
			cycles.resize(cycles.size() + 1);
			int curr = i;
			while (cycles.back().empty() or cycles.back()[0] != curr) {
				cycles.back().push_back(curr);
				cycle[curr] = cycles.size() - 1;
				curr = pos_after_k_swaps[curr];
			}
		}
	}

	for (int i = 1; i < cycles.size(); i++) {
		if (m / k >= cycles[i].size()) {
			for (auto j : cycles[i]) {
				for (auto pos : positions_visited[j]) {
					mp[pos]++;
				}
			}
			for (auto j : cycles[i]) {
				ans[j] = mp.size();
			}

			mp.clear();
		}
		else {
			// find the m / k starting positions (starting positions before each k swaps)
			for (int j = 0; j < m / k; j++) {
				for (auto pos : positions_visited[cycles[i][j]]) {
					mp[pos]++;
				}
			}

			for (int j = 0; j < cycles[i].size(); j++) {
				// remove end starting position and add new starting position to transition
				if (j > 0 and m/k > 0) {
					for (auto pos : positions_visited[cycles[i][j - 1]]) {
						erase_m(pos);
					}
					for (auto pos : positions_visited[cycles[i][(j + m / k - 1) % cycles[i].size()]]) {
						mp[pos]++;
					}
				}

				// add the positions reached from m%k swaps
				for (auto pos : positions_visited_end[cycles[i][(j + m / k) % cycles[i].size()]]) {
					mp[pos]++;
				}
				ans[cycles[i][j]] = mp.size();
				for (auto pos : positions_visited_end[cycles[i][(j + m / k) % cycles[i].size()]]) {
					erase_m(pos);
				}
			}

			mp.clear();
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
}