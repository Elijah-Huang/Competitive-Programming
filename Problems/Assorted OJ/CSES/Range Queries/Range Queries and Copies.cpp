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

const int maxn = 2e5;
int n, q;
vector<int> a;
vector<int> array_to_root_idx(1);
seg_tree st;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	st = seg_tree(a);

	while (q--) {
		int t, k;
		cin >> t >> k; k--;
		if (t == 1) {
			int a, x; cin >> a >> x; a--;
			array_to_root_idx[k] = st.assign(array_to_root_idx[k], a, x);
		}
		else if (t == 2) {
			int l, r; cin >> l >> r; l--; r--;
			cout << st.sum(array_to_root_idx[k], l, r) << '\n';
		}
		else {
			array_to_root_idx.push_back(array_to_root_idx[k]);
		}
	}
}