#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
long long pow_2[60];
long long tot_pow[60];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    pow_2[0] = 1;
    for (int i = 1; i < 60; i++) {
        pow_2[i] = pow_2[i - 1] * 2 % mod;
    }

    int t; cin >> t;
    while (t--) {
        int ans = 0;
        memset(tot_pow, 0, sizeof(tot_pow));
        int n; cin >> n;
        vector<long long> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 60; j++) {
                if (x[i] & (1ll << j)) {
                    tot_pow[j] += 1;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            long long tot_and = 0, tot_or = 0;
            for (int j = 0; j < 60; j++) {
                if (x[i] & (1ll << j)) {
                    tot_and = (tot_and + pow_2[j] * tot_pow[j]) % mod;
                    tot_or = (tot_or + pow_2[j] * n) % mod;
                }
                else {
                    tot_or = (tot_or + pow_2[j] * tot_pow[j]) % mod;
                }
            }

            ans = (ans + tot_and * tot_or) % mod;
        }
                        
        cout << ans << '\n';
    }
}