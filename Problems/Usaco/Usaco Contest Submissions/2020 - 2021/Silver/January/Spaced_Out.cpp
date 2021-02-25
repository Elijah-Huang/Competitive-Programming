#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int n;
int a[maxn][maxn];
int ans = 0;

void solve_rows() {
	int mx = 0;

	for (int i = 0; i < n; i++) {
		int row[2]{};
		for (int k = 0; k < 2; k++) {
			for (int j = 0; 2 * j + k < n; j++) {
				row[k] += a[i][2 * j + k];
			}
		}
		
		mx += *max_element(row, row + 2);
	}

	ans = max(ans, mx);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	solve_rows();

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			swap(a[i][j], a[j][i]);
		}
	}

	solve_rows();

	cout << ans;
}