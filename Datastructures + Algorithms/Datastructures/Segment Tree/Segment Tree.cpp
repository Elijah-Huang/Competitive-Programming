#include<bits/stdc++.h>
using namespace std;

struct seg_tree {

    int n;
    vector<long long> t;

    seg_tree() {}
    seg_tree(int sz, int element = 0) {
        n = sz;
        t.resize(4 * n);
        vector<int> a(n, element);
        build(a);
    }
    seg_tree(vector<int>& a) {
        n = a.size();
        t.resize(4 * n);
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
            build(a, 2 * v , tl, tm);
            build(a, 2 * v  + 1, tm + 1, tr);
            t[v] = t[2 * v ] + t[2 * v  + 1];
        }
    }

    void assign(int idx, long long new_val) {
        assign(idx, new_val, 1, 0, n - 1);
    }
    void assign(int idx, long long new_val, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = new_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (idx <= tm) {
                assign(idx, new_val, 2 * v , tl, tm);
            }
            else {
                assign(idx, new_val, 2 * v  + 1, tm + 1, tr);
            }

            t[v] = t[2 * v ] + t[2 * v  + 1];
        }
    }

    void add(int idx, long long added_val) {
        add(idx, added_val, 1, 0, n - 1);
    }
    void add(int idx, long long added_val, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] += added_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (idx <= tm) {
                add(idx, added_val, 2 * v , tl, tm);
            }
            else {
                add(idx, added_val, 2 * v  + 1, tm + 1, tr);
            }

            t[v] = t[2 * v ] + t[2 * v  + 1];
        }
    }

    long long sum(int l, int r) {
        return sum(l, r, 1, 0, n - 1);
    }
    long long sum(int l, int r, int v, int tl, int tr) {
        if (tr < l or r < tl) {
            return 0ll;
        }

        if (l <= tl and tr <= r) {
            return t[v];
        }

        int tm = (tl + tr) / 2;
        return sum(l, r, 2 * v, tl, tm) + sum(l, r, 2 * v + 1, tm + 1, tr);
    }
};