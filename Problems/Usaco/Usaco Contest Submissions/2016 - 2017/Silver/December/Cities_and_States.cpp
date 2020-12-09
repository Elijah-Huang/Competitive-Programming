#include<bits/stdc++.h>
using namespace std;
string revers(string a) {
	return a.substr(2, 2) + a.substr(0, 2);
}
int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("citystate.in", "r", stdin); freopen("citystate.out", "w", stdout);
	int n;
	cin >> n;
	long long ans = 0;
	unordered_map<string, long long> amounts;
	for (int i = 0; i < n; i++) {
		char a1[11];
		char a2[3];
		scanf("%10s %2s", a1, a2);
		string a = a1;
		string b = a2;
		amounts[a.substr(0, 2) + b]++;
	}
	for (auto s : amounts) {
		string r = revers(s.first);
		if (r != s.first and amounts.count(r)) {
			ans += amounts[r] * (s.second);
		}
	}
	ans /= 2;
	printf("%lld", ans);
}