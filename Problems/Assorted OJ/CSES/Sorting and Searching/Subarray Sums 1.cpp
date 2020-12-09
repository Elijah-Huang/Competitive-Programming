#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x;

    map<long long, int> mp = { {0,1} };
    long long curr = 0;
    long long ans = 0;
    while (n--) {
        int a; cin >> a;
        curr += a;
        ans += mp[curr-x];
        mp[curr]++;
    }

    cout << ans;
}