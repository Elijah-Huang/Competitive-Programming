#include<bits/stdc++.h>
#include<array>
using namespace std;

const int maxn = 1001;
int l, n, ans = 1 << 30, best_state = 0;
int c[maxn][maxn];
int q[maxn];
// min cost such that the 2 other people are at the location represented by the state
int dp[200 * 200], dp2[200 * 200];
// stores the previous location of the person who has now been moved to answer the current query
unsigned char prev_loc[maxn][200 * 200];
vector<array<int, 3>> path;
vector<array<int, 2>> movee;
int person[200];

int state(int i, int j) {
	if (i > j) {
		swap(i, j);
	}
	return 200 * i + j;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> l >> n;

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			cin >> c[i][j];
		}
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[state(0, 1)] = 0;
	q[0] = 2;
	for (int i = 1; i <= n; i++) {
		memset(dp2, 0x3f, sizeof(dp2));
		cin >> q[i]; q[i]--;

		for (int curr_state = 0; curr_state < l*200; curr_state++) {
			vector<int> vals = { q[i-1], curr_state / 200, curr_state % 200 };
			int j = find(vals.begin(), vals.end(), q[i]) - vals.begin();

			if (j == 3) {
				for (int j = 0; j < 3; j++) {
					int new_state = state(vals[(j + 1) % 3], vals[(j + 2) % 3]);
					if (dp2[new_state] > dp[curr_state] + c[vals[j]][q[i]]) {
						dp2[new_state] = dp[curr_state] + c[vals[j]][q[i]];
						prev_loc[i][new_state] = vals[j];
					}
				}
			}
			else {
				int new_state = state(vals[(j + 1) % 3], vals[(j + 2) % 3]);
				if (dp2[new_state] > dp[curr_state] + c[vals[j]][q[i]]) {
					dp2[new_state] = dp[curr_state] + c[vals[j]][q[i]];
					prev_loc[i][new_state] = vals[j];
				}
			}
		}
		
		memcpy(dp, dp2, sizeof(dp));
	}

	for (int i = 0; i < l*200; i++) {
		if (ans > dp[i]) {
			ans = dp[i];
			best_state = i;
		}
	}

	path.push_back({ q[n], best_state / 200, best_state % 200 });
	while (path.size() != n + 1) {
		for (int i = 0; i < 3; i++) {
			int q_num = n + 1 - path.size();

			if (path.back()[i] == q[q_num]) {
				int curr_state = state(path.back()[(i + 1) % 3], path.back()[(i + 2) % 3]);
				movee.push_back({ int(prev_loc[q_num][curr_state]), q[n + 1 - path.size()] });
				path.push_back({ int(prev_loc[q_num][curr_state]), path.back()[(i + 1) % 3], path.back()[(i + 2) % 3] });
				break;
			}
		}
	}
	reverse(path.begin(), path.end());
	reverse(movee.begin(), movee.end());

	cout << ans << '\n';
	
	person[0] = 1; person[1] = 2; person[2] = 3;
	for (auto move: movee) {
		person[move[1]] = person[move[0]];
		cout << person[move[1]] << ' ';
	}
}