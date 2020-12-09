#include<bits/stdc++.h>
using namespace std;

int start[5001][5001];
int dp[5001][5001];

int main() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    int mx = 0;

    int lst = -1e6;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            start[i][j] = lst;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                if (4 * (dp[i - 1][j - 1] + 1) - (i + j - start[i - 1][j - 1]) < 0) {
                    dp[i][j] = 1;
                    start[i][j] = i + j - 2;
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    start[i][j] = start[i - 1][j - 1];
                }
            }
            else {
                int first = 4 * (dp[i - 1][j]) - (i + j - start[i - 1][j]);
                int second = 4 * (dp[i][j - 1]) - (i + j - start[i][j - 1]);
                if (first > second) {
                    if (first < 0) {
                        dp[i][j] = lst;
                        start[i][j] = i + j - 2;
                    }
                    else {
                        dp[i][j] = dp[i - 1][j];
                        start[i][j] = start[i - 1][j];
                    }
                }
                else {
                    if (second < 0) {
                        dp[i][j] = lst;
                        start[i][j] = i + j - 2;
                    }
                    else {
                        dp[i][j] = dp[i][j - 1];
                        start[i][j] = start[i][j - 1];
                    }
                }
            }

            mx = max(mx, 4 * (dp[i][j]) - (i + j - start[i][j]));
        }
    }

    cout << mx;
}
