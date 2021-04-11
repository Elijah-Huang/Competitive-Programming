#include<bits/stdc++.h>
using namespace std;

int t, m;
long long p[100], n[100], n2[100], tot_sum, bst = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cse = 1; cse <= t; cse++) {
		tot_sum = 0, bst = 0;
		cin >> m;

		for (int i = 0; i < m; i++) {
			cin >> p[i] >> n[i];
			tot_sum += p[i] * n[i];
		}

		for (int prod_sum = 2; prod_sum <= min(tot_sum, 30000ll); prod_sum++) {
			memcpy(n2, n, sizeof(n));
			long long sm = tot_sum - prod_sum;
			long long curr_sum = 0;

			for (int i = 0; i < m; i++) {
				while (sm % p[i] == 0 and n2[i] > 0) {
					sm /= p[i];
					n2[i]--;
					curr_sum += p[i];
				}
			}

			if (sm == 1 and curr_sum == prod_sum) {
				bst = tot_sum - prod_sum;
				break;
			}
		}

		cout << "Case #" << cse << ": " << bst << '\n';
	}
}