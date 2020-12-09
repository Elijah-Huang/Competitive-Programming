#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    map<int, int> mp = { {0,1} };
    int curr = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        curr = ((curr + a) % n + n) % n;
        ans += mp[curr];
        mp[curr]++;
    }

    cout << ans;
}