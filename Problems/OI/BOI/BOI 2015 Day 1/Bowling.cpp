#include<bits/stdc++.h>
using namespace std;

int q, n;
string s;
vector<string> frames(11);
vector<int> frame_points(11);
// frame | bonus points needed for frame | # of bonus shots for that frame | bonus points needed for previous frame | bonus shots for that frame
long long dp[11][21][3][11][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> q;
	while (q--) {
		cin >> n;

		getline(cin,s);
		for (int i = 1; i <= n - 1; i++) {
			frames[i] = s.substr(2 * i - 2, 2);
		}
		frames[n] = s.substr(2 * n-2, 3);

		for (int i = 1; i <= n; i++) {
			cin >> frame_points[i];
		}

		memset(dp, 0, sizeof(dp));
		dp[0][0][0][0][0] = 1;
		for (int frame = 0; frame <= n-1; frame++) {
			for (int bonus = 0; bonus <= 20; bonus++) {
				for (int bshots = 0; bshots <= 2; bshots++) {
					for (int prev_bonus = 0; prev_bonus <= 10; prev_bonus++) {
						long long ways = dp[frame][bonus][bshots][prev_bonus];
						if (frame < n - 1) {
							if (frames[frame] == "??") {
								if (prev_bonus) {
									if (prev_bonus == 10) {
										if (frame_points[frame] >= 10) {
											if (bonus >= 10 and bshots == 2) {
												dp[frame + 1][frame_points[frame] - 10][2][bonus - 10] += ways;
											}
											else if (bonus == 10) {
												dp[frame+1][frame_points[frame]-10][2][0] 
											}
										}
									}
									else {

									}
								}
							}
							else if (frames[frame][1] == '?') {

							}
							else if (frames[frame][0] == '?') {
								
							}
							else {
								int a = stoi(frames[frame]);
								int score1 = a / 10, score2 = a % 10;

								if (score1 == prev_bonus and 
									(bshots == 2 and score1 + score2 == bonus or 
									bshots == 1 and score1 == bonus or 
									bshots == 0 and bonus == 0)) {
									dp[frame + 1][0][0][0] += ways;
								}
							}
						}
						else {

						}
					}
				}
			}
		}



	}
}