#include<bits/stdc++.h>
using namespace std;

struct seg_tree
{
	int n;
	vector<int> t, lazy;
	int null = 1e9;

	seg_tree() {};
	seg_tree(int n) : n(n)
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