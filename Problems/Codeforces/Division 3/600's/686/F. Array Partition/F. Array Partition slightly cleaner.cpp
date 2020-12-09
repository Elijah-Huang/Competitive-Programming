#include<bits/stdc++.h>
using namespace std;

int n; 
vector<int> a;
multiset<int> mn;
map<int, int> counts;

bool test(bool reversed = 0) {
    mn.clear();
    counts.clear();
    for (int i = 0; i < n - 1; i++) {
        mn.insert(a[i]);
        counts[a[i]]++;
    }

    int r = n - 1;
    int mx1 = a[0], mx2 = a[n - 1];
    for (int i = 0; i < n - 2; i++) {
        mn.erase(mn.find(a[i]));
        counts[a[i]]--;
        mx1 = max(mx1, a[i]);
        while (i + 1 < r and max(mx2, a[r - 1]) <= mx1) {
            if (a[r - 1] == mx1 and (a[i + 1] < mx1 or counts[mx1] == 1)) {
                break;
            }
            r--;
            mx2 = max(mx2, a[r]);
            mn.erase(mn.find(a[r]));
            counts[a[r]]--;
        }
        if (i + 1 >= r) {
            break;
        }
        if (mx1 == mx2 and mx1 == *mn.begin()) {
            cout << "YES\n";
            if (reversed) {
                cout << n - (i + 1 + mn.size()) << ' ' << mn.size() << ' ' << i + 1  << '\n';
            }
            else {
                cout << i + 1 << ' ' << mn.size() << ' ' << n - (i + 1 + mn.size()) << '\n';
            }
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (!test()) {
            reverse(a.begin(), a.end());
            if (!test(1)) {
                cout << "NO\n";
            }
        }
    }
}