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
    freopen("circlecross.in", "r", stdin); freopen("circlecross.out", "w", stdout);
    int n; cin >> n;
    seg_tree intersect(2 * n, 0);
    vector<pair<int, int>> road(n, { -1,-1 });
	for (int i = 0; i < 2 * n; i++) {
        int x; cin >> x; x--;
        if (road[x].first == -1) {
            road[x].first = i;
            intersect.update(i, 1);
        }
        else {
            road[x].second = i;
            intersect.update(i, -1);
        }
	}
    sort(road.begin(), road.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (road[i].first + 1 < road[i].second) {
            ans += intersect.sum(road[i].first + 1, road[i].second - 1);
        }
        intersect.update(road[i].first, -1);
        intersect.update(road[i].second, 1);
    }

    cout << ans / 2;
}