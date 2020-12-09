#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("shuffle.in", "r", stdin); freopen("shuffle.out", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	int needed_shifts = n - m + 1;
	vector<vector<int>> shifts(ilogb(needed_shifts) + 1, vector<int>(n));
	for (int i = 0; i < m; i++) {
		cin >> shifts[0][i];
		shifts[0][i] -= 2;
		if (shifts[0][i] < 0) {
			shifts[0][i] = n - 1;
		}
	}
	for (int i = m; i < n; i++) {
		shifts[0][i] = i - 1;
	}

	vector<int> curr(n);
	for (int i = 0; i < n; i++) {
		curr[shifts[0][i]] = i;
	}

	for (int i = 1; i < ilogb(needed_shifts) + 1; i++) {
		vector<int> next(n);
		for (int j = 0; j < n; j++) {
			next[shifts[i - 1][j]] = curr[j];
			shifts[i][curr[j]] = shifts[i - 1][j];
		}
		curr = next;
	}

	iota(curr.begin(), curr.end(), 1);
	int idx = 0;
	int val = 1;
	while (idx <= ilogb(needed_shifts)) {
		if (val & needed_shifts) {
			vector<int> next(n);
			for (int i = 0; i < n; i++) {
				next[shifts[idx][i]] = curr[i];
			}
			curr = next;
		}
		val <<= 1;
		idx++;
	}
	
	vector<int> next;
	for (int i = m - 2; i >= 0; i--) {
		next.push_back(curr[i]);
	}
	for (int i = n - 1; i >= m - 1; i--) {
		next.push_back(curr[i]);
	}
	curr = next;

	while (q--) {
		int query; cin >> query; query--;
		cout << curr[query] << '\n';
	}
}