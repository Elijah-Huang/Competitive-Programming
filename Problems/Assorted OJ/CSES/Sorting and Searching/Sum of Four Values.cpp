#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    gp_hash_table<int, pair<int, int>> mp({}, {}, {}, {}, { 1 << 19 });
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mp.find(x - a[i] - a[j]) != mp.end()) {
                cout << i + 1 << ' ' << j + 1 << ' ' << mp[x - a[i] - a[j]].first + 1 << ' ' << mp[x-a[i]-a[j]].second + 1;
                return 0;
            }
        }

        for (int j = 0; j < i; j++) {
            mp[a[i] + a[j]] = { i,j };
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}