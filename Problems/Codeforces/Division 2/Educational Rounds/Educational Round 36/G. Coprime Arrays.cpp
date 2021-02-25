#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 1, mod = 1e9 + 7;
int n, k;
long long tot_ans = 0, curr_ans = 0;
int spf[maxn];
bool cardinality_mod2[maxn];
int val_to_pow_n[maxn];
vector<int> updates[maxn];

long long mod_exp(long long b, int e = n) {
	long long res = 1;
	while (e) {
		if (e & 1) {
			res = (res * b) % mod;
		}
		e >>= 1;
		b = (b * b) % mod;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	for (long long i = 2; i <= k; i++) {
		if (spf[i] == 0) {
			spf[i] = i;

			for (long long j = i * i; j <= k; j += i) {
				if (spf[j] == 0) {
					spf[j] = i;
				}
			}
		}
	}

	for (int i = 1; i <= k; i++) {
		int curr = i;
		vector<int> fact;
		while (curr != 1) {
			if (fact.empty() or fact.back() != spf[curr]) {
				fact.push_back(spf[curr]);
				curr /= spf[curr];
			}
			else {
				break;
			}
		}

		if (curr == 1) {
			// even -> 0 % 2 | odd -> 1 % 2
			// notice that fact is empty for i == 1 so it is 0 % 2, flip of what it should be
			cardinality_mod2[i] = fact.size() % 2;
			for (int j = i; j <= k; j += i) {
				updates[j].push_back(i);
			}
		}
	}

	for (int i = 1; i <= k; i++) {
		val_to_pow_n[i] = mod_exp(i);
	}

	for (int i = 1; i <= k; i++) {
		for (auto j : updates[i]) {
			curr_ans -= (1 - 2 * cardinality_mod2[j]) * val_to_pow_n[i / j - 1];
			curr_ans += (1 - 2 * cardinality_mod2[j]) * val_to_pow_n[i / j];
		}
		curr_ans = (mod + curr_ans % mod) % mod;
		tot_ans = (tot_ans + (i^curr_ans)) % mod;
	}
	
	cout << tot_ans << '\n';
}