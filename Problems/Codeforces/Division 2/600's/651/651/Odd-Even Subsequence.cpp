#include <bits/stdc++.h>
using namespace std;
bool works(vector<int> const  &v, int const &m, int const &k, int const &n, bool const &type) {
	int total = 0;
	bool place_min = type;
	for (int i = 0; i < n; i++) {
		if (total >= k) {
			break;
		}
		if (place_min) {
			for (; i < n; i++) {
				if (v[i] <= m) {
					total++;
					place_min = false;
					break;
				}
			}
		}
		else {
			total++;
			place_min = true;
		}
	}
	return total >= k;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> v;
	int curr;
	for (int i = 0; i < n; i++) {
		cin >> curr;
		v.push_back(curr);
	}
	int largest;
	int m;
	int l = 1;
	int r = pow(10, 9);
	while (l != r) {
		m = (l + r) / 2;
		if (works(v, m, k, n, true)) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	largest = l;
	l = 1;
	r = pow(10, 9);
	while (l != r) {
		m = (l + r) / 2;
		if (works(v, m, k, n, false)) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	largest = min(largest, l);
	cout << largest;
}