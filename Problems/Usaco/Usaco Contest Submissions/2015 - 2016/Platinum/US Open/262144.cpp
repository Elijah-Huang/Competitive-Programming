#include<bits/stdc++.h>
using namespace std;

vector<int> a;

int side_added(int l, int r, int largest) {
	int amt = 0;
	int curr = 0;
	int largest_count = 0;
	for (int i = l; i < r; i++) {
		if (curr == a[i]) {
			amt++;
		}
		else if (a[i] == largest) {
			largest_count += amt / (1 << (a[i] - curr));;
			break;
		}
		else {
			amt = 1 + amt / (1 << (a[i] - curr));
			curr = a[i];
		}
	}
	return largest_count;
}
int solve(int l, int r) {
	int amt = 1;
	for (int i = l; i < r - 1; i++) {
		if (a[i] == a[i + 1]) {
			amt++;
		}
		else {
			if (i != r - 1 and i - amt >= l and
				a[i - amt] > a[i] and a[i] < a[i + 1] and amt % 2 == 1) {
					fill(a.begin() + i - amt + 1, a.begin() + i + 1, a[i] + 1);
					return max(solve(l, i - amt + amt / 2 + 1), solve(i - amt / 2 + 1, r));
			}
			else {
				amt = 1;
			}
		}
	}
	int largest = *max_element(a.begin(), a.end());
	int largest_count = 0;
	for (int i = l; i < r; i++) {
		largest_count += (a[i] == largest);
	}
	largest_count += side_added(l, r, largest);
	reverse(a.begin() + l, a.begin() + r);
	largest_count += side_added(l, r, largest);
	reverse(a.begin() + l, a.begin() + r);
	return largest + ilogb(largest_count);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("262144.in", "r", stdin); freopen("262144.out", "w", stdout);
	int n; cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pair<int, int>> to_change(1);
	while (!to_change.empty()) {
		int amt = 1;
		to_change.resize(0);
		for (int i = 0; i < a.size() - 1; i++) {
			if (a[i] == a[i + 1]) {
				amt++;
			}
			else {
				if (i != a.size() - 1 and i + 1 > amt and
					a[i - amt] > a[i] and a[i] < a[i + 1] and amt % 2 == 0) {
					to_change.push_back({i - amt + 1, i});
				}
				else {
					amt = 1;
				}
			}
		}
		if (!to_change.empty()) {
			int i = 0;
			int j = 0;
			vector<int> new_a;
			while (i < a.size()) {
				if (j < to_change.size() and i == to_change[j].first) {
					new_a.insert(new_a.end(), (to_change[j].second - to_change[j].first + 1) / 2, a[i] + 1);
					i = to_change[j].second + 1;
					j++;
				}
				else {
					new_a.push_back(a[i]);
					i++;
				}
			}
			a = new_a;
		}
	}

	cout << solve(0,a.size());
}