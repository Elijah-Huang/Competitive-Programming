#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    vector<int> nse(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<pair<int,int>> unprocessed;
    for (int i = n-1; i >= 0; i--) {
        while (!unprocessed.empty() and unprocessed.top().first > a[i]) {
            nse[unprocessed.top().second] = i + 1;
            unprocessed.pop();
        }
        unprocessed.push({ a[i], i });
    }

    for (auto i : nse) {
        cout << i << ' ';
    }
}