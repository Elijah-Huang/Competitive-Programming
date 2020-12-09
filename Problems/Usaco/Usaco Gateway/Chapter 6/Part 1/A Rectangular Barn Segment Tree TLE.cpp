/*
ID: elijahj1
TASK: rectbarn
LANG: C++14
*/
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
            t[v] = max(t[v * 2] , t[v * 2 + 1]);
        }
    }

    long long sum(int l, int r) {
        return sum(l, r, 1, 0, n - 1);
    }
    long long sum(int l, int r, int v, int tl, int tr) {
        if (l > r)
            return -4000ll;
        if (l == tl and r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return max(sum(l, min(r, tm), v * 2, tl, tm)
            , sum(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr));
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
            t[v] = max(t[v * 2] , t[v * 2 + 1]);
        }
    }

};


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("rectbarn.in", "r", stdin); freopen("rectbarn.out", "w", stdout);
    long long best_area = 0;
    int r, c, p; cin >> r >> c >> p;
    vector<vector<int>> points(r + 1);
    vector<int> active_damaged(c + 1,0);
    while (p--) {
        int x, y; cin >> x >> y;
        points[x].push_back(y);
    }

    for (int max_x = 1; max_x <= r; max_x++) {
        for (auto y : points[max_x]) {
            active_damaged[y] = max_x;
        }
        vector<vector<int>> nxt_y(r + 1, { c + 1 });
        seg_tree left_seg(r + 1, 0), right_seg(r + 1, -(c + 1));
        for (int y = c; y >= 1; y--) {
            right_seg.update(active_damaged[y], -y);
            nxt_y[active_damaged[y]].push_back(y);
        }

        for (int y = 1; y <= c; y++) {
            nxt_y[active_damaged[y]].pop_back();
            right_seg.update(active_damaged[y], -nxt_y[active_damaged[y]].back());
            if (active_damaged[y] != max_x) {
                best_area = max(best_area, (max_x - active_damaged[y]) * 
                    (-right_seg.sum(active_damaged[y] + 1, max_x) - left_seg.sum(active_damaged[y] + 1, max_x) - 1));

            }
            left_seg.update(active_damaged[y], y);
        }
    }

    cout << best_area << '\n';
}