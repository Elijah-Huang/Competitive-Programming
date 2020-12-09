#include<bits/stdc++.h>
using namespace std;
long long powm(long long base, long long exp, int const& mod) {
	base %= mod;
	long long ans = 1;
	while (exp) {
		if (exp % 2 == 1) {
			ans = (ans * base) % mod;
		}
		exp = exp >> 1;
		base = (base * base) % mod;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, p;
	const int mod = 1e9 + 7;
	unordered_map<int, int> mp;
	cin >> m;
	while (m--) {
		cin >> p;
		if (mp.count(p)) {
			mp[p]++;
		}
		else {
			mp[p] = 1;
		}
	}
	bool square = true;
	for (auto i : mp) {
		if (i.second % 2 == 1) {
			square = false;
			break;
		}
	}
	long long base = 1;
	long long power = 1;
	if (!square) {
		bool two_used = false;
		for (auto i : mp) {
			base = base * powm(i.first, i.second, mod) % mod;
		}
		for (auto i : mp) {
			if (two_used or i.second % 2 == 0) {
				power = power * (i.second + 1) % (mod - 1);
			}
			else {
				power = power * ((i.second + 1) / 2) % (mod - 1);
				two_used = true;
			}
		}
	}
	else {
		for (auto i : mp) {
			base = base * powm(i.first, i.second/2, mod) % mod;
		}
		for (auto i : mp) {
			power = power * (i.second + 1) % (mod - 1);
		}
	}
	cout << powm(base, power, mod);
}