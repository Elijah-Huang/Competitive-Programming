#include <bits/stdc++.h>
using namespace std;
using ld = double;
using ll = long long;

int n, k; ld ans;
priority_queue<pair<ld, pair<ll, ll>>> pq;

ld d(ll a, ll b) {
    if (a == 0 and b == 0) {
        return 0;
    }
    return ld(ld(a) / ld(a + b));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        ld here = d(a, b);
        ans += here;
        pq.push({ d(a + 1, b) - here, {a, b} });
    }
    while (k--) {
        ld t = pq.top().first; ll a, b;
        tie(a, b) = pq.top().second;

        pq.pop();
        ans += t, ++a;
        pq.push({ d(a + 1, b) - d(a, b), {a, b} });
    }
    cout << setprecision(12) << fixed << ans << '\n';
}