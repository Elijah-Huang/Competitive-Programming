#include <bits/stdc++.h>
using namespace std;
struct seg_tree {
    int n;
    vector<long long> t;
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
};
struct tarrif {
    int l, r, c, p;
};
struct opening {
    int t, i;
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    vector<tarrif> t(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i].l >> t[i].r >> t[i].c >> t[i].p;
    }
    sort(t.begin(), t.end(), [&](auto& a, auto& b) { return a.p < b.p; });
    vector<opening> start(m);
    vector<opening> end(m);
    for (int i = 0; i < m; i++) {
        start[i] = opening({ t[i].l,i });
        end[i] = opening({ t[i].r,i });
    }
    auto cmp = [&](auto& a, auto& b) {return a.t < b.t; };
    sort(start.begin(), start.end(), cmp);
    sort(end.begin(), end.end(), cmp);
    long long cost = 0;
    vector<int> zeros(m);
    seg_tree amounts(zeros);
    seg_tree costs(zeros);
    int s_ptr = 0, e_ptr = 0;
    for (int day = 1; day <= n; day++) {
        while (s_ptr < m and start[s_ptr].t <= day) {
            amounts.update(start[s_ptr].i, t[start[s_ptr].i].c);
            costs.update(start[s_ptr].i, (long long)t[start[s_ptr].i].c * t[start[s_ptr].i].p);
            s_ptr++;
        }
        int lb = 0, rb = m - 1;
        while (lb != rb) {
            int mid = (lb + rb) / 2;
            if (amounts.sum(0, mid) >= k) {
                rb = mid;
            }
            else {
                lb = mid+1;
            }
        }
        cost += costs.sum(0, lb);
        long long total = amounts.sum(0, lb);
        if (k < total) {
            cost -= (total-k) * t[lb].p;
        }
        while (e_ptr < m and end[e_ptr].t <= day) {
            amounts.update(end[e_ptr].i, 0);
            costs.update(end[e_ptr].i, 0);
            e_ptr++;
        }
    }
    cout << cost;
}