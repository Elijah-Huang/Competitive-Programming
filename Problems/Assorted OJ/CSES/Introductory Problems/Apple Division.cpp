#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> p(n);
	int total_sets = 1 << n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	long long total = accumulate(p.begin(), p.end(), 0ll);
	long long least_diff = 1ll << 40;
	for (int i = 0; i < total_sets; i++) {
		int idx = 1;
		long long curr_total = 0;
		for (int j = 0; j < n; j++) {
			curr_total += ((idx & i)>0) * (p[j]);
			idx <<= 1;
		}
		least_diff = min(least_diff, abs(total - 2 * curr_total));
	}

	cout << least_diff;
}