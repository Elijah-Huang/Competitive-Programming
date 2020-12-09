#include <bits/stdc++.h>
using namespace std;
int main() {
	/*
	double ab = 0.1;
	ab += 0.1;
	ab += 0.1;
	cout << (ab == 0.3) << '\n';
	cout << (fabs(ab == 0.3) < 1e-14) << '\n';
	cout << ab;
	*/
	int n, m, a[50], b[50];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int mx = 0;
	int tot = 0;
	/*
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (b[j] % a[i] == 0) {
				if (mx < b[j] / a[i]) {
					tot = 1;
					mx = b[j] / a[i];
				}
				else {
					tot += mx == b[j] / a[i];
				}
			}
		}
	}
	*/
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			double curr = (double)b[j] / a[i];
			if (curr == int(curr)) {
				if (mx < b[j] / a[i]) {
					tot = 1;
					mx = b[j] / a[i];
				}
				else {
					tot += mx == b[j] / a[i];
				}
			}
		}
	}
	cout << tot; 
}