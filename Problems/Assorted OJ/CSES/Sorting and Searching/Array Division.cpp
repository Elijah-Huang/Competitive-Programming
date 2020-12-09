#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    long long l = 0, r = 1ll << 50;
    while (l != r) {
        long long m = (l + r) / 2;

        int j = 0;
        for (int i = 0; i < k; i++) {
            long long curr = m;
            while (j < n and curr >= x[j]) {
                curr -= x[j];
                j++;
            }
        }

        if (j == n) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
    
    cout << l;
}