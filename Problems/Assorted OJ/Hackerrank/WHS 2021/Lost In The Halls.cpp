#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i]; b[i]--;
	}

	bool all_same = 1;
	int diff = (b[0] - a[0] + m) % m;
	
	for (int i = 1; i < n; i++) {
		if ((b[i] - a[i] + m) % m != diff) {
			all_same = 0;
			break;
		}
	}

	if (all_same) {
		cout << m + diff;
	}
	else {
		cout << -1;
	}
}