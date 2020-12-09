#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<bool> seen(n);
	for (int i = 0; i < n-1; i++) {
		int a; cin >> a;
		seen[--a] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (!seen[i]) {
			cout << i + 1;
		}
	}
}