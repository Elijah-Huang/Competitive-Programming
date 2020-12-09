#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int n, m, a[60000000], curr;
	//vector<int> a(100000);
	cin >> n >> m;
	long long total_sum = 0;
	for (int i = 0; i < m; i++) {
		cin >> curr;
		a[i] = curr;
		total_sum += curr;
	}
	if (total_sum < n) {
		cout << -1 << '\n';
	}
	else {
		bool small = true;
		for (int i = 0; i < m; i++) {
			if (i > n - a[i]) {
				small = false;
				break;
			}
		}
		if (small) {
			long long overlap = total_sum - n;
			cout << 1 << " ";
			int i = 1;
			int max_overlap = a[i - 1] - 1;
			while (overlap) {
				max_overlap = a[i - 1] - 1;
				if (max_overlap < overlap) {
					overlap -= max_overlap;
					cout << i + 1 << " ";
					i++;
				}
				else {
					break;
				}
			}
			int idx;
			if (i < m) {
				idx = i + 1 + max_overlap - overlap;
				cout << idx << " ";
				i++;
			}
			for (i; i < m; i++) {
				idx += a[i - 1];
				cout << idx << " ";
			}
		}
		else {
			cout << -1 << '\n';
		}
	}

}