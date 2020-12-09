#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x;
	vector<int> a(n);
    map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
    
    for (int i = n-1; i >= 0; i--) {
        mp[a[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        mp[a[i]].pop_back();
        if (mp[a[i]].empty()) {
            mp.erase(a[i]);
        }
        for (int j = 0; j < i; j++) {
            if (mp.count(x - a[i] - a[j])) {
                cout << i + 1 << ' ' << j + 1 << ' ' << mp[x - a[i] - a[j]].back() + 1;
                return 0;
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}