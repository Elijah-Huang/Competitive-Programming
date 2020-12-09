#include<bits/stdc++.h>
using namespace std;

struct bit {

	int n;
	vector<int> a;
	vector<int> a2;

	bit() {}
	bit(int n2, int val) {
		n = n2 + 1;
		a.resize(n);
		a2 = vector<int>(n, val);
		if (val) {
			for (int i = 0; i < n2; i++) {
				add(i, val);
			}
		}
	}
	bit(vector<int>& b) {
		n = b.size() + 1;
		a.resize(n);
		a2 = b;
		for (int i = 0; i < b.size(); i++) {
			add(i, b[i]);
		}
	}

	void add(int idx, int val) {
		for (idx++; idx < n; idx += idx & -idx) {
			a[idx] += val;
		}
	}

	void update(int idx, int val) {
		int val2 = val;
		val -= a2[idx];
		a2[idx] = val2;
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