#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int bit[maxn];

void add(int idx, int val) {
	for (idx++; idx < maxn; idx += idx & -idx) {
		bit[idx] += val;
	}
}

int sum(int idx) {
	int ans = 0;
	for (idx++; idx > 0; idx -= idx & -idx) {
		ans += bit[idx];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("lineup.in", "r", stdin); freopen("lineup.out", "w", stdout);
	int n, k, mx = 1; cin >> n >> k;
	vector<int> cows(n);
	map<int, vector<int>> pos;
	map<int, int> idx;
	for (int i = 0; i < n; i++) {
		cin >> cows[i];
		pos[cows[i]].push_back(i);
		if (pos[cows[i]].size() == 1) {
			add(i, 1);
			idx[cows[i]] = 0;
		}
	}

	for (int start = 0; start < n; start++) {
		add(start, -1);

		int l = start, r = n - 1;
		while (l != r) {
			int m = (l + r + 1) / 2;
			if (sum(m) <= k) {
				l = m;
			}
			else {
				r = m - 1;
			}
		}
		mx = max(mx, int(upper_bound(pos[cows[start]].begin(),pos[cows[start]].end(),l) - (pos[cows[start]].begin() + idx[cows[start]])));
		
		idx[cows[start]]++;
		if (pos[cows[start]].size() != idx[cows[start]]) {
			add(pos[cows[start]][idx[cows[start]]], 1);
		}
	}

	cout << mx << '\n';
}