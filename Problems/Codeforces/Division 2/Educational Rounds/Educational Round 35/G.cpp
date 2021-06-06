#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int n, q;
int a[maxn];

// lazy segtree 
char t[4 * maxn][101]; // stores the mapping/transformation
char lazy[4 * maxn][101]; // pending future mapping/transformation to be applied on top of current one in t
bool pending[4 * maxn]; // if pending to improve constant factor a bit

void propagate(int v, int tl, int tr) {
	if (pending[v]) {
		// update
		for (int i = 0; i < 101; i++) {
			t[v][i] = lazy[v][t[v][i]];
		}
		pending[v] = 0;

		// push and update pending mappings/transformations
		if (tl != tr) {
			vector<int> a = { 2 * v, 2 * v + 1 };
			for (auto v2 : a) {
				if (pending[v2]) {
					for (int i = 0; i < 101; i++) {
						lazy[v2][i] = lazy[v][lazy[v2][i]];
					}
				}
				else {
					memcpy(lazy[v2], lazy[v], sizeof(lazy[v]));
					pending[v2] = 1;
				}
			}
		}
	}
}

void update(int l, int r, int x, int y, int v = 1, int tl = 0, int tr = n - 1) {
	if (tr < l or r < tl) {
		return;
	}

	propagate(v, tl, tr);

	if (l <= tl and tr <= r) {
		iota(lazy[v], lazy[v] + 101, 0);
		lazy[v][x] = y;
		pending[v] = 1;
		return;
	}

	int tm = (tl + tr) / 2;
	update(l, r, x, y, 2 * v, tl, tm);
	update(l, r, x, y, 2 * v + 1, tm + 1, tr);
}

int get(int i, int v = 1, int tl = 0, int tr = n - 1) {
	propagate(v, tl, tr);

	if (tl == tr) {
		return t[v][a[i]];
	}

	int tm = (tl + tr) / 2;
	if (i <= tm) {
		return get(i, 2 * v, tl, tm);
	}
	else {
		return get(i, 2 * v + 1, tm + 1, tr);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 4 * n; i++) {
		iota(t[i], t[i] + 101, 0);
	}

	cin >> q;

	while (q--) {
		int l, r, x, y; 
		cin >> l >> r >> x >> y; 
		l--; r--;

		update(l, r, x, y);
	}

	for (int i = 0; i < n; i++) {
		cout << get(i) << ' ';
	}
}