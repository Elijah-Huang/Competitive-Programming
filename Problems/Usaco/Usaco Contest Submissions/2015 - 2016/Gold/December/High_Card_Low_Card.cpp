#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cardgame.in", "r", stdin); freopen("cardgame.out", "w", stdout);
	int n; cin >> n;
	vector<int> first_half(n / 2), last_half(n / 2);
	vector<bool> used(2*n + 1);
	vector<int> bessie_f, bessie_l;
	for (int i = 0; i < n / 2; i++) {
		cin >> first_half[i];
		used[first_half[i]] = 1;
	}
	for (int i = 0; i < n/2; i++) {
		cin >> last_half[i];
		used[last_half[i]] = 1;
	}
	for (int i = 1; i <= 2*n; i++) {
		if (!used[i]) {
			if (bessie_l.size() < n / 2) {
				bessie_l.push_back(i);
			}
			else {
				bessie_f.push_back(i);
			}
		}
	}

	reverse(bessie_l.begin(), bessie_l.end());
	sort(first_half.begin(), first_half.end());
	sort(last_half.begin(), last_half.end(), greater<int>());

	int wins = 0;
	int first_idx = 0;
	for (int i = 0; i < n / 2; i++) {
		while (first_idx < n / 2 and bessie_f[first_idx] < first_half[i]){
			first_idx++;
		}
		if (first_idx != n / 2) {
			wins++;
			first_idx++;
		}
	}

	int last_idx = 0;
	for (int i = 0; i < n / 2; i++) {
		while (last_idx < n / 2 and bessie_l[last_idx] > last_half[i]) {
			last_idx++;
		}
		if (last_idx != n / 2) {
			wins++;
			last_idx++;
		}
	}

	cout << wins;
}