/*
ID: elijahj1
TASK: milk4
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("milk4.in", "r", stdin); freopen("milk4.out", "w", stdout);
	int q, p; cin >> q >> p;
	vector<int> pails(p);
	vector<vector<int>> quarts(q+1);
	for (int i = 0; i < p; i++) {
		cin >> pails[i];
	}
	quarts[0].push_back(0);
	sort(pails.begin(), pails.end());
	for (auto pail : pails) {
		vector<vector<int>> new_quarts(q + 1);
		for (int amount = pail; amount <= q; amount++) {
			if (quarts[amount - pail].size() != 0) {
				new_quarts[amount].assign(quarts[amount - pail].begin(), quarts[amount - pail].end());
				new_quarts[amount].push_back(pail);
			}
			if (new_quarts[amount - pail].size() != 0) {
				if (new_quarts[amount].size() == 0) {
					new_quarts[amount] = new_quarts[amount - pail];
				}
				else {
					if (new_quarts[amount - pail].size() < new_quarts[amount].size()) {
						new_quarts[amount] = new_quarts[amount - pail];
					}
					else if (new_quarts[amount - pail].size() == new_quarts[amount].size()
						and new_quarts[amount - pail] < new_quarts[amount]) {
						new_quarts[amount] = new_quarts[amount - pail];
					}
				}
			}
		}
		for (int amount = pail; amount <= q; amount++) {
			if (new_quarts[amount].size()) {
				if (quarts[amount].size()) {
					if (new_quarts[amount].size() < quarts[amount].size()) {
						quarts[amount] = new_quarts[amount];
					}
					else if (new_quarts[amount].size() == quarts[amount].size()
						and new_quarts[amount] < quarts[amount]) {
						quarts[amount] = new_quarts[amount];
					}
				}
				else {
					quarts[amount] = new_quarts[amount];
				}
			}
		}
	}
	cout << quarts[q].size() - 1;
	for (int i = 1; i < quarts[q].size(); i++) {
		cout << ' ' << quarts[q][i];
	}
	cout << '\n';

}