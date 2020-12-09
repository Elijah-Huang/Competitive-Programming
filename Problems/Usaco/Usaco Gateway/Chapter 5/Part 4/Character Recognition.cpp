/*
ID: elijahj1
TASK: charrec
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<vector<string>> letters(27, vector<string>(20));
	int cost[27][20][121]{};
	int corruptions[1201], size_best[1201];
	for (int i = 1; i <= 1200; i++) {
		corruptions[i] = 1000000;
	}
	corruptions[0] = 0;
	char char_best[1201];
	freopen("font.in","r",stdin); freopen("charrec.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 20; j++) {
			string row;
			cin >> row;
			letters[i][j] = row;
		}
	}
	freopen("charrec.in","r",stdin);
	int m;
	cin >> m;
	vector<string> input(m+1);
	for (int i = 1; i <= m; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 20; j++) {
			for (int k = 1; k <= m; k++) {
				for (int idx = 0; idx < 20; idx++) {
					cost[i][j][k] += letters[i][j][idx] != input[k][idx];
				}
			}
		}
	}
	for (int i = 19; i <= m; i++) {
		if (i >= 19) {
			int best_costi1 = 500;
			int best_char1 = 0;
			for (int c = 0; c < 27; c++) {
				for (int missing = 0; missing < 20; missing++) {
					int curr_cost = 0;
					int i2 = i;
					for (int curr = i - 18; curr <= i; curr++) {
						if (curr - (i - 18) != missing) {
							curr_cost += cost[c][curr - (i2 - 18)][curr];
						}
						else {
							i2--;
							curr_cost += cost[c][curr - (i2 - 18)][curr];
						}
					}
					if (curr_cost < best_costi1) {
						best_costi1 = curr_cost;
						best_char1 = c;
					}
				}
			}
			if (corruptions[i] > corruptions[i - 19] + best_costi1) {
				corruptions[i] = corruptions[i - 19] + best_costi1;
				size_best[i] = 19;
				if (best_char1 != 0) {
					char_best[i] = char(best_char1 + 96);
				}
				else {
					char_best[i] = ' ';
				}
			}		
		}
		if (i >= 20) {
			int best_costi2 = 500;
			int best_char2 = 0;
			for (int c = 0; c < 27; c++) {
				int curr_cost = 0;
				for (int curr = i - 19; curr <= i; curr++) {
					curr_cost += cost[c][curr - (i - 19)][curr];
				}
				if (curr_cost < best_costi2) {
					best_costi2 = curr_cost;
					best_char2 = c;
				}
			}
			if (corruptions[i] > corruptions[i - 20] + best_costi2) {
				corruptions[i] = corruptions[i - 20] + best_costi2;
				size_best[i] = 20;
				if (best_char2 != 0) {
					char_best[i] = char(best_char2 + 96);
				}
				else {
					char_best[i] = ' ';
				}
			}
		}
		if (i >= 21) {
			int best_costi3 = 500;
			int best_char3 = 0;
			for (int c = 0; c < 27; c++) {
				for (int duplicate = 0; duplicate < 20; duplicate++) {
					int curr_cost = 0;
					int i2 = i;
					for (int curr = i - 20; curr <= i; curr++) {
						if ((curr - (i - 20)) != duplicate) {
							curr_cost += cost[c][curr - (i2 - 20)][curr];
						}
						else {
							curr_cost += min(cost[c][curr - (i - 20)][curr],
								cost[c][curr - (i - 20)][curr + 1]);
							curr++;
							i2++;
						}
					}
					if (curr_cost < best_costi3) {
						best_costi3 = curr_cost;
						best_char3 = c;
					}
				}
			}
			if (corruptions[i] > corruptions[i - 21] + best_costi3) {
				corruptions[i] = corruptions[i - 21] + best_costi3;
				size_best[i] = 21;
				if (best_char3 != 0) {
					char_best[i] = char(best_char3 + 96);
				}
				else {
					char_best[i] = ' ';
				}
			}
		}
	}
	string ans = "";
	int loc = m;
	while (loc) {
		ans += char_best[loc];
		loc -= size_best[loc];
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}