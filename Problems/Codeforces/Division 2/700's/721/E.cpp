#include<bits/stdc++.h>
using namespace std;

const int maxn = 35001;
int n, k;
int prev_el[maxn], last_oc[maxn];

struct seg_tree 
{
	int n;
	vector<int> t, lazy;
	int null = 1e9;

	seg_tree() {};
	seg_tree(int n): n(n) 
	{
		t.resize(4 * n);
		lazy.resize(4 * n, null);
	}

	void propagate(int v, int tl, int tr)
	{
		if (lazy[v] != null)
		{
			t[v] += lazy[v];

			if (tl != tr) 
			{
				lazy[2 * v] = (lazy[2 * v] == null ? 0 : lazy[2 * v]) + lazy[v];
				lazy[2 * v + 1] = (lazy[2 * v + 1] == null ? 0 : lazy[2 * v + 1]) + lazy[v];
			}

			lazy[v] = null;
		}
	}

	void range_add(int l, int r, int added_val)
	{
		range_add(l, r, added_val, 1, 0, n - 1);
	}
	void range_add(int l, int r, int added_val, int v, int tl, int tr) 
	{
		propagate(v, tl, tr);

		if (r < tl or tr < l)
		{
			return;
		}

		if (l <= tl and tr <= r)
		{
			lazy[v] = added_val;
			propagate(v, tl, tr);

			return;
		}

		int tm = (tl + tr) / 2;
		range_add(l, r, added_val, 2 * v, tl, tm);
		range_add(l, r, added_val, 2 * v + 1, tm + 1, tr);

		t[v] = min(t[2 * v], t[2 * v + 1]);
	}

	int mn(int l, int r)
	{
		return mn(l, r, 1, 0, n - 1);
	}
	int mn(int l, int r, int v, int tl, int tr)
	{
		if (r < tl or tr < l) 
		{
			return null;
		}

		propagate(v, tl, tr);

		if (l <= tl and tr <= r) 
		{
			return t[v];
		}

		int tm = (tl + tr) / 2;
		return min(mn(l, r, 2 * v, tl, tm), mn(l, r, 2 * v + 1, tm + 1, tr));
	}
};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> k;

	for (int i = 1; i <= n; i++) 
	{
		int a; cin >> a;

		if (last_oc[a]) 
		{
			prev_el[i] = last_oc[a];
		}

		last_oc[a] = i;
	}

	// the array that the segtree is built over is the dp array
	seg_tree sg(n + 1);
	sg.t.assign(4 * (n + 1), sg.null);
	sg.range_add(0, 0, -sg.null);
	seg_tree sg2(n + 1);

	for (int segments = 1; segments <= k; segments++) 
	{
		for (int i = 1; i <= n; i++) 
		{
			if (prev_el[i]) 
			{
				sg.range_add(0, prev_el[i] - 1, i - prev_el[i]);
			}

			sg2.range_add(i, i, sg.mn(0, i - 1));
		}

		swap(sg, sg2);
		sg2.t.assign(4 * (n + 1), 0);
		sg2.lazy.assign(4 * (n + 1), sg2.null);
	}

	cout << sg.mn(n, n);
}