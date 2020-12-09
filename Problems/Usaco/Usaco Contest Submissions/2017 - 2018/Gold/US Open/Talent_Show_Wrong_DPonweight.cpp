#include<bits/stdc++.h>
using namespace std; 

int dp[251][int(2001)];

struct cow {
	int w, t;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("talent.in","r",stdin); freopen("talent.out","w",stdout);
	freopen("8.in", "r", stdin);
	int n, w; cin >> n >> w;
	int border = 0;
	vector<cow> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i].w >> cows[i].t;
	}
	
	sort(cows.begin(), cows.end(), [&](const cow& a, const cow& b) {return a.w < b.w; });
	
	memset(dp, 0x80, sizeof(dp));
	dp[0][0] = 0;
	for (int last = 0; last < n and cows[last].w < w; last++) {
		for (int curr_w = 0; curr_w < w; cur#include<bits/stdc++.h>
			using namespace std;

			int dp[251][int(2001)];

			struct cow {
			int w, t;
		};

			int main() {
				ios_base::sync_with_stdio(0); cin.tie(0);
					//freopen("talent.in","r",stdin); freopen("talent.out","w",stdout);
					freopen("8.in", "r", stdin);
				int n, w; cin >> n >> w;
				int border = 0;
				vector<cow> cows(n);
				for (int i = 0; i < n; i++) {
					cin >> cows[i].w >> cows[i].t;
				}

				sort(cows.begin(), cows.end(), [&](const cow& a, const cow& b) {return a.w < b.w; });

				memset(dp, 0x80, sizeof(dp));
				dp[0][0] = 0;
				for (int last = 0; last < n and cows[last].w < w; last++) {
					for (int curr_w = 0; curr_w < w; curr_w++) {
						dp[last + 1][curr_w] = max(dp[last + 1][curr_w], dp[last][curr_w]);
						dp[last + 1][curr_w + cows[last].w] =
							max(dp[last + 1][curr_w + cows[last].w], dp[last][curr_w] + cows[last].t);
					}
					border = last + 1;
				}

				double best_ratio = 0;
				for (int i = border; i < n; i++) {
					best_ratio = max(best_ratio, double(cows[i].t) / cows[i].w);
				}
				cout << best_ratio << '\n';
				for (int curr_w = w; curr_w < 2 * w; curr_w++) {
					best_ratio = max(best_ratio, double(dp[border][curr_w]) / curr_w);
				}
				cout << best_ratio << '\n';
				for (int curr_w = 0; curr_w < 2 * w; curr_w++) {
					for (int i = border; i < n; i++) {
						best_ratio = max(best_ratio, double(dp[border][curr_w] + cows[i].t) / (curr_w + cows[i].w));
					}
				}

				best_ratio *= 1000;
				if (fabs(round(best_ratio) - best_ratio) < 1e-8) {
					cout << int(round(best_ratio)) << '\n';
				}
				else {
					cout << int(best_ratio) << '\n';
				}
				freopen("8.out", "r", stdin);
				int a; cin >> a; cout << a;
			}r_w++) {
			dp[last + 1][curr_w] = max(dp[last + 1][curr_w], dp[last][curr_w]);
			dp[last + 1][curr_w + cows[last].w] =
				max(dp[last + 1][curr_w + cows[last].w], dp[last][curr_w] + cows[last].t);
		}
		border = last + 1;
	}

	double best_ratio = 0;
	for (int i = border; i < n; i++) {
		best_ratio = max(best_ratio, double(cows[i].t) / cows[i].w);
	}
	cout << best_ratio << '\n';
	for (int curr_w = w; curr_w < 2*w; curr_w++) {
		best_ratio = max(best_ratio, double(dp[border][curr_w]) / curr_w);
	}
	cout << best_ratio << '\n';
	for (int curr_w = 0; curr_w < 2 * w; curr_w++) {
		for (int i = border; i < n; i++) {
			best_ratio = max(best_ratio, double(dp[border][curr_w] + cows[i].t) / (curr_w + cows[i].w));
		}
	}

	best_ratio *= 1000;
	if (fabs(round(best_ratio) - best_ratio) < 1e-8) {
		cout << int(round(best_ratio)) << '\n';
	}
	else {
		cout << int(best_ratio) << '\n';
	}
	freopen("8.out", "r", stdin);
	int a; cin >> a; cout << a;
}