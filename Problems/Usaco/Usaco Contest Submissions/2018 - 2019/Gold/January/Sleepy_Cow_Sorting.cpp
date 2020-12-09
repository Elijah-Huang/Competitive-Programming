#include<bits/stdc++.h>
using namespace std;

struct seg_tree {

    int n;
    vector<long long> t;

    seg_tree() {}
    seg_tree(int sz, int element) {
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
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    long long sum(int l, int r) {
        return sum(l, r, 1, 0, n - 1);
    }
    long long sum(int l, int r, int v, int tl, int tr) {
        if (l > r)
            return 0ll;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(l, min(r, tm), v * 2, tl, tm)
            + sum(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
    }

    void update(int pos, long long new_val) {
        update(pos, new_val, 1, 0, n - 1);
    }
    void update(int pos, long long new_val, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = new_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(pos, new_val, v * 2, tl, tm);
            else
                update(pos, new_val, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void add(int pos, long long added_val) {
        add(pos, added_val, 1, 0, n - 1);
    }
    void add(int pos, long long added_val, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] += added_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                add(pos, added_val, v * 2, tl, tm);
            else
                add(pos, added_val, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("sleepy.in", "r", stdin); freopen("sleepy.out", "w", stdout);
    int n; cin >> n;
    seg_tree sgt(n + 1, 0);
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }
    
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (order[i] > order[i + 1]) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << '\n';
    for (int i = ans; i < n; i++) {
        sgt.update(order[i], 1);
    }
    for (int i = 0; i < ans; i++) {
        cout << n - 1 - sgt.sum(order[i] + 1, sgt.n - 1) << (i == ans - 1 ? '\n' : ' ');
        sgt.update(order[i], 1);
    }
}