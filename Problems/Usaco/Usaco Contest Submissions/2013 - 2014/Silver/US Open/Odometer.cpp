#include<bits/stdc++.h>
using namespace std;

long long dp[10][19][19][2][20];
long long dp2[10][10][19][19][2][20];

long long solve0_9(vector<int>& x) {
	// fill, start, end, maxed, total filled
	memset(dp, 0, sizeof(dp));
	for (int end = x.size() - 1; end >= 0; end--) {
		//base case
		for (int i = 1; i <= max((end != x.size() - 1) * 9, x[end]); i++) {
			bool mxed = 0;
			if (end == x.size() - 1 and i == x[end]) {
				mxed = 1;
			}
			for (int fill = 0; fill <= 9; fill++) {
				dp[fill][end][end][mxed][fill == i] += 1;
			}
		}
		//transition
		if (end == 0) {
			break;
		}
		for (int start = x.size() - 1; start >= end; start--) {
			for (int fill = 0; fill <= 9; fill++) {
				for (int filled = 0; filled <= start - end + 1; filled++) {
					for (int mxed = 0; mxed <= 1; mxed++) {
						if (mxed) {
							for (int to_place = 0; to_place <= x[end - 1]; to_place++) {
								dp[fill][start][end - 1][to_place == x[end - 1]][filled + (to_place == fill)]
									+= dp[fill][start][end][mxed][filled];
							}
						}
						else {
							for (int to_place = 0; to_place <= 9; to_place++) {
								dp[fill][start][end - 1][mxed][filled + (to_place == fill)]
									+= dp[fill][start][end][mxed][filled];
							}
						}
					}
				}
			}
		}
	}

	long long tot = 0;
	for (int fill = 0; fill <= 9; fill++) {
		for (int start = x.size() - 1; start >= 0; start--) {
			for (int mxed = 0; mxed <= 1; mxed++) {
				for (int filled = (start + 2) / 2; filled <= start + 1; filled++) {
					tot += dp[fill][start][0][mxed][filled];
				}
			}
		}
	}

	return tot;
}

long long solve_overlap(vector<int>& x) {
	// fill1, fill2, start, end, maxed, fill1 filled
	memset(dp2, 0, sizeof(dp2));
	for (int end = x.size() - 1; end >= 0; end--) {
		//base case
		for (int i = 1; i <= max((end != x.size() - 1) * 9, x[end]); i++) {
			bool mxed = 0;
			if (end == x.size() - 1 and i == x[end]) {
				mxed = 1;
			}
			for (int fill1 = 1; fill1 <= 9; fill1++) {
				for (int fill2 = 0; fill2 < fill1; fill2++) {
					if (i == fill1 or i == fill2) {
						dp2[fill1][fill2][end][end][mxed][fill1 == i] += 1;
					}
				}
			}
		}
		//transition
		if (end == 0) {
			break;
		}
		for (int start = x.size() - 1; start >= end; start--) {
			for (int fill1 = 1; fill1 <= 9; fill1++) {
				for (int fill2 = 0; fill2 < fill1; fill2++) {
					for (int filled = 0; filled <= start - end + 1; filled++) {
						for (int mxed = 0; mxed <= 1; mxed++) {
							vector<int> options = { fill1,fill2 };
							if (mxed) {
								for (auto to_place : options) {
									if (to_place <= x[end - 1]) {
										dp2[fill1][fill2][start][end - 1][to_place == x[end - 1]][filled + (to_place == fill1)]
											+= dp2[fill1][fill2][start][end][mxed][filled];
									}
								}
							
							}
							else {
								for (auto to_place : options) {
									dp2[fill1][fill2][start][end - 1][mxed][filled + (to_place == fill1)]
										+= dp2[fill1][fill2][start][end][mxed][filled];
								}
							}
						}
					}
				}
			}
		}
	}

	long long tot = 0;
	for (int fill1 = 1; fill1 <= 9; fill1++) {
		for (int fill2 = 0; fill2 < fill1; fill2++) {
			for (int start = x.size() - 1; start >= 1; start--) {
				if ((start + 1) % 2 == 0) {
					for (int mxed = 0; mxed <= 1; mxed++) {
						tot += dp2[fill1][fill2][start][0][mxed][(start + 1) / 2];
					}
				}
			}
		}
	}

	return tot;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("odometer.in", "r", stdin); freopen("odometer.out", "w", stdout);
	long long x1, y1;
	cin >> x1 >> y1;
	x1--;
	vector<int> x, y;
	while (x1) {
		x.push_back(x1 % 10);
		x1 /= 10;
	}
	while (y1) {
		y.push_back(y1 % 10);
		y1 /= 10;
	}
	/*cout << solve0_9(y) << ' ' << solve_overlap(y) << '\n';
	cout << solve0_9(x) << ' ' << solve_overlap(x) << '\n';*/
	cout << solve0_9(y) - solve_overlap(y) - (solve0_9(x) - solve_overlap(x));
}