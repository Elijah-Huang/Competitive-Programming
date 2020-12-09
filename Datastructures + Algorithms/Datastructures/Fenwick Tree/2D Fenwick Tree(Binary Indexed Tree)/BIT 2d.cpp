#include<bits/stdc++.h>
using namespace std;

struct bit {

	int n1, n2;
	vector<vector<int>> a;
	vector<vector<int>> a2;

	bit() {}
	bit(int x2, int y2, int val) {
		n1 = x2+1;
		n2 = y2+1;
		a = vector<vector<int>>(n1, vector<int>(n2));
		a2 = vector<vector<int>>(x2, vector<int>(y2, val));
		if (val) {
			for (int i = 0; i < n1-1; i++) {
				for (int j = 0; j < n2-1; j++) {
					add(i, j, val);
				}
			}
		}
	}
	bit(vector<vector<int>>& b) {
		n1 = b.size() + 1;
		n2 = b[0].size() + 1;
		a = vector<vector<int>>(n1, vector<int>(n2));
		a2 = b;
		for (int i = 0; i < n1-1; i++) {
			for (int j = 0; j < n2-1; j++) {
				add(i, j, b[i][j]);
			}
		}
	}

	void add(int idx1, int idx2, int val) {
		for (idx1++; idx1 < n1; idx1 += idx1 & -idx1) {
			for (idx2++; idx2 < n2; idx2 += idx2 & -idx2) {
				a[idx1][idx2] += val;
			}
		}
	}

	void update(int idx1, int idx2, int val) {
		int val2 = val;
		val -= a2[idx1][idx2];
		a2[idx1][idx2] = val2;
		add(idx1, idx2, val);
	}

	long long sum(int idx1, int idx2) {
		long long tot = 0;
		for (idx1++; idx1 < n1; idx1 -= idx1 & -idx1) {
			for (idx2++; idx2 < n2; idx2 -= idx2 & -idx2) {
				tot += a[idx1][idx2];
			}
		}
		return tot;
	}

	long long sum(int idx1, int idx2, int idx3, int idx4) {
		if (idx4 > idx2) {
			swap(idx4, idx2);
		}
		if (idx3 > idx1) {
			swap(idx3, idx1);
		}
		return sum(idx1, idx2) - sum(idx1, idx4 - 1) - sum(idx3 - 1, idx2) + sum(idx3 - 1, idx4 - 1);
	}
};