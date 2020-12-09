#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	const int MAXN = 1e6;
	int n, m, p, a[MAXN], b[MAXN];
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int smallesta = 0;
	int smallestb = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % p != 0) {
			smallesta = i;
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		if (b[i] % p != 0) {
			smallestb = i;
			break;
		}
	}
	cout << smallesta + smallestb;

}