#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, x; cin >> n >> x;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	sort(p.begin(), p.end());

	int total_gondolas = n;
	int right_idx = n - 1;
	for (int i = 0; i < n; i++) {
		while (right_idx > i and p[right_idx] + p[i] > x) {
			right_idx--;
		}
		if (right_idx <= i) {
			break;
		}
		else {
			total_gondolas--;
			right_idx--;
		}
	}

	cout << total_gondolas;
}