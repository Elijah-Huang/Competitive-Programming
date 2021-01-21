#include<bits/stdc++.h>
using namespace std;

struct seg_tree {

    int n;
    int null = -(1 << 30);
    vector<int> t, lazy_add, lazy_assign;

    seg_tree(int sz, int element = 0) {
        n = sz;
        t.resize(4 * n);
        lazy_add.resize(4 * n, null);
        lazy_assign.resize(4 * n, null);
        vector<int> a(n, element);
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

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    int mx(int l, int r) {
        return mx(l, r, 1, 0, n - 1);
    }
    int mx(int l, int r, int v, int tl, int tr) {
        if (tr < l or r < tl) {
            return 0;
        }

        propagate(v, tl, tr);

        if (l <= tl and tr <= r) {
            return t[v];
        }

        int tm = (tl + tr) / 2;
        return max(mx(l, r, 2 * v, tl, tm), mx(l, r, 2 * v + 1, tm + 1, tr));
    }
};

const int maxn = 1e5, mx_w = 1e6;
int n, k;
int ans = 0;

struct event {
    int x, y1, y2, g;
};
vector<event> events;

seg_tree st(2 * mx_w + 1, 0);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("lazy.in","r",stdin); freopen("lazy.out","w",stdout);
    
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int g, x, y;
        cin >> g >> x >> y;
        events.push_back({ x + y - k, x - (y + k) + mx_w, x - (y - k) + mx_w, g });
        events.push_back({ x + y + k + 1, x - (y + k) + mx_w, x - (y - k) + mx_w, -g });
    }
    
    sort(events.begin(), events.end(), [&](const event& a, const event& b) {return a.x < b.x; });

    for (auto& e: events) {
        st.range_add(e.y1, e.y2, e.g);
        if (e.g > 0) {
            ans = max(ans, st.mx(0, 2 * mx_w));
        }
    }

    cout << ans << '\n';
}