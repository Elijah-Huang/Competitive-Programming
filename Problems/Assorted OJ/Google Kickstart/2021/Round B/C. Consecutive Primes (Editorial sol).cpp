#include<bits/stdc++.h>
using namespace std;

int t;

bool isprime(int a) {
	for (int i = 2; i*i <= a; i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	
	return 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cse = 1; cse <= t; cse++) {
		long long z; cin >> z;
		long long ans;

		int root = sqrt(z);

		vector<long long> prime_below, prime_above;
		for (int i = root; i >= 2 and prime_below.size() != 2; i--) {
			if (isprime(i)) {
				prime_below.push_back(i);
			}
		}

		for (int i = root + 1; prime_above.empty(); i++) {
			if (isprime(i)) {
				prime_above.push_back(i);
			}
		}
		
		if (prime_below[0] * prime_above[0] <= z) {
			ans = prime_below[0] * prime_above[0];
		}
		else {
			ans = prime_below[0] * prime_below[1];
		}

		cout << "Case #" << cse << ": " << ans << '\n';
	}
}