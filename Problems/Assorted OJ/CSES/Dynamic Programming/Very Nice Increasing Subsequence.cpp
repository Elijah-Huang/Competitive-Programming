#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> seq(n);
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	vector<int> active;
	for (int i = 0; i < n; i++) {
		auto loc = lower_bound(active.begin(), active.end(), seq[i]);
		if (loc == active.end()) {
			active.push_back(seq[i]);
		}
		else {
			*loc = seq[i];
		}
	}

	cout << active.size();
}