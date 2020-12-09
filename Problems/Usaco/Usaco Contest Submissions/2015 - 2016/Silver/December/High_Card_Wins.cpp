#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("highcard.in", "r", stdin); freopen("highcard.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> elsie, bessie, taken(2 * n);
	for (int i = 0; i < n; i++) {
		int card; cin >> card;
		elsie.push_back(card);
		taken[card - 1] = 1;
	}
	for (int i = 0; i < 2 * n; i++) {
		if (!taken[i]) {
			bessie.push_back(i + 1);
		}
	}
	sort(elsie.begin(), elsie.end());
	sort(bessie.begin(), bessie.end());
	int idx_e = 0;
	int max_points = 0;
	for (int i = 0; i < n; i++) {
		if (bessie[i] > elsie[idx_e]) {
			idx_e++;
			max_points++;
		}
	}
	cout << max_points;
}