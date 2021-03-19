#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e7 + 1;
int spf[maxn];
long long pow2[60];
int t, c, d, x;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (long long i = 2; i < maxn; i++) {
		if (spf[i] == 0) {
			spf[i] = i;

			for (long long j = i * i; j < maxn; j += i) {
				if (spf[j] == 0) {
					spf[j] = i;
				}
			}
		}
	}

	pow2[0] = 1;
	for (int i = 1; i < 60; i++) {
		pow2[i] = 2*pow2[i-1];
	}

	cin >> t;

	while (t--) {
		cin >> c >> d >> x;

		long long pairs = 0;

		for (int i = 1; i*i <= x; i++) {
			if (x % i == 0) {
				vector<int> s = { i,x / i };
				if (i * i == x) {
					s.pop_back();
				}

				for (auto j : s) {
					int e = x / j + d;

					if (e % c == 0) {
						e /= c;

						int distinct_primes = 0;
						int lst = 0;
						while (e > 1) {
							if (lst != spf[e]) {
								distinct_primes++;
							}

							lst = spf[e];
							e /= lst;
						}

						pairs += pow2[distinct_primes];
					}
				}
			}
		}

		cout << pairs << '\n';
	}
}