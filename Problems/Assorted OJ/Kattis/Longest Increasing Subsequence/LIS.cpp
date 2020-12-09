#include<bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while (cin >> n) {
		vector<int> seq(n);
		for (int i = 0; i < n; i++) {
			cin >> seq[i];
		}

		vector<int> len(n, 1);
		vector<int> prev(n, -1);
		set<pair<int, int>> active;
		for (int i = 0; i < n; i++) {
			auto loc = active.lower_bound({ seq[i], -1 });
			if (loc == active.begin()) {
				if (active.size() and len[loc->second] == 1) {
					active.erase(loc);
				}
				active.insert({ seq[i],i });
			}
			else if (loc != active.end()) {
				auto before = loc;
				before--;
				if (len[loc->second] == 1 + len[before->second]) {
					active.erase(loc);
				}
				len[i] = len[before->second] + 1;
				prev[i] = before->second;
				active.insert({ seq[i],i });
			}
			else {
				auto before = loc;
				before--;
				len[i] = len[before->second] + 1;
				prev[i] = before->second;
				active.insert({ seq[i],i });
			}
		}

		int curr = (--active.end())->second;
		cout << len[curr] << '\n';
		vector<int> LIS;
		while (curr != -1) {
			LIS.push_back(curr);
			curr = prev[curr];
		}
		reverse(LIS.begin(), LIS.end());
		for (int i = 0; i < LIS.size(); i++) {
			cout << LIS[i] << (i != LIS.size() - 1 ? ' ' : '\n');
		}
	}
}