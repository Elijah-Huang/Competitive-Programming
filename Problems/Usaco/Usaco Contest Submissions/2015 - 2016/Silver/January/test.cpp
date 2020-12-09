#include <bits/stdc++.h>
using namespace std;

int n, k; //num bales, cows
int loc[(int)5e4]; //locations of bales

bool test(int r) {
    vector<bool> visited(n);
    int pos = 0; int kk = k;
    while (kk != 0 && pos < n) {
        int i = pos;
        while (i < n && loc[i] - loc[pos] <= 2 * r) {
            visited[i] = 1;
            i++;
        }
        pos = i;
        kk--; //one less cow
    }
    for (int i = 0; i < n; i++)
        if (!visited[i]) return false;
    return true;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("angry.in"); ofstream cout("angry.out");
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int u; cin >> u; u--; loc[i] = u;
    }
    sort(loc, loc + n);
    int l = 0; int r = 1e9;
    int res = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (!test(m)) l = m + 1;
        else {
            r = m - 1;
            res = m;
        }
    }
    cout << res << endl;
    return 0;
}