#include<bits/stdc++.h>
using namespace std;

struct seg_tree {

    int n, l, r, idx;
    int null = 0;
    vector<int> t, lazy_assign;

    seg_tree() {}
    seg_tree(int sz, int element = 0) {
        n = sz;
        t.resize(4 * n);
        lazy_assign.resize(4 * n, null);
        vector<int> a(n, element);
        build(a);
    }
    seg_tree(vector<int>& a) {
        n = a.size();
        t.resize(4 * n);
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
            t[v] = max(t[2 * v], t[2 * v + 1]);
        }
    }

    /* Correctly sets the value of t[v] based on pending update and propagates update to
    * its children. In order for the seg tree to be a valid representation, if either v or its
    * children are going to be used, propagate must be called on v to propagate the updates
    * down to be used to properly set the value of all nodes that are going to be used,
    * whether this be updating lazy for that node or using its value for get(), mx(), or
    * calculating values of nodes that partially contain the range update for range_assign, etc.
    *
    * At most 1 of lazy_assign[v] or lazy_add[v] represent a pending update
    */
    void propagate(int v, int tl, int tr) {
        if (lazy_assign[v]) {
            t[v] = lazy_assign[v];

            if (tl != tr) {
                lazy_assign[2 * v] = lazy_assign[2 * v + 1] = lazy_assign[v];
            }
            lazy_assign[v] = null;
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

            t[v] = max(t[2 * v], t[2 * v + 1]);
        }
    }

    void range_assign(int l, int r, int new_val) {
        this->l = l;
        this->r = r;
        range_assign(new_val, 1, 0, n - 1);
    }
    void range_assign(int new_val, int v, int tl, int tr) {
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
        range_assign(new_val, 2 * v, tl, tm);
        range_assign(new_val, 2 * v + 1, tm + 1, tr);

        /* Must be recalculated here because only part of the range tl -> tr is updated
        * so it's impractical to set this part in the future. The new lazy values are fine
        * because the entire range must be updated and so we can easily set the
        * node properly with just information from lazy[] and propagate the changes
        */
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    int get(int idx) {
        this->idx = idx;
        return get(1, 0, n - 1);
    }
    int get(int v, int tl, int tr) {
        propagate(v, tl, tr);

        if (tl == tr) {
            return t[v];
        }
        else {
            int tm = (tl + tr) / 2;
            if (idx <= tm) {
                return get(2 * v, tl, tm);
            }
            else {
                return get(2 * v + 1, tm + 1, tr);
            }
        }
    }

    int mx(int l, int r) {
        this->l = l;
        this->r = r;
        return mx(1, 0, n - 1);
    }
    int mx(int v, int tl, int tr) {
        if (tr < l or r < tl) {
            return 0;
        }

        propagate(v, tl, tr);

        if (l <= tl and tr <= r) {
            return t[v];
        }

        int tm = (tl + tr) / 2;
        return max(mx(2 * v, tl, tm), mx(2 * v + 1, tm + 1, tr));
    }
};


int n, q;
seg_tree skyscrapers;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    skyscrapers = seg_tree(a);

    while (q--) {
        int t; cin >> t;

        if (t == 1) {
            int i; cin >> i; i--;
           
            int height = skyscrapers.get(i);
            int left, right;

            int l = 0, r = i;
            while (l != r) {
                int m = (l + r) / 2;
                if (skyscrapers.mx(m, i) > height) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
            }
            left = l;

            l = i, r = n-1;
            while (l != r) {
                int m = (l + r + 1) / 2;
                if (skyscrapers.mx(i, m) > height) {
                    r = m - 1;
                }
                else {
                    l = m;
                }
            }
            right = l;

            cout << right - left + 1 << '\n';
        }
        else if (t == 2) {
            int i, x; cin >> i >> x; i--;
            skyscrapers.assign(i, x);
        }
        else {
            int i, j, x; cin >> i >> j >> x; i--, j--;
            skyscrapers.range_assign(i, j, x);
        }
    }
}