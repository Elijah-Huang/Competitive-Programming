#include<bits/stdc++.h>
using namespace std;

int k;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> k;

	for (int m = 5; m * m <= k; m++) {
		if (k % m == 0) {
			int n = k / m; // n > m

			string vowels = "aeiou";
			string row, vowely;
			for (int i = 0; i < m; i++) {
				row.push_back(vowels[i % 5]);
			}
	
			for (int i = 0; i < n; i++) {
				vowely += row;
				rotate(row.begin(), row.begin() + 1, row.end());
			}
			
			cout << vowely;
			return 0;
		}
	}

	cout << -1;
}