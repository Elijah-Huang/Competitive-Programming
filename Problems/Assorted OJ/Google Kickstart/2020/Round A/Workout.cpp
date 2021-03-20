// O((n+k)*log(max(m)))
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int t, n, k;
int difficulty[maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> difficulty[i];
		}

		int l = 0, r = 1e9;
		while (l != r) {
			int m = (l + r) / 2;
			bool fail = false;
			int left = k;

			for (int i = 0; i < n - 1; i++) {
				int diff = difficulty[i + 1] - difficulty[i];
				int placed_inbetween = 0;

				while (left and (diff + placed_inbetween) / (placed_inbetween + 1) > m) {
					left--;
					placed_inbetween++;
				}

				if ((diff + placed_inbetween) / (placed_inbetween + 1) > m) {
					fail = true;
					break;
				}
			}

			if (fail) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}


		cout << "Case #" << i << ": " << l << '\n';
	}
}