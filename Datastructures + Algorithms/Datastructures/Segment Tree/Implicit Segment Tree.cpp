#include <bits/stdc++.h>
using namespace std;

struct imp_seg_tree {
	struct vertex {
		vertex* l = nullptr, * r = nullptr;
		long long val = 0;
	};

	long long n;
	vertex* root = new vertex;

	imp_seg_tree() {};
	imp_seg_tree(long long n) : n(n) {};

	void extend(vertex* a) {
		if (!a->l) a->l = new vertex;
		if (!a->r) a->r = new vertex;
	}

	void add(long long idx, long long val) {
		add(idx, val, root, 0, n - 1);
	}
	void add(long long idx, long long val, vertex* v, long long tl, long long tr) {
		if (tl == tr) {
			v->val += val;
			return;
		}

		extend(v);

		long long tm = (tl + tr) / 2;
		if (idx <= tm) {
			add(idx, val, v->l, tl, tm);
		}
		else {
			add(idx, val, v->r, tm + 1, tr);
		}

		v->val = v->l->val + v->r->val;
	}

	void assign(long long idx, long long val) {
		assign(idx, val, root, 0, n - 1);
	}
	void assign(long long idx, long long val, vertex* v, long long tl, long long tr) {
		if (tl == tr) {
			v->val = val;
			return;
		}

		extend(v);

		long long tm = (tl + tr) / 2;
		if (idx <= tm) {
			assign(idx, val, v->l, tl, tm);
		}
		else {
			assign(idx, val, v->r, tm + 1, tr);
		}

		v->val = v->l->val + v->r->val;
	}

	long long sum(long long l, long long r) {
		return sum(l, r, root, 0, n - 1);
	}
	long long sum(long long l, long long r, vertex* v, long long tl, long long tr) {
		if (r < tl or tr < l) {
			return 0;
		}

		if (l <= tl and tr <= r) {
			return v->val;
		}

		extend(v);

		long long tm = (tl + tr) / 2;
		return sum(l, r, v->l, tl, tm) + sum(l, r, v->r, tm + 1, tr);
	}
};