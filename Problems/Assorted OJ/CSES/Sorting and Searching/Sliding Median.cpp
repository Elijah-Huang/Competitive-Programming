#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    multiset<int> first_half, last_half;
    int f_sz = (k + 1) / 2; int l_sz = k / 2;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<int> initial(x.begin(), x.begin() + k);
    sort(initial.begin(), initial.end());
    for (int i = 0; i < f_sz; i++) {
        first_half.insert(initial[i]);
    }
    for (int i = f_sz; i < f_sz + l_sz; i++) {
        last_half.insert(initial[i]);
    }
    
    cout << *first_half.rbegin() << ' ';
    for (int i = k; i < n; i++) {
        if (first_half.count(x[i - k])) {
            first_half.erase(first_half.find(x[i - k]));
        }
        else {
            last_half.erase(last_half.find(x[i - k]));
        }
        first_half.insert(x[i]);
        if (!last_half.empty()) {
            first_half.insert(*last_half.begin());
            last_half.erase(last_half.begin());
        }
        while (first_half.size() > f_sz) {
            int val = *first_half.rbegin();
            first_half.erase(first_half.find(val));
            last_half.insert(val);
        }

        cout << *first_half.rbegin() << ' ';
    }
}