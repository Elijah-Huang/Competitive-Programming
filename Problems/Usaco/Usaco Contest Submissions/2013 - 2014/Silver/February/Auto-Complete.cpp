#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("auto.in", "r", stdin); freopen("auto.out", "w", stdout);
	int w, n; cin >> w >> n;
	vector<pair<string, int>> dictionary(w);
	for (int i = 0; i < w; i++) {
		cin >> dictionary[i].first;
		dictionary[i].second = i + 1;
	}
	sort(dictionary.begin(), dictionary.end());

	for (int i = 0; i < n; i++) {
		int k; string pref; cin >> k >> pref;
		if (pref > dictionary[w - 1].first) {
			cout << -1 << '\n';
			continue;
		}
		int L = 0, R = w - 1;
		while (L != R) {
			int m = (L + R) / 2;
			if (dictionary[m].first >= pref) {
				R = m;
			}
			else {
				L = m + 1;
			}
		}
		if (L + k - 1 > w - 1 or pref != dictionary[L + k - 1].first.substr(0, pref.length())) {
			cout << -1 << '\n';
		}
		else {
			cout << dictionary[L + k - 1].second << '\n';
		}
	}
}