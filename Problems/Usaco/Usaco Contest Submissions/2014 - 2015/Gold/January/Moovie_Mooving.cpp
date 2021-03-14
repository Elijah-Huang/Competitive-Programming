#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;
int n, l;
vector<int> showtimes[maxn];
int duration[maxn];
// dp[i] -> maximum endtime of a set of shows that covers a contiguous period of time from 0
int dp[1 << maxn];
int min_movies = maxn + 1;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("movie.in", "r", stdin); freopen("movie.out", "w", stdout);

	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> duration[i];
		int c; cin >> c;
		while (c--) {
			int a; cin >> a;
			showtimes[i].push_back(a);
		}
	}

	for (int i = 1; i < (1 << n); i++) {
		int movies = 0;

		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				movies++;
				int l = 0, r = showtimes[j].size() - 1;
				while (l != r) {
					int m = (l + r + 1) / 2;
					if (showtimes[j][m] <= dp[i - (1 << j)]) {
						l = m;
					}
					else {
						r = m - 1;
					}
				}

				if (showtimes[j][l] <= dp[i - (1 << j)]) {
					dp[i] = max(dp[i], max(dp[i-(1<<j)], showtimes[j][l] + duration[j]));
				}
			}
		}

		if (dp[i] >= l) {
			min_movies = min(min_movies, movies);
		}
	}

	if (min_movies == maxn + 1) {
		cout << -1;
	}
	else {
		cout << min_movies;
	}
}