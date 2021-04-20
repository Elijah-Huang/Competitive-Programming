#include<bits/stdc++.h>
using namespace std;

int t;

vector<int> primes;
const int mx = 1e9 + 10;
bitset<mx> composite;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// precompute primes

	for (long long i = 2; i < mx; i++) {
		if (!composite[i]) {
			primes.push_back(i);

			for (long long j = i * i; j < mx; j += i) {
				composite[j] = 1;
			}
		}
	}

	cin >> t;

	for (int cse = 1; cse <= t; cse++) {
		long long z; cin >> z;
		
		int l = 0, r = primes.size() - 2;
		while (l != r) {
			int m = (l + r + 1) / 2;
			
			if ((long long)(primes[m]) * primes[m + 1] <= z) {
				l = m;
			}
			else {
				r = m - 1;
			}
		}

		cout << "Case #" << cse << ": " << (long long)(primes[l]) * primes[l + 1] << '\n';
	}
}