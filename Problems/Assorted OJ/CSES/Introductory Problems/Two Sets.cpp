#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<bool> used(n + 1);
	vector<vector<int>> sets(2);
	if (n % 4 == 0) {
		for (int i = 0; i < n / 4; i++) {
			sets[0].push_back(1 + i);
			sets[0].push_back(n - i);
			used[1 + i] = 1;
			used[n - i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (!used[i]) {
				sets[1].push_back(i);
			}
		}
	}
	else if ((n + 1) % 4 == 0) {
		for (int i = 0; i < (n+1) / 4; i++) {
			sets[0].push_back(1 + i);
			sets[0].push_back(n-1 - i);
			used[1 + i] = 1;
			used[n-1 - i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (!used[i]) {
				sets[1].push_back(i);
			}
		}
	}
	else {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	for (auto& set : sets) {
		cout << set.size() << '\n';
		for (auto i : set) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}