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
    freopen("bphoto.in", "r", stdin); freopen("bphoto.out", "w", stdout);
    int n; cin >> n;
    int ans = 0;
    seg_tree left(n, 0), right(n, 1);
    vector<pair<int,int>> heights_sorted(n);
    vector<pair<int,int>> heights_original(n);
    for (int i = 0; i < n; i++) {
        cin >> heights_sorted[i].first;
        heights_sorted[i].second = i;
    }

    sort(heights_sorted.begin(), heights_sorted.end());
    for (int i = 0; i < n; i++) {
        heights_original[heights_sorted[i].second] = { heights_sorted[i].first, i };
    }
    
    for (int i = 0; i < n; i++) {
        int sort_idx = heights_original[i].second;
        right.update(sort_idx, 0);
        int taller_left = left.sum(sort_idx, left.n - 1);
        int taller_right = right.sum(sort_idx, right.n - 1);
        ans += max(taller_left, taller_right) > 2 * min(taller_left, taller_right);
        left.update(sort_idx, 1);
    }

    cout << ans << '\n';
}