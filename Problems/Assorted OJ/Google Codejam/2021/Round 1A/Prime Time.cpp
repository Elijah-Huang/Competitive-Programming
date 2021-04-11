#include<bits/stdc++.h>
using namespace std;

int t, m;
long long p[100], n[100];
long long tot_sum;

long long bst = 0;

void solve(long long curr_sum = 0, long long curr_prod = 1, int i = 0) {
	if (tot_sum - curr_sum == curr_prod) {
		bst = max(bst, curr_prod);
		return;
	}

	if (i == m) {
		return;
	}

	for (int j = 0; j <= n[i]; j++) {
		solve(curr_sum, curr_prod, i + 1);

		if (curr_prod > (tot_sum - (curr_sum + p[i])) / p[i]) {
			break;
		}
		else {
			curr_prod *= p[i];
			curr_sum += p[i];
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cse = 1; cse <= t; cse++) {
		bst = 0; tot_sum = 0;

		cin >> m;

		for (int i = 0; i < m; i++) {
			cin >> p[i] >> n[i];
			tot_sum += p[i] * n[i];
		}

		solve();

		cout << "Case #" << cse << ": " << bst << '\n';
	}
}