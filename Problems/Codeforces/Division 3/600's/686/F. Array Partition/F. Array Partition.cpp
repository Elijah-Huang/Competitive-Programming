#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<vector<int>> mx(2, vector<int>(n));
        multiset<int> mn;
        map<int,int> counts;
        bool found = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n - 1; i++) {
            mn.insert(a[i]);
            counts[a[i]]++;
        }
        
        int r = n - 1;
        int mx1 = a[0], mx2 = a[n - 1];
        for (int i = 0; i < n-2; i++) {
            mn.erase(mn.find(a[i]));
            counts[a[i]]--;
            mx1 = max(mx1, a[i]);
            while (i + 1 < r and max(mx2,a[r-1]) <= mx1) {
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
                cout << i + 1 << ' ' << mn.size() << ' ' << n - (i + 1 + mn.size()) << '\n';
                found = true;
                break;
            }
        }

        if (!found) {
            reverse(a.begin(), a.end());
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
                    cout << n - (i + 1 + mn.size()) << ' ' << mn.size() << ' ' << i + 1 << '\n';
                    found = true;
                    break;
                }
            }
        }

        /*
        mx[0][0] = a[0];
        mx[1][n - 1] = a[n - 1];
        for (int i = 1; i < n; i++) {
            mx[0][i] = max(mx[0][i - 1], a[i]);
            mx[1][n - 1 - i] = max(mx[1][n - 1 - i + 1], a[n - 1 - i]);
        }
        
        for (int i = 0; i < n - 2; i++) {
            mn.erase(mn.find(a[i]));
            while (!mn.empty()) {
                if (a[i+mn.size()] > mx[0][i] or mn.count(mx[0][i]) == 1 and a[i+mn.size()] == mx[0][i]){
                    break;
                }
                mn.erase(mn.find(a[i + mn.size()]));
            }
            if (mn.empty()) {
                break;
            }
            if (*mn.begin() == mx[0][i] and mx[1][i + mn.size() + 1] == mx[0][i]) {
                cout << "YES\n";
                cout << i + 1 << ' ' << mn.size() << ' ' << n - mn.size() - (i + 1) << '\n';
                found = true;
                break;
            }
        }
        */
        if (!found) {
            cout << "NO\n";
        }
        
    }
}