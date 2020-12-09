#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> stacks(m + 1);
	vector<vector<int>> operations;
	for (int i = 1; i <= m; i++) {
		int amt; cin >> amt;
		stacks[i].resize(amt);
		for (int j = 0; j < amt; j++) {
			cin >> stacks[i][j];
		}
		reverse(stacks[i].begin(), stacks[i].end());
	}

	for (int i = 2; i <= m; i++) {
		while (!stacks[i].empty()) {
			operations.push_back({ i,1 });
			stacks[1].push_back(stacks[i].back());
			stacks[i].pop_back();
		}
	}

	while (!stacks[1].empty()) {
		int curr = stacks[1].back(); stacks[1].pop_back();
		if (curr == 1 or curr == 2) {
			stacks[2].push_back(curr);
			operations.push_back({ 1,2 });
		}
		else {
			stacks[curr].push_back(curr);
			operations.push_back({ 1,curr });
		}
	}

	while (!stacks[2].empty()) {
		int curr = stacks[2].back(); stacks[2].pop_back();
		if (curr == 1) {
			stacks[1].push_back(curr);
			operations.push_back({ 2,1 });
		}
		else {
			stacks[3].push_back(curr);
			operations.push_back({ 2,3 });
		}
	}
	
	while (!stacks[3].empty() and stacks[3].back() == 2) {
		stacks[3].pop_back();
		stacks[2].push_back(2);
		operations.push_back({ 3,2 });
	}

	cout << operations.size() << '\n';
	for (auto& op : operations) {
		for (auto& loc : op) {
			cout << loc << ' ';
		}
		cout << '\n';
	}
}