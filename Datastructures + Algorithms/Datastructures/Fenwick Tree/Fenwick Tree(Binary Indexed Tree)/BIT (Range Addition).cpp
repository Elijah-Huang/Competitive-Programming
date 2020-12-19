#include<bits/stdc++.h>
using namespace std;

struct bit {

	int n;
	vector<long long> a, c;

	bit() {}
	bit(int n2, long long val = 0) {
		n = n2 + 2;
		a.resize(n);
		c.resize(n);
		if (val) {
			for (int i = 0; i < n2; i++) {
				add(a, i, val);
			}
		}
	}
	bit(vector<int>& b2) {
		n = b2.size() + 2;
		a.resize(n);
		c.resize(n);
		for (int i = 0; i < b2.size(); i++) {
			add(a, i, b2[i]);
		}
	}

	void add(vector<long long>& a, int idx, long long val) {
		for (idx++; idx < n; idx += idx & -idx) {
			a[idx] += val;
		}
	}

	void assign(vector<long long>& a, int idx, long long val) {
		add(a, idx, val - sum(idx, idx));
	}

	void range_add(int l, int r, long long val) {
		add(a, l, -(l - 1) * val);
		add(c, l, val);
		add(c, r + 1, -val);
		add(a, r + 1, r * val);
	}

	long long sum_one(vector<long long>& a, int idx) {
		long long tot = 0;
		for (idx++; idx > 0; idx -= idx & -idx) {
			tot += a[idx];
		}
		
		return tot;
	}

	long long sum_true(int idx) {
		return sum_one(a, idx) + idx * sum_one(c, idx);
	}

	long long sum(int l, int r) {
		return sum_true(r) - sum_true(l - 1);
	}
};