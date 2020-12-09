#include<bits/stdc++.h>
using namespace std;
int solve(int& len, long long n) {
	if (n <= len) {
		return n;
	}
	else {
		long long mult = 1;
		while (n >= len * 2 * mult + 1) {
			mult <<= 1;
		}
		if (n == len * mult + 1) {
			return solve(len, n - 1);
		}
		else {
			return solve(len, n - (len * mult + 1));
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("cowcode.in", "r", stdin); freopen("cowcode.out", "w", stdout);
	long long n;
	string s;
	cin >> s >> n;
	int len = s.length();
	cout << s[solve(len, n)-1];
}