#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> filling_freq;
		priority_queue<int> freq_filling;
		for (int i = 0; i < n; i++) {
			int f; cin >> f;
			filling_freq[f]++;
		}
		for (auto i : filling_freq) {
			freq_filling.push(i.second);
		}

		int L = 0; int R = n - 2;
		while (L != R) {
			int m = (L + R + 1) / 2;
			vector<int> can_place(n);
			priority_queue<int> curr_freq = freq_filling;
			bool fail = false;
			for (int i = 0; i < n; i++) {
				if (curr_freq.empty()) {
					fail = true;
					break;
				}
				int curr = curr_freq.top(); 
				curr_freq.pop();
				if (i + m > n - 2 and curr > 1) {
					fail = true;
					break;
				}
				else if (i + m <= n-2 and curr > 1) {
					can_place[i + m] = curr - 1;
				}
				if (can_place[i]) {
					curr_freq.push(can_place[i]);
				}
			}
			if (fail) {
				R = m - 1;
			}
			else {
				L = m;
			}
		}

		cout << L << '\n';

	}
}