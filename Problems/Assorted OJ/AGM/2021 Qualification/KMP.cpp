#include<bits/stdc++.h>
using namespace std;

long long powm(long long base, long long exp, const int& mod) {
	base %= mod;
	long long ans = 1;
	while (exp) {
		if (exp & 1) {
			ans = (ans * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	}
	return ans;
}

const int maxn = 1e5, mod = 1e9 + 7;
int n;
int seq[maxn];
vector<vector<int>> segs;
long long tot_inv, tot_prod;
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}
	
	sort(seq, seq + n);

	int last = -1;
	for (int i = 0; i < n; i++) {
		if (seq[i] > last+1) {
			segs.push_back(vector<int>(1,1));
			
		}
		else if (seq[i] == last+1) {
			segs.back().push_back(1);
		}
		else {
			segs.back().back()++;
		}

		last = seq[i];
	}
	
	for (auto& seg : segs) {
		tot_inv = tot_prod = 1;
		for (auto cnt : seg) {
			tot_prod = (tot_prod * cnt) % mod;
			ans = (ans + (tot_prod * tot_inv) % mod) % mod;
			tot_inv = (tot_inv + powm(tot_prod, mod-2,mod)) % mod;
		}
	}

	cout << ans << '\n';
}