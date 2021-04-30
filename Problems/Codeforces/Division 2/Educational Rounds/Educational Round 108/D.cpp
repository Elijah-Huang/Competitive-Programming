#include<bits/stdc++.h>
using namespace std;

const int maxn = 5001;
int n;
long long mx = 0;
long long a[maxn], b[maxn], pprod[maxn], sprod[maxn];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    pprod[0] = a[0] * b[0];
    for (int i = 1; i < n; i++) {
        pprod[i] = pprod[i - 1] + a[i] * b[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        sprod[i] = sprod[i + 1] + a[i] * b[i];
    }

    for (int lmidorg = 0; lmidorg < n; lmidorg++) {
        for (int rmidorg = lmidorg; rmidorg < n and rmidorg < lmidorg + 2; rmidorg++) {
            int lmid = lmidorg;
            int rmid = rmidorg;

            long long curr_prod = a[lmid] * b[rmid];
            if (rmid > lmid) {
                curr_prod += a[rmid] * b[lmid];
            }

            mx = max(mx, curr_prod + pprod[(lmid - 1 + n + 1) % (n + 1)] + sprod[rmid + 1]);
            
            lmid--;
            rmid++;

            while (lmid >= 0 and rmid < n) {
                curr_prod += a[rmid] * b[lmid] + a[lmid] * b[rmid];

                mx = max(mx, curr_prod + pprod[(lmid - 1 + n + 1) % (n + 1)] + sprod[rmid + 1]);

                lmid--;
                rmid++;
            }
        }
    }

    cout << mx;
}

