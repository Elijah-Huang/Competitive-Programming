#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int mx = 0;
	int n; cin >> n;
	long long total_moves = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		total_moves += max(0, mx - a);
		mx = max(mx, a);
	}

	cout << total_moves << '\n';
}