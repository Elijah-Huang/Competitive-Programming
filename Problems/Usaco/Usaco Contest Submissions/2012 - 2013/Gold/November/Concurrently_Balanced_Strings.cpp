#include<bits/stdc++.h>
using namespace std;

struct psum {
	int val, idx;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cbs.in", "r", stdin); freopen("cbs.out", "w", stdout);
	int ans = 0;
	int k, n; cin >> k >> n;
	vector<string> strings(k);
	vector<int> curr_psum(k);
	vector<vector<int>> psums(n);
	vector<stack<psum>> prev_psums(k);
	vector<bool> removed_psum(n);
	map<vector<int>, int> usable_psums;
	for (int i = 0; i < k; i++) {
		cin >> strings[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			curr_psum[j] += strings[j][i] == '(' ? 1 : -1;
		}

		ans += usable_psums[curr_psum];

		for (int j = 0; j < k; j++) {
			while (!prev_psums[j].empty() and prev_psums[j].top().val > curr_psum[j]) {
				if (!removed_psum[prev_psums[j].top().idx]) {
					usable_psums[psums[prev_psums[j].top().idx]]--;
					removed_psum[prev_psums[j].top().idx] = 1;
				}
				prev_psums[j].pop();
			}
			prev_psums[j].push({ curr_psum[j],i });
		}
		usable_psums[curr_psum]++;
		psums[i] = curr_psum;
	}

	cout << ans;
}