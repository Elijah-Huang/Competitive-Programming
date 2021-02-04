#include<bits/stdc++.h>
using namespace std;

struct seg_tree {
	struct vertex {
		vertex* l, * r;
		long long val;

		vertex(long long val = 0) : l(nullptr), r(nullptr), val(val) {};
		vertex(vertex* l, vertex* r) : l(l), r(r), val(l->val + r->val) {};
	};

	int n;
	vector<vertex*> versions;

	seg_tree() {};
	seg_tree(vector<int>& a) {
		this->n = a.size();
		versions.push_back(build(a, 0, n - 1));
	}
	seg_tree(int n, int val) {
		this->n = n;
		vector<int> a(n, val);
		versions.push_back(build(a, 0, n - 1));
	}

	vertex* build(vector<int>& a, int tl, int tr) {
		if (tl == tr) {
			return new vertex(a[tl]);
		}

		int tm = (tl + tr) / 2;
		return new vertex(build(a, tl, tm), build(a, tm + 1, tr));
	}

	int assign(int root_idx, int idx, long long val) {
		versions.push_back(assign(idx, val, versions[root_idx], 0, n - 1));
		return versions.size() - 1;
	}
	vertex* assign(int idx, long long val, vertex* v, int tl, int tr) {
		if (tl == tr) {
			return new vertex(val);
		}

		int tm = (tl + tr) / 2;
		if (idx <= tm) {
			return new vertex(assign(idx, val, v->l, tl, tm), v->r);
		}
		else {
			return new vertex(v->l, assign(idx, val, v->r, tm + 1, tr));
		}
	}

	int add(int root_idx, int idx, long long val) {
		versions.push_back(add(idx, val, versions[root_idx], 0, n - 1));
		return versions.size() - 1;
	}
	vertex* add(int idx, long long val, vertex* v, int tl, int tr) {
		if (tl == tr) {
			return new vertex(v->val + val);
		}

		int tm = (tl + tr) / 2;
		if (idx <= tm) {
			return new vertex(add(idx, val, v->l, tl, tm), v->r);
		}
		else {
			return new vertex(v->l, add(idx, val, v->r, tm + 1, tr));
		}
	}

	long long sum(int root_idx, int l, int r) {
		return sum(l, r, versions[root_idx], 0, n - 1);
	}
	long long sum(int l, int r, vertex* v, int tl, int tr) {
		if (tl > r or tr < l) {
			return 0;
		}

		if (l <= tl and tr <= r) {
			return v->val;
		}

		int tm = (tl + tr) / 2;
		return sum(l, r, v->l, tl, tm) + sum(l, r, v->r, tm + 1, tr);
	}
};