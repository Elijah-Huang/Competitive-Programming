#include<bits/stdc++.h>
using namespace std;

struct seg_tree {

    int n, null = -(1ll << 62);
    vector<long long> t, lazy_add, lazy_assign;

    seg_tree() {}
    seg_tree(int sz, int element) {
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
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    /* correctly sets the value of t[v] based on pending update and propagates update to
    * its children in order for the seg tree to be a valid representation, if either v or its
    * children are going to be used, propagate must be called on v to propagate the updates
    * down to be used to properly set the value of all nodes that are going to be used
    * whether this be updating lazy for that node or using its value for get(), sum() etc.
    */
    void propagate(int v, int tl, int tr) {
        if (lazy_assign[v] != null) {
            t[v] = (tr - tl + 1) * lazy_assign[v];

            if (tl != tr) {
                lazy_add[2 * v] = lazy_add[2 * v + 1] = null;
                lazy_assign[2 * v] = lazy_assign[2 * v + 1] = lazy_assign[v];
            }
            lazy_assign[v] = null;
        }
        else if (lazy_add[v] != null) {
            t[v] += (tr - tl + 1) * lazy_add[v];

            if (tl != tr) {
                if (lazy_assign[2 * v]) {
                    lazy_assign[2 * v] = (lazy_assign[2 * v] == null ? lazy_add[v] : lazy_assign[2 * v] + lazy_add[v]);
                }
                else {
                    lazy_add[2 * v] = (lazy_add[2 * v] == null ? lazy_add[v] : lazy_add[2 * v] + lazy_add[v]);
                }
                if (lazy_assign[2 * v + 1]) {
                    lazy_assign[2 * v + 1] = (lazy_assign[2 * v + 1] == null ? lazy_add[v] : lazy_assign[2 * v + 1] + lazy_add[v]);
                }
                else {
                    lazy_add[2 * v + 1] = (lazy_add[2 * v + 1] == null ? lazy_add[v] : lazy_add[2 * v + 1] + lazy_add[v]);
                }
            }
            lazy_add[v] = null;
        }
    }

    void assign(int idx, long long new_val) {
        assign(idx, new_val, 1, 0, n - 1);
    }
    void assign(int idx, long long new_val, int v, int tl, int tr) {
        if (tl == tr) {
            lazy_assign[v] = new_val;
            propagate(v, tl, tr);
        }
        else {
            propagate(v, tl, tr);

            int tm = (tl + tr) / 2;
            if (idx <= tm) {
                propagate(2 * v + 1, tm + 1, tr);
                assign(idx, new_val, 2 * v, tl, tm);
            }
            else {
                propagate(2 * v, tl, tm);
                assign(idx, new_val, 2 * v + 1, tm + 1, tr);
            }

            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    void add(int idx, long long added_val) {
        add(idx, added_val, 1, 0, n - 1);
    }
    void add(int idx, long long added_val, int v, int tl, int tr) {
        if (tl == tr) {
            lazy_add[v] = (lazy_add[v] == null ? added_val : lazy_add[v] + added_val);
            propagate(v, tl, tr);
        }
        else {
            propagate(v, tl, tr);

            int tm = (tl + tr) / 2;
            if (idx <= tm) {
                propagate(2 * v + 1, tm + 1, tr);
                assign(idx, added_val, 2 * v, tl, tm);
            }
            else {
                propagate(2 * v, tl, tm);
                assign(idx, added_val, 2 * v + 1, tm + 1, tr);
            }

            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    void range_assign(int l, int r, int new_val) {
        range_assign(l, r, new_val, 1, 0, n - 1);
    }
    void range_assign(int l, int r, int new_val, int v, int tl, int tr) {
        if (l <= tl and tr <= r) {
            lazy_assign[v] = new_val;
            propagate(v, tl, tr);

            return;
        }

        propagate(v, tl, tr);

        if (tr < l or r < tl) {
            return;
        }

        int tm = (tl + tr) / 2;
        range_assign(l, r, new_val, 2 * v, tl, tm);
        range_assign(l, r, new_val, 2 * v + 1, tm + 1, tr);

        /* must be recalculated here because only part of the range tl -> tr is updated
        * so it's impractical to set this part in the future. the new lazy values are fine
        * because the entire range must be updated and so we can easily set the
        * node properly with just information from lazy and propagate the changes
        */
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    void range_add(int l, int r, int added_val) {
        range_add(l, r, added_val, 1, 0, n - 1);
    }
    void range_add(int l, int r, int added_val, int v, int tl, int tr) {
        if (l <= tl and tr <= r) {
            if (lazy_assign[v] == null) {
                propagate(v, tl, tr);
            }
            lazy_add[v] = (lazy_add[v] == null ? added_val : lazy_add[v] + added_val);
            propagate(v, tl, tr);

            return;
        }

        propagate(v, tl, tr);

        if (tr < l or r < tl) {
            return;
        }

        int tm = (tl + tr) / 2;
        range_add(l, r, added_val, 2 * v, tl, tm);
        range_add(l, r, added_val, 2 * v + 1, tm + 1, tr);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    long long get(int idx) {
        return get(idx, 1, 0, n - 1);
    }
    long long get(int idx, int v, int tl, int tr) {
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

    long long sum(int l, int r) {
        return sum(l, r, 1, 0, n - 1);
    }
    long long sum(int l, int r, int v, int tl, int tr) {
        if (tr < l or r < tl) {
            return 0ll;
        }

        propagate(v, tl, tr);

        if (l <= tl and tr <= r) {
            return t[v];
        }

        int tm = (tl + tr) / 2;
        return sum(l, r, 2 * v, tl, tm) + sum(l, r, 2 * v + 1, tm + 1, tr);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    seg_tree st(a);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, u; cin >> a >> b >> u;
            a--; b--;
            st.range_add(a, b, u);
        }
        else {
            int k; cin >> k; k--;
            cout << st.get(k) << '\n';
        }
    }
}