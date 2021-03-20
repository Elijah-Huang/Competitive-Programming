// O(sum(string length))
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int t, n, k;
string strings[maxn];
int ans;

// recursive function that greedily creates groups starting from max depth(matched prefix)
// returns the # of unmatched to be matched later (as soon as possible)
// d = length of prefix that is shared by all strings in strs_at_d
int solve(int d, vector<int>& strs_at_d) {
	int leftover = 0;
	map<char, vector<int>> strs_below_d;

	for (int i = 0; i < strs_at_d.size(); i++) {
		if (strings[strs_at_d[i]].length() == d) {
			// can not share a prefix of length d+1
			leftover += 1;
		}
		else {
			strs_below_d[strings[strs_at_d[i]][d]].push_back(strs_at_d[i]);
		}
	}

	for (auto b :strs_below_d) {
		// recursively solve these new sets of strings that share prefixes of length d+1
		leftover += solve(d + 1, b.second);
	}

	// group up and return the leftover ungrouped
	ans += d * (leftover / k);
	return leftover % k;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		ans = 0;

		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> strings[i];
		}
		
		vector<int> all_strs(n);
		iota(all_strs.begin(), all_strs.end(), 0);

		solve(0, all_strs);


		cout << "Case #" << i << ": " << ans << '\n';
	}
}