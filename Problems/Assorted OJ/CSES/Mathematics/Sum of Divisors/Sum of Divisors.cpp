#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long ap_sum(long long left, long long right) {
	if ((right - left + 1) % 2 == 0) {
		return (((right - left + 1)/2) % mod) * ((left + right) % mod) % mod;
	}
	else {
		return ((right - left + 1) % mod) * (((left + right)/2) % mod) % mod;
	}
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n; cin >> n;
	long long ans = 0;

	//say floor(n/i) = a
	// iterate through a's
	for (long long a = 1; a * a < n; a++) {
		long long right = n / a;
		long long left = n / (a + 1) + 1;
		ans = (ans + (a % mod) * ap_sum(left, right)) % mod;
	}

	//iterate through i's to find a
	for (long long i = 1; i * i < n; i++) {
		long long a = n / i;
		if (a < sqrt(n)) {
			break;
		}
		long long right = n / a;
		long long left = n / (a + 1) + 1;
		ans = (ans + (a % mod) * ap_sum(left, right)) % mod;
	}

	//not counted if perfect square
	if (sqrt(n) == int(sqrt(n))) {
		ans = (ans + n) % mod;
	}

	cout << ans;
}