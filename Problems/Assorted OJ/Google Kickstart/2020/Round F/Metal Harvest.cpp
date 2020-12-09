#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, c = 0;
	cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<pair<int, int>> intervals(n);
		for (int i = 0; i < n; i++) {
			cin >> intervals[i].first >> intervals[i].second;
		}
		sort(intervals.begin(), intervals.end());
		int deployed = 0;
		int curr = -1;
		int i = 0;
		while (i < n) {
			while (i < n and intervals[i].second <= curr) {
				i++;
			}
			if (i == n) {
				break;
			}
			if (curr <= intervals[i].first) {
				int nw = (intervals[i].second - intervals[i].first + k - 1) / k;
				deployed += nw;
				curr = intervals[i].first + nw * k;
			}
			else {
				int nw = (intervals[i].second - curr + k - 1) / k;
				deployed += nw;
				curr += nw * k;
			}
		}
		c++;
		cout << "Case #" << c << ": " << deployed << '\n';
	}
}
	