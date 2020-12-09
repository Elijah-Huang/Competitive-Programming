#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> table(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
		}
	}
	vector<int> curr_row(n);
	for (int i = 0; i < n; i++) {
		curr_row[i] = i;
	}
	vector<int> curr_col(m);
	for (int i = 0; i < m; i++) {
		curr_col[i] = i;
	}
	while (k--) {
		char c;
		int x, y; 
		cin >> c >> x >> y;
		x--; y--;
		//cout << c << ' ' << x << ' ' << y << '\n';
		if (c == 'c') {
			swap(curr_col[x], curr_col[y]);
		}
		else if (c == 'r') {
			swap(curr_row[x], curr_row[y]);
		}
		else {
			cout << table[curr_row[x]][curr_col[y]] << '\n';
		}
	}
}