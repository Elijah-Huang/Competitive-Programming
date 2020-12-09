#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int n, q;
vector<int> a, b;
int smaller_than(int const &m) {
	int lower = 0;
	for (auto num : a) {
		if (num <= m) {
			lower++;
		}
		else {
			break;
		}
	}
	for (auto k : b) {
		if (k > 0) {
			if (k <= m) {
				lower++;
			}
		}
		else if (k < 0 and abs(k) <= lower) {
			lower--;
		}
	}
	return lower;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	b.resize(q);
	for (int i = 0; i < q; i++) {
		cin >> b[i];
	}
	if (smaller_than(pow(10, 6)) == 0) {
		cout << 0;
		return 0;
	}
	int lb = 1, rb = pow(10, 6), m;
	while (lb != rb) {
		m = (lb + rb) / 2;
		if (smaller_than(m) > 0) {
			rb = m;
		}
		else {
			lb = m + 1;
		}
	}
	cout << lb;

}