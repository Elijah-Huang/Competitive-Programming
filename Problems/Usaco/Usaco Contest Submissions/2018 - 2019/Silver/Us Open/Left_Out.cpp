#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("leftout.in", "r", stdin); freopen("leftout.out", "w", stdout);
	int n;
	cin >> n;
	vector<string> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i];
	}
	vector<string> distinct_rows;
	vector<int> earliest;
	for (int i = 0; i < n; i++) {
		bool diff = true;
		for (int j = 0; j < distinct_rows.size(); j++) {
			if (cows[i] == distinct_rows[j]) {
				diff = false;
				break;
			}
		}
		if (diff) {
			distinct_rows.push_back(cows[i]);
			earliest.push_back(i);
			if (distinct_rows.size() > 3) {
				break;
			}
		}
	}
	if (distinct_rows.size() == 1 or distinct_rows.size() > 3) {
		cout << -1;
	}
	else if (distinct_rows.size() == 2) {
		int differences = 0;
		int j;
		for (int i = 0; i < n; i++) {
			if (distinct_rows[0][i] != distinct_rows[1][i]) {
				differences++;
				j = i;
			}
		}
		if (differences == 1) {
			cout << 1 << ' ' << j + 1;
		}
		else {
			cout << -1;
		}
	}
	else {
		vector<int> differences(3);
		for (int i = 0; i < n; i++) {
			differences[0] += distinct_rows[1][i] != distinct_rows[2][i];
			differences[1] += distinct_rows[0][i] != distinct_rows[2][i];
			differences[2] += distinct_rows[0][i] != distinct_rows[1][i];
		}
		if (find(differences.begin(), differences.end(), 1) == differences.end()
			or find(differences.begin(), differences.end(), n) == differences.end()) {
			cout << -1;
		}
		else {
			int loc = find(differences.begin(), differences.end(), n) - differences.begin();
			for (int i = 0; i < 3; i++) {
				if (differences[i] == 1) {
					int j;
					for (int k = 0; k < n; k++) {
						if (distinct_rows[(i + 1) % 3][k] != distinct_rows[(i + 2) % 3][k]) {
							j = k;
							break;
						}
					}
					cout << earliest[loc] + 1 << ' ' << j + 1;
					break;
				}
			}
		}
	}
}