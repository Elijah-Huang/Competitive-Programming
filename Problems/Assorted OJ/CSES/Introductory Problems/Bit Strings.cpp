#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int powm(long long base, long long exp) {
	base %= mod;
	long long res = 1;
	while(exp){
		if (exp & 1) {
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	cout << powm(2, n);
}