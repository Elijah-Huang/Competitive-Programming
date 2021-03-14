#include<bits/stdc++.h>
using namespace std;

struct checkpoint {
	int x, y;
};

const int maxn = 1e5;
int n, q;
checkpoint points[maxn];

int dist(int i, int j) {
	return abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y);
}

// bit (you could just copy paste the segtree and change it a bit ofc, but this is just for practice)
// stores distances between points -> n-1 checkpoints
int a[maxn + 10], vals[maxn + 10];

void update_bit(int idx, int val) {
	idx++;
	int diff = val - vals[idx];
	vals[idx] = val;
	for (; idx <= n-1; idx += idx & -idx) {
		a[idx] += diff;
	}
}

int sump(int idx) {
	int ret = 0;
	for (idx++; idx > 0; idx -= idx & -idx) {
		ret += a[idx];
	}
	return ret;
}

int sum(int l, int r) {
	return sump(r) - sump(l - 1);
}


// segtree
// stores changes in dist via skipping checkpoints -> n-2 checkpoints
int t[4 * maxn];

void build(vector<int>& a, int v = 1, int tl = 0, int tr = n-1) {
	if (tl == tr) {
		t[v] = a[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build(a, 2 * v, tl, tm);
		build(a, 2 * v + 1, tm + 1, tr);
		t[v] = max(t[2 * v], t[2 * v + 1]);
	}
}

void update_segtree(int idx, int val, int v = 1, int tl = 0, int tr = n - 1) {
	if (tl == tr) {
		t[v] = val;
	}
	else {
		int tm = (tl + tr) / 2;
		if (idx <= tm) {
			update_segtree(idx, val, 2 * v, tl, tm);
		}
		else {
			update_segtree(idx, val, 2 * v + 1, tm + 1, tr);
		}

		t[v] = max(t[2 * v], t[2 * v + 1]);
	}
}

int findmax(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
	if (tr < l or r < tl) {
		return 0;
	}

	if (l <= tl and tr <= r) {
		return t[v];
	}

	int tm = (tl + tr) / 2;
	return max(findmax(l, r, 2 * v, tl, tm), findmax(l, r, 2 * v + 1, tm + 1, tr));
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("marathon.in", "r", stdin); freopen("marathon.out", "w", stdout);

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	}
	
	// set up bit and segtree
	for (int i = 0; i < n - 1; i++) {
		update_bit(i, dist(i, i + 1));
	}

	vector<int> a(n);
	for (int i = 1; i < n - 1; i++) {
		a[i] = dist(i - 1, i) + dist(i, i + 1) - dist(i-1, i + 1);
	}
	build(a);

	while (q--) {
		char t; cin >> t;
		if (t == 'Q') {
			int l, r; cin >> l >> r; l--; r--;

			cout << sum(l, r - 1) - (r >= l + 2 ? findmax(l + 1, r - 1) : 0) << '\n';
		}
		else {
			int p; cin >> p; p--;
			int x, y; cin >> x >> y;
			points[p] = { x,y };

			if (p > 0) {
				update_bit(p - 1, dist(p - 1, p));
			}
			if (p < n - 1) {
				update_bit(p, dist(p, p + 1));
			}
			
			if (p >= 1) {
				update_segtree(p, dist(p - 1, p) + dist(p, p + 1) - dist(p - 1, p + 1));
			}
			if (p >= 2) {
				update_segtree(p - 1, dist(p - 2, p - 1) + dist(p - 1, p) - dist(p - 2, p));
			}
			if (p < n - 2) {
				update_segtree(p + 1, dist(p, p + 1) + dist(p + 1, p + 2) - dist(p, p + 2));
			}
		}
	}
}