#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n, l, r; cin >> n >> l >> r;

	if (n == 1) {
		cout << min(l, r);
		return 0;
	}

	vector<long long> al, ar;
	vector<long long> num_at_d(1, 1);
	long long p = 1;
	for (int i = 0; i < 61; i++) {
		if (p > 2e18 / n) { break; };
		p *= n;
		num_at_d.push_back(p + num_at_d.back());
	}
	
	int d = 0;
	for (int i = 0; i < num_at_d.size(); i++) {
		if (num_at_d[i] < l) {
			d = i;
		}
	}
	while (d != 0) {
		al.push_back(l);
		long long l2 = l;
		l2 -= num_at_d[d];
		l = num_at_d[d - 1] + (l2 + n - 1) / n;
		d -= 1;
	}
	al.push_back(l);
	al.push_back(1);

	d = 0;
	for (int i = 0; i < num_at_d.size(); i++) {
		if (num_at_d[i] < r) {
			d = i;
		}
	}
	while (d != 0) {
		ar.push_back(r);
		long long r2 = r;
		r2 -= num_at_d[d];
		r = num_at_d[d - 1] + (r2 + n - 1) / n;
		d -= 1;
	}
	ar.push_back(r);
	ar.push_back(1);

	/*for (int i = 0; i < al.size(); i++) {
		cout << al[i] << '\n';
	}
	cout << '\n';
	for (int i = 0; i < ar.size(); i++) {
		cout << ar[i] << '\n';
	}*/

	for (int i = 0; i < al.size(); i++) {
		bool found = 0;
		for (int j = 0; j < ar.size(); j++) {
			if (al[i] == ar[j]) {
				found = 1;
			}
		}
		if (found) {
			cout << al[i];
			return 0;
		}
	}
}