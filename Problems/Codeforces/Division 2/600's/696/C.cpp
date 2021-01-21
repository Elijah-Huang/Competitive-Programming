#include<bits/stdc++.h>
using namespace std;

int t, n;
int a[2000];
int x;
map<int, int> counts, counts2;
vector<pair<int,int>> ops;

void remove(int val) {
	counts2[val]--;
	if (counts2[val] == 0) {
		counts2.erase(val);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;

	while (t--) {
		ops.clear();
		counts.clear();

		cin >> n;

		for (int i = 0; i < 2 * n; i++) {
			cin >> a[i];
			counts[a[i]]++;
		}

		sort(a, a + 2 * n);

		for (int i = 0; i < 2 * n - 1; i++) {
			counts2 = counts;
			ops = { { a[i], a[2 * n - 1] } };
			remove(a[i]);
			remove(a[2 * n - 1]);
			x = a[2 * n - 1];

			for (int op = 2; op <= n; op++) {
				int curr_mx = counts2.rbegin()->first;
				if (x == 2 * curr_mx) {
					if (counts2[curr_mx] >= 2) {
						remove(curr_mx);
						remove(curr_mx);
						ops.push_back({ curr_mx, curr_mx });
						x = curr_mx;
					}
					else {
						break;
					}
				}
				else if (counts2.count(x - curr_mx)) {
					remove(curr_mx);
					remove(x - curr_mx);
					ops.push_back({ x - curr_mx, curr_mx });
					x = curr_mx;
				}
				else {
					break;
				}
			}

			if (ops.size() == n) {
				cout << "YES\n";
				cout << ops[0].first + ops[0].second << '\n';
				for (auto& op : ops) {
					cout << op.first << ' ' << op.second << '\n';
				}

				break;
			}
		}

		if (ops.size() != n) {
			cout << "NO\n";
		}
	}
}