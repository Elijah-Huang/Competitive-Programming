#include<bits/stdc++.h>
#include <unordered_map>
#include<chrono>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	const int maxn = 2e5;
	int t, n, k, a[maxn];
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] = a[i] % k;
		}
		long long ans = 0;
		gp_hash_table<int, int, custom_hash> m;
		for (int i = 0; i < n; i++) {
			if (m.find(a[i]) != m.end()) {
				m[a[i]]++;
			}
			else {
				m[a[i]] = 1;
			}
		}
		m.erase(0);
		int earliest;
		int most = 0;
		for (auto i : m) {
			if (i.second > most) {
				most = i.second;
				earliest = i.first;
			}
			else if (i.second == most) {
				earliest = min(earliest, i.first);
			}
		}
		if (!m.empty()) {
			cout << (long long)(k) * (most - 1) + k - earliest + 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

}