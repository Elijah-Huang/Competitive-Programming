#include<bits/stdc++.h>
using namespace std;

const int maxn = 50;
int n;
string grid[maxn];
int dp[maxn][maxn][maxn][maxn];
bool vis[maxn][maxn][maxn][maxn];
int psum[2][maxn][maxn];

void solve(int i, int j, int i2, int j2) {
	vis[i][j][i2][j2] = 1;
	dp[i][j][i2][j2] = max(j2 - j + 1, i2 - i + 1);

	for (int midi = i; midi <= i2; midi++) {
		if (psum[0][midi][j2] - (j ? psum[0][midi][j-1]: 0) == 0) {
			if (midi-1 >= i and !vis[i][j][midi-1][j2]) {
				solve(i, j, midi-1, j2);
			}
			if (midi+1 <= i2 and !vis[midi+1][j][i2][j2]) {
				solve(midi+1, j, i2, j2);
			}

			dp[i][j][i2][j2] = min({ dp[i][j][i2][j2], (midi - 1 >= i ? dp[i][j][midi - 1][j2] : 0) + (midi + 1 <= i2 ? dp[midi + 1][j][i2][j2] : 0 )});
		}
	}

	for (int midj = j; midj <= j2; midj++) {
		if (psum[1][i2][midj] - (i ? psum[1][i-1][midj] : 0) == 0) {
			if (midj+1 <= j2 and !vis[i][midj+1][i2][j2]) {
				solve(i, midj+1, i2, j2);
			}
			if (midj-1 >= j and !vis[i][j][i2][midj-1]) {
				solve(i, j, i2, midj-1);
			}

			dp[i][j][i2][j2] = min({ dp[i][j][i2][j2], (midj+1 <= j2 ? dp[i][midj + 1][i2][j2] : 0) + (midj-1 >= j ? dp[i][j][i2][midj - 1] : 0) });
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	for (int i = 0; i < n; i++) {
		psum[0][i][0] = grid[i][0] == '#';
		for (int j = 1; j < n; j++){
			psum[0][i][j] = psum[0][i][j - 1] + (grid[i][j] == '#');
		}
	}

	for (int j = 0; j < n; j++) {
		psum[1][0][j] = grid[0][j] == '#';
		for (int i = 1; i < n; i++) {
			psum[1][i][j] = psum[1][i - 1][j] + (grid[i][j] == '#');
		}
	}
	
	solve(0, 0, n - 1, n - 1);
	cout << dp[0][0][n - 1][n - 1];
}