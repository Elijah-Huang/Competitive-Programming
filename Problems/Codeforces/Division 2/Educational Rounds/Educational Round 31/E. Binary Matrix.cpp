#include<bits/stdc++.h>
using namespace std;

const int maxn = 1 << 12, maxm = 1 << 14;
int n, m;
// par[0-m-1] -> current row | par[m-2*m-1] -> row above | par[2*m-3*m-1] -> parent of sets 
int par[3 * maxm], par2[3 * maxm], conv_par_of_set[3 * maxm];
string row, prev_row;
int ones = 0;
int merges = 0;

int find_parent(int a) {
	if (a == par[a]) {
		return a;
	}
	return par[a] = find_parent(par[a]);
}

void union_sets(int a, int b){
	a = find_parent(a);
	b = find_parent(b);

	if (a != b) {
		merges += 1;
		par[b] = a;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		iota(par, par + m, 0);

		string unconverted_row; cin >> unconverted_row;

		// convert row from hexadecimal to binary
		for (auto j : unconverted_row) {
			int a = 0;
			string converted;

			if (j >= 65) {
				a = j - 'A' + 10;
			}
			else {
				a = j - '0';
			}

			for (int bits = 4; bits > 0; bits--) {
				ones += a & 1;
				converted += ('0' + (a & 1));
				a >>= 1;
			}

			reverse(converted.begin(), converted.end());
			row += converted;
		}

		// merging current row
		for (int j = 1; j < m; j++) {
			if (row[j] == '1' and row[j-1] == '1') {
				union_sets(j - 1, j);
			}
		}

		// merging with above row
		if (i) {
			for (int j = 0; j < m; j++) {
				if (row[j] == '1' and prev_row[j] == '1') {
					union_sets(j, m + j);
				}
			}
		}

		// shifting indices 
		int set_num = 0;
		iota(par2, par2 + 3 * m, 0);
		memset(conv_par_of_set, 0, sizeof(conv_par_of_set));
		for (int j = 0; j < m; j++) {
			if (row[j] == '1') {
				int par_of_set = find_parent(j);
				if (conv_par_of_set[par_of_set] == 0) {
					conv_par_of_set[par_of_set] = 2*m + set_num++;
				}

				par2[m + j] = conv_par_of_set[par_of_set];
			}
		}

		memcpy(par, par2, sizeof(par2));
		prev_row = row;
		row.clear();
	}

	cout << ones - merges;
}