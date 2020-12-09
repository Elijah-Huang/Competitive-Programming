#include<bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> seq(n);
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	set<pair<int, int>> active;
	for (int i = 0; i < n; i++) {
		auto loc = active.lower_bound({ seq[i], -1 });
		if (loc == active.begin()) {
			if (active.size() and loc->second == 1) {
				active.erase(loc);
			}
			active.insert({ seq[i], 1 });
		}
		else if (loc != active.end()) {
			auto before = loc;
			before--;
			if (loc->second == 1 + before->second) {
				active.erase(loc);
			}
			active.insert({ seq[i], before->second + 1 });
		}
		else {
			auto before = loc;
			before--;
			active.insert({ seq[i], before->second + 1 });
		}
	}

	cout << (--active.end())->second << '\n';
}