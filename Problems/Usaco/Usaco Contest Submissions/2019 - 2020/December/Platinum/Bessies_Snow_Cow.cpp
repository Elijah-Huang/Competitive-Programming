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

const int maxn = 1e5 + 1;
int n, q, t = -1;
int tin[maxn], tout[maxn];
vector<int> adj[maxn];
bit bt(maxn);
set<pair<int,int>> colors[maxn];

void dfs(int c, int p) {
	tin[c] = ++t;

	for (auto n : adj[c]) {
		if (n != p) {
			dfs(n, c);
		}
	}

	tout[c] = t;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("snowcow.in", "r", stdin); freopen("snowcow.out", "w", stdout);
	
	cin >> n >> q;
	
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, c; cin >> x >> c;
			
			auto i = colors[c].upper_bound({ tin[x],0 });
			if (i != colors[c].begin()) {
				i--;
				if (i->first <= tin[x] and tout[x] <= i->second) {
					continue;
				}
			}

			for (auto i = colors[c].lower_bound({ tin[x],-1 }); i != colors[c].end() and i->first <= tout[x];) {
				auto i2 = next(i);
				bt.range_add(i->first, i->second, -1);
				colors[c].erase(i);
				i = i2;
			}

			bt.range_add(tin[x], tout[x], 1);
			colors[c].insert({ tin[x],tout[x] });
		}
		else {
			int x; cin >> x;
			cout << bt.sum(tin[x], tout[x]) << '\n';
		}
	}
}