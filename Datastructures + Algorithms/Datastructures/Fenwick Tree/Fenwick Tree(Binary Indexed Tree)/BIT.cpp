#include<bits/stdc++.h>
using namespace std;

struct bit {

	int n;
	vector<int> b;
	vector<long long> a;

	bit() {}
	bit(int n2, int val = 0) {
		n = n2 + 1;
		a.resize(n);
		b = vector<int>(n, val);
		if (val) {
			for (int i = 0; i < n2; i++) {
				add(i, val);
			}
		}
	}
	bit(vector<int>& b2) {
		n = b2.size() + 1;
		a.resize(n);
		b = b2;
		for (int i = 0; i < b.size(); i++) {
			add(i, b[i]);
		}
	}

	void add(int idx, int val) {
		b[idx] += val;
		for (idx++; idx < n; idx += idx & -idx) {
			a[idx] += val;
		}
	}

	void assign(int idx, int val) {
		int val2 = val;
		val -= b[idx];
		b[idx] = val2;

		add(idx, val);
	}

	long long sum(int idx) {
		long long tot = 0;
		for (idx++; idx > 0; idx -= idx & -idx) {
			tot += a[idx];
		}

		return tot;
	}

	long long sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};