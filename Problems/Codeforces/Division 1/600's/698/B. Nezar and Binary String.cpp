#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int tc, n, q;
string s, f;
vector<pair<int, int>> queries;

// lazy seg tree
int t[4 * maxn], assign[4 * maxn];

void propagate(int v, int tl, int tr) {
	if (assign[v] != -1) {
		t[v] = (tr - tl + 1) * assign[v];
		if (tl != tr) {
			assign[2 * v] = assign[2 * v + 1] = assign[v];
		}
		assign[v] = -1;
	}
}

void range_assign(int l, int r, int x, int v = 1, int tl = 0, int tr = n - 1) {
	propagate(v, tl, tr);

	if (l > tr or r < tl) {
		return;
	}

	if (l <= tl and tr <= r) {
		assign[v] = x;
		t[v] = (tr - tl + 1) * x;
		return;
	}

	int tm = (tl + tr) / 2;
	range_assign(l, r, x, 2 * v, tl, tm);
	range_assign(l, r, x, 2 * v + 1, tm + 1, tr);
	
	t[v] = t[2 * v] + t[2 * v + 1];
}

int sum(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
	if (l > tr or r < tl) {
		return 0;
	}

	propagate(v, tl, tr);

	if (l <= tl and tr <= r) {
		return t[v];
	}

	int tm = (tl + tr) / 2;
	return sum(l, r, 2 * v, tl, tm) + sum(l, r, 2 * v + 1, tm + 1, tr);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	fill(assign, assign + 4 * maxn, -1);

	cin >> tc;
	while (tc--) {
		bool fail = false;

		cin >> n >> q;
		
		cin >> s >> f;

		for (int i = 0; i < f.length(); i++) {
			range_assign(i, i, f[i] == '1');
		}

		for (int i = 0; i < q; i++) {
			int l, r; cin >> l >> r; l--; r--;
			queries.push_back({ l,r });
		}
		
		for (int i = q-1; i >= 0 and !fail; i--) {
			if (!fail) {
				int l = queries[i].first, r = queries[i].second;
				int ones = sum(l, r);
				int zeros = (r - l + 1) - ones;
				int tot = ones + zeros;

				if (ones == zeros) {
					fail = true;
				}
				else if (ones < zeros) {
					range_assign(l, r, 0);
				}
				else {
					range_assign(l, r, 1);
				}
			}
		}
		
		for (int i = 0; i < s.length() and !fail; i++) {
			if (s[i] - '0' != sum(i, i)) {
				fail = true;
			}
		}

		cout << (fail ? "NO" : "YES") << '\n';

		queries.clear();
	}
}