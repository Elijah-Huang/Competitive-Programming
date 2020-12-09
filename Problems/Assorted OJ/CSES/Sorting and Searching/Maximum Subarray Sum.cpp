#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long mx = -1e15;
	long long curr = 0;
	for (int i = 0; i < n; i++) {
		curr = max(curr + a[i], a[i]);
		mx = max(mx, curr);
	}

	cout << mx;
}