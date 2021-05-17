#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 69;
long long n, a[N], mn[N], mx[N];

int main() {
    memset(mn, 0x3f, sizeof(mn));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    mn[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            mn[i] = min(mn[i], mn[j] + (a[i] ^ a[j]));
            mx[i] = max(mx[i], mx[j] + (a[i] ^ a[j]));
        }
    }
    cout << mx[n] - mn[n] << '\n';
}