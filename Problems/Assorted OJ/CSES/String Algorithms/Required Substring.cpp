#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int pf[100];
int dp[1001][101];
long long pow_26[1000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s2; cin >> s2;
    int m = s2.length();
    s2.push_back('%');
    vector<int> s;
    for (int i = 0; i < s2.length(); i++) {
        s.push_back(int(s2[i]));
    }

    for (int i = 1; i < m; i++) {
        int l = pf[i - 1];
        while (l != 0 and s[l] != s[i]) {
            l = pf[l - 1];
        }
        pf[i] = l + (s[l] == s[i]);
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 65; k < 91; k++) {
                int l = j;
                while (l != 0 and s[l] != k) {
                    l = pf[l - 1];
                }
                l += (s[l] == k);
                dp[i + 1][l] = (dp[i + 1][l] + dp[i][j]) % mod;
            }
        }
    }

    long long curr = 1;
    for (int i = 0; i < 1000; i++) {
        pow_26[i] = curr;
        curr = (curr * 26) % mod;
    }

    int ans = 0;
    for (int i = m; i <= n; i++) {
        ans = (ans + (dp[i][m] * pow_26[n - i]) % mod) % mod;
    }
    
    cout << ans;
}