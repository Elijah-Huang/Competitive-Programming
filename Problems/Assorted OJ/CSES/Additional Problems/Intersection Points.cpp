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

const long long maxc = 2e6 + 1, shift = 1e6;
int n;
imp_seg_tree ist(maxc);

long long ans = 0;

struct query {
	int t, y, l, r;
};

vector<query> queries;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			queries.push_back({ 1, y1, x1, 1 });
			queries.push_back({ 1, y2 + 1, x2, -1 }); // since queries of type 1(updates) come before type 2(sums) if y is equal
		}
		else {
			queries.push_back({ 2,y1,x1,x2 });
		}
	}

	sort(queries.begin(), queries.end(), [&](query& a, query& b) {return make_pair(a.y, a.t) < make_pair(b.y, b.t); });

	for (auto& q : queries) {
		if (q.t == 1) {
			ist.add(q.l + shift, q.r);
		}
		else {
			ans += ist.sum(q.l + shift, q.r + shift);
		}
	}

	cout << ans << '\n';
}