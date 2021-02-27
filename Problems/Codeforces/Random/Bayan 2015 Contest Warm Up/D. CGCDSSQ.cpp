// O(n* log ^ 3(n))
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, q;
int a[maxn];
map<int, long long> pos_gcd;
int st[maxn][20];
int lo2[maxn+1];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void precompute_sparse_table() {
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    lo2[1] = 0;
    for (int i = 2; i <= n; i++) {
        lo2[i] = lo2[i / 2] + 1;
    }
}

int rgcd(int l, int r) {
    int d = lo2[r - l + 1];
    return gcd(st[l][d], st[r - (1 << d) + 1][d]);
}

void precompute_gcds() {
    for (int i = 0; i < n; i++) {
        int curr_l = i;
        while (curr_l < n) {
            int curr_gcd = rgcd(i, curr_l);
            int l = curr_l, r = n - 1;

            while (l != r) {
                int m = (l + r + 1) / 2;
                
                if (rgcd(i, m) == curr_gcd) {
                    l = m;
                }
                else {
                    r = m - 1;
                }
            }

            pos_gcd[curr_gcd] += (r - curr_l + 1);
            curr_l = r + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    precompute_sparse_table();
    precompute_gcds();

    cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << pos_gcd[x] << '\n';
    }
}