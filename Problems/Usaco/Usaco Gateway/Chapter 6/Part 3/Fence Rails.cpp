/*
ID: elijahj1
TASK: fence8
LANG: C++14
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> boards, rails;
int n, r;
int total_board = 0, curr_total = 0;
int unusable_board = 0;

bool solve(int start_idx, int rail_idx) {
	if (rail_idx == -1) {
		return true;
	}
	if (unusable_board > total_board - curr_total) {
		return false;
	}
	for (int i = start_idx; i < n; i++) {
		if (boards[i] >= rails[rail_idx]) {
			bool ret;
			boards[i] -= rails[rail_idx];
			if (boards[i] < rails[0]) {
				unusable_board += boards[i];
			}
			if (rail_idx > 0 and rails[rail_idx] == rails[rail_idx - 1]) {
				ret = solve(i, rail_idx - 1);
			}
			else {
				ret = solve(0, rail_idx - 1);
			}
			if (boards[i] < rails[0]) {
				unusable_board -= boards[i];
			}
			boards[i] += rails[rail_idx];
			if (ret) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fence8.in", "r", stdin); freopen("fence8.out", "w", stdout);
	cin >> n;
	boards.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> boards[i];
	}
	cin >> r;
	rails.resize(r);
	for (int i = 0; i < r; i++) {
		cin >> rails[i];
	}

	sort(boards.begin(), boards.end(), greater<int>());
	sort(rails.begin(), rails.end());
	total_board = accumulate(boards.begin(), boards.end(), 0);

	
	int lo = 0, hi = r;
	while (lo != hi) {
		int m = (lo + hi + 1) / 2;
		curr_total = accumulate(rails.begin(), rails.begin() + m, 0);
		if (solve(0, m-1)) {
			lo = m;
		}
		else {
			hi = m - 1;
		}
	}
	cout << lo << '\n';
	
	// iterative deepening works, but since the pruning function gets worse the further you get from the answer, it's
	// not 1/1-r times running time at the answer, it's a much larger constant.
	/*
	for (int used = 0; used < r; used++) {
		curr_total += rails[used];
		if (!solve(0, used)) {
			cout << used << '\n';
			return 0;
		}
	}
	cout << r << '\n';
	*/
}