#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, q;
string desired;
// 0 = prefix, 1 = suffix | location
int ans[2][maxn + 2];
int last_loc[26];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;

	cin >> desired;

	memset(last_loc, 0, sizeof(last_loc));
	for (int i = 1; i <= n; i++) {
		bool smaller_intersect = last_loc[desired[i-1] - 'A'] == 0;
		for (int j = desired[i - 1]-'A' - 1; j >= 0; j--) {
			if (last_loc[j] >= last_loc[desired[i - 1] - 'A' ]) {
				smaller_intersect = 1;
			}
		}

		ans[0][i] = ans[0][i - 1] + smaller_intersect;

		last_loc[desired[i - 1] - 'A'] = i;
	}
	memset(last_loc, 0x3f, sizeof(last_loc));
	for (int i = n; i >= 1; i--) {
		bool smaller_intersect = last_loc[desired[i-1] - 'A'] > 1e6;
		for (int j = desired[i - 1] - 'A' - 1; j >= 0; j--) {
			if (last_loc[j] <= last_loc[desired[i - 1] - 'A']) {
				smaller_intersect = 1;
			}
		}

		ans[1][i] = ans[1][i + 1] + smaller_intersect;

		last_loc[desired[i - 1] - 'A'] = i;
	}

	while (q--) {
		int a, b; cin >> a >> b;
		cout << ans[0][a - 1] + ans[1][b + 1] << '\n';
	}
}