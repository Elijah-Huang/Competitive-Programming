#include<bits/stdc++.h>
using namespace std;

struct seg_tree {

    int n;
    vector<long long> t;

    seg_tree() {}
    seg_tree(int sz) {
        n = sz;
        t.resize(4 * n, 1e9);
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
                assign(idx, new_val, 2 * v, tl, tm);
            }
            else {
                assign(idx, new_val, 2 * v + 1, tm + 1, tr);
            }

            t[v] = min(t[2 * v], t[2 * v + 1]);
        }
    }

    int mn(int l, int r) {
        return mn(l, r, 1, 0, n - 1);
    }
    int mn(int l, int r, int v, int tl, int tr) {
        if (tr < l or r < tl) {
            return 1e9;
        }

        if (l <= tl and tr <= r) {
            return t[v];
        }

        int tm = (tl + tr) / 2;
        return min(mn(l, r, 2 * v, tl, tm), mn(l, r, 2 * v + 1, tm + 1, tr));
    }
};

const int maxn = 3e5;
int n; 
int h[maxn], h2[maxn], dp[maxn];
vector<pair<int,int>> lower, higher;
seg_tree lower_mn(maxn), higher_mn(maxn);
map<int, int> convert;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    memcpy(h2, h, sizeof(h));
    sort(h2, h2 + n);
    for (int i = 0; i < n; i++) {
        convert[h2[i]] = i;
    }

    dp[0] = 0;
    lower.push_back({ h[0], dp[0] });
    lower_mn.assign(convert[h[0]], dp[0]);
    higher.push_back({ h[0], dp[0] });
    higher_mn.assign(convert[h[0]], dp[0]);
    for (int i = 1; i < n; i++) {
        dp[i] = 1 + min({ lower.size() ? lower.back().second : int(1e9), higher.size() ? higher.back().second : int(1e9),
            lower_mn.mn(0,convert[h[i]]), higher_mn.mn(convert[h[i]], maxn) });

        while (!lower.empty() and lower.back().first <= h[i]) {
            lower_mn.assign(convert[lower.back().first], 1e9);
            lower.pop_back();
        }

        lower.push_back({ h[i], dp[i] });
        lower_mn.assign(convert[h[i]], dp[i]);

        while (!higher.empty() and higher.back().first >= h[i]) {
            higher_mn.assign(convert[higher.back().first], 1e9);
            higher.pop_back();
        }

        higher.push_back({ h[i],dp[i] });
        higher_mn.assign(convert[h[i]], dp[i]);
    }

    cout << dp[n - 1];
}