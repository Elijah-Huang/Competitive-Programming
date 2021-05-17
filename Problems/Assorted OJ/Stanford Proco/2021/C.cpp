#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 69;
int s, n, q, a[N], cnt[N];
set<int> cmp;
map<int, int> mp;
map<int, int> inv_mp;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cmp.insert(a[i]);
    }
    int c = 0;
    for (int i : cmp) {
        mp[i] = c;
        inv_mp[c] = i;
        c++;
    }
    for (int i = 0; i < n; ++i) {
        //cout << a[i] << " " <<  mp[a[i]] << '\n';
        ++cnt[mp[a[i]]];
    }
    for (int i = 1; i < n; ++i) {
        cnt[i] += cnt[i - 1];
        //cout << i << " " << cnt[i] << '\n';
    }
    cin >> q;
    while (q--) {
        int x; cin >> x;

        int i = upper_bound(cnt, cnt + n, x) - cnt;

        if (i == n) {
            cout << s << '\n'; 
        }
        else {
            cout << inv_mp[i] - 1 << '\n';
        }
    }
}