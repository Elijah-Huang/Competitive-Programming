// O(nlogn) precomputation and memory, but O(1) range queries (here for min)
// no updates!
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int n;
int a[maxn];
int st[maxn][30];
int lo2[maxn];

void precompute_sparse_table() {
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; j < 30; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    lo2[1] = 0;
    for (int i = 2; i <= n; i++) {
        lo2[i] = lo2[i / 2] + 1;
    }
}

int rmin(int l, int r) {
    int d = lo2[r - l + 1];
    return min(st[l][d], st[r - (1 << d) + 1][d]);
}