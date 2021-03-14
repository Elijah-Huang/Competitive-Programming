// O(Q*log_3(maxa)*12)
#include<bits/stdc++.h>
using namespace std;

int q;

// digit dp to solve x = 0 and y = y2, d = d2
long long solvep(long long y2, long long d2) {
	if (d2 < 0) {
		return 0;
	}

	// pos | carryover | exceeds prefix
	long long dp[40][2][2]{};
	vector<int> y(1), d(1);

	while (y2) {
		y.push_back(y2 % 3);
		y2 /= 3;
	}
	// extra zeros in conjunction with carry ensure we calculate the right digit at each idx
	y.resize(40);
	while (d2) {
		d.push_back(d2 % 3);
		d2 /= 3;
	}
	// extra zeros ensure d2 <= d
	d.resize(40);

	// # of ways to choose a number d2 <= d such that base 3 digits of d2 and 
	// y + d2 sum to 0 % 2 for all digits with idx < 40 -> same as all digits
	// (because 3^40-1 > 2^60)
	dp[0][0][0] = 1;
	for (int pos = 0; pos < 40-1; pos++) {
		for (int carry = 0; carry < 2; carry++) {
			for (int prefix = 0; prefix < 2; prefix++) {
				for (int next_digit = 0; next_digit < 3; next_digit++) {
					int carry2, prefix2, y_val_at_pos;

					if (next_digit > d[pos + 1] or next_digit == d[pos + 1] and prefix) {
						prefix2 = 1;
					}
					else {
						prefix2 = 0;
					}

					y_val_at_pos = y[pos + 1] + next_digit + carry;
					carry2 = y_val_at_pos >= 3;
					y_val_at_pos %= 3;
					
					if ((y_val_at_pos + next_digit) % 2 == 0) {
						dp[pos + 1][carry2][prefix2] += dp[pos][carry][prefix];
					}
				}
			}
		}
	}
	
	// meaning of the dp state
	// 0 % 2 sum up to idx 39 | no carryover (38th idx can't = 1 (3^38>2^60)) | d2 <= d
	return dp[39][0][0];
}

long long solve(long long x, long long y, long long d) {
	if (x > y) {
		swap(x, y);
	}

	// query can be broken into 2 "prefix" queries (x = 0)
	return solvep(y - x, x + d) - solvep(y - x, x - 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> q;

	while (q--) {
		long long d, x, y;
		cin >> d >> x >> y;
		
		cout << solve(x, y, d) << '\n';
	}
}