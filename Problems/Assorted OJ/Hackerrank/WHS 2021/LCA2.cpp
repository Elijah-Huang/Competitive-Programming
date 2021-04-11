#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 1000;
ll n, l, r, p[MX], cnt[MX];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l >> r, --l, --r;
    if (n == 1) {
        cout << min(l+1, r+1);
        return 0;
    }
    int l_lvl = 0, r_lvl = 0, lmx = 0;
    p[0] = 1;
    for (; ; ++lmx) {
        if ((5e18) / n < p[lmx])
            break;
        p[lmx + 1] = p[lmx] * n;
    }
    p[lmx + 1] = 2e18;
    for (int i = 0; i <= lmx; ++i) {
        cnt[i] = p[i] + (i ? cnt[i - 1] : 0);
        //cout << i << " " << cnt[i] << '\n';
    }
    for (; ; ++l_lvl)
        if (l - cnt[l_lvl] < 0)
            break;
    --l_lvl;
    for (; ; ++r_lvl)
        if (r - cnt[r_lvl] < 0)
            break;
    --r_lvl;
    //cout << l_lvl << " " << r_lvl << '\n';
    while (l_lvl < r_lvl) {
        r -= cnt[r_lvl--];
        r /= n;
        r += cnt[r_lvl];
        //cout << "r is now " << r << '\n';
    }
    while (r_lvl < l_lvl) {
        l -= cnt[l_lvl--];
        l /= n;
        l += cnt[l_lvl];
        //cout << "l is now " << l << '\n';
    }
    while (l != r) {
        l -= cnt[l_lvl--];
        l /= n;
        l += cnt[l_lvl];
        r -= cnt[r_lvl--];
        r /= n;
        r += cnt[r_lvl];
        //cout << "r is now " << r << '\n';
        //cout << "l is now " << l << '\n';
    }
    cout << l + 1 << '\n';
}