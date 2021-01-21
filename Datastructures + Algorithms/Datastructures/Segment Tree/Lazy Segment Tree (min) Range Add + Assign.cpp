#include<bits/stdc++.h>
using namespace std;

struct seg_tree {

    int n;
    int null = -(1 << 30);
    vector<int> t, lazy_add, lazy_assign;

    seg_tree() {}
    seg_tree(int sz, int element = 0) {
        n = sz;
        t.resize(4 * n);
        lazy_add.resize(4 * n, null);
        lazy_assign.resize(4 * n, null);
        vector<int> a(n, element);
        build(a);
    }
    seg_tree(vector<int>& a) {
        n = a.size();
        t.resize(4 * n);
        lazy_add.resize(4 * n, null);
        lazy_assign.resize(4 * n, null);
        build(a);
    }

    void build(vector<int>& a) {
        build(a, 1, 0, n - 1);
    }
    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = min(t[2 * v], t[2 * v + 1]);
        }
    }

    /* Correctly sets the value of t[v] based on pending update and propagates update to
    * its children. In order for the seg tree to be a valid representation, if either v or its
    * children are going to be used, propagate must be called on v to propagate the updates
    * down to be used to properly set the value of all nodes that are going to be used,
    * whether this be updating lazy for that node or using its value for get(), mn(), or
    * calculating values of nodes that partially contain the range update for range_assign, etc.
    *
    * At most 1 of lazy_assign[v] or lazy_add[v] represent a pending update
    */
    void propagate(int v, int tl, int tr) {
        if (lazy_assign[v] != null) {
            t[v] = lazy_assign[v];

            if (tl != tr) {
                lazy_add[2 * v] = lazy_add[2 * v + 1] = null;
                lazy_assign[2 * v] = lazy_assign[2 * v + 1] = lazy_assign[v];
            }
            lazy_assign[v] = null;
        }
        else if (lazy_add[v] != null) {
            t[v] += lazy_add[v];

            if (tl != tr) {
                if (lazy_assign[2 * v] != null) {
                    lazy_assign[2 * v] = lazy_assign[2 * v] + lazy_add[v];
                }
                else {
                    lazy_add[2 * v] = (lazy_add[2 * v] == null ? lazy_add[v] : lazy_add[2 * v] + lazy_add[v]);
                }
                if (lazy_assign[2 * v + 1] != null) {
                    lazy_assign[2 * v + 1] = lazy_assign[2 * v + 1] + lazy_add[v];
                }
                else {
                    lazy_add[2 * v + 1] = (lazy_add[2 * v + 1] == null ? lazy_add[v] : lazy_add[2 * v + 1] + lazy_add[v]);
                }
            }
            lazy_add[v] = null;
        }
    }

    void assign(int idx, int new_val) {
        assign(idx, new_val, 1, 0, n - 1);
    }
    void assign(int idx, int new_val, int v, int tl, int tr) {
        propagate(v, tl, tr);

        if (tl == tr) {
            lazy_assign[v] = new_val;
            propagate(v, tl, tr);
        }
        else {
            int tm = (tl + tr) / 2;
            if (idx <= tm) {
                propagate(2 * v + 1, tm + 1, tr);
                assign(idx, new_val, 2 * v, tl, tm);
            }
            else {
                propagate(2 * v, tl, tm);
                assign(idx, new_val, 2 * v + 1, tm + 1, tr);
            }

            t[v] = min(t[2 * v], t[2 * v + 1]);
        }
    }

    void add(int idx, int added_val) {
        add(idx, added_val, 1, 0, n - 1);
    }
    void add(int idx, int added_val, int v, int tl, int tr) {
        propagate(v, tl, tr);

        if (tl == tr) {
            lazy_add[v] = (lazy_add[v] == null ? added_val : lazy_add[v] + added_val);
            propagate(v, tl, tr);
        }
        else {
            int tm = (tl + tr) / 2;
            if (idx <= tm) {
                propagate(2 * v + 1, tm + 1, tr);
                assign(idx, added_val, 2 * v, tl, tm);
            }
            else {
                propagate(2 * v, tl, tm);
                assign(idx, added_val, 2 * v + 1, tm + 1, tr);
            }

            t[v] = min(t[2 * v], t[2 * v + 1]);
        }
    }

    void range_assign(int l, int r, int new_val) {
        range_assign(l, r, new_val, 1, 0, n - 1);
    }
    void range_assign(int l, int r, int new_val, int v, int tl, int tr) {
        propagate(v, tl, tr);

        if (tr < l or r < tl) {
            return;
        }

        if (l <= tl and tr <= r) {
            lazy_assign[v] = new_val;
            propagate(v, tl, tr);

            return;
        }

        int tm = (tl + tr) / 2;
        range_assign(l, r, new_val, 2 * v, tl, tm);
        range_assign(l, r, new_val, 2 * v + 1, tm + 1, tr);

        /* Must be recalculated here because only part of the range tl -> tr is updated
        * so it's impractical to set this part in the future. The new lazy values are fine
        * because the entire range must be updated and so we can easily set the
        * node properly with just information from lazy[] and propagate the changes
        */
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    void range_add(int l, int r, int added_val) {
        range_add(l, r, added_val, 1, 0, n - 1);
    }
    void range_add(int l, int r, int added_val, int v, int tl, int tr) {
        propagate(v, tl, tr);

        if (tr < l or r < tl) {
            return;
        }

        if (l <= tl and tr <= r) {
            lazy_add[v] = (lazy_add[v] == null ? added_val : lazy_add[v] + added_val);
            propagate(v, tl, tr);

            return;
        }

        int tm = (tl + tr) / 2;
        range_add(l, r, added_val, 2 * v, tl, tm);
        range_add(l, r, added_val, 2 * v + 1, tm + 1, tr);

        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    int get(int idx) {
        return get(idx, 1, 0, n - 1);
    }
    int get(int idx, int v, int tl, int tr) {
        propagate(v, tl, tr);

        if (tl == tr) {
            return t[v];
        }
        else {
            int tm = (tl + tr) / 2;
            if (idx <= tm) {
                return get(idx, 2 * v, tl, tm);
            }
            else {
                return get(idx, 2 * v + 1, tm + 1, tr);
            }
        }
    }

    int mn(int l, int r) {
        return mn(l, r, 1, 0, n - 1);
    }
    int mn(int l, int r, int v, int tl, int tr) {
        if (tr < l or r < tl) {
            return 1 << 30;
        }

        propagate(v, tl, tr);

        if (l <= tl and tr <= r) {
            return t[v];
        }

        int tm = (tl + tr) / 2;
        return min(mn(l, r, 2 * v, tl, tm), mn(l, r, 2 * v + 1, tm + 1, tr));
    }
};