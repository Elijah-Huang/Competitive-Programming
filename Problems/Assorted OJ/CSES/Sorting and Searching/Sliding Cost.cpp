#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    multiset<int> first_half, last_half;
    long long f_sz = (k + 1) / 2, l_sz = k / 2;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    long long sum_first = 0, sum_last = 0;
    vector<int> initial(x.begin(), x.begin() + k);
    sort(initial.begin(), initial.end());
    for (int i = 0; i < f_sz; i++) {
        first_half.insert(initial[i]);
        sum_first += initial[i];
    }
    for (int i = f_sz; i < f_sz + l_sz; i++) {
        last_half.insert(initial[i]);
        sum_last += initial[i];
    }

    cout << (f_sz)*(*first_half.rbegin()) - sum_first  + sum_last - (l_sz)*(*first_half.rbegin())<< ' ';
    for (int i = k; i < n; i++) {
        if (first_half.count(x[i - k])) {
            first_half.erase(first_half.find(x[i - k]));
            sum_first -= x[i - k];
        }
        else {
            last_half.erase(last_half.find(x[i - k]));
            sum_last -= x[i - k];
        }
        first_half.insert(x[i]);
        sum_first += x[i];
        if (!last_half.empty()) {
            int val = *last_half.begin();
            first_half.insert(val);
            sum_first += val;
            last_half.erase(val);
            sum_last -= val;
        }
        while (first_half.size() > f_sz) {
            int val = *first_half.rbegin();
            first_half.erase(first_half.find(val));
            sum_first -= val;
            last_half.insert(val);
            sum_last += val;
        }

        cout << (f_sz) * (*first_half.rbegin()) - sum_first + sum_last - (l_sz) * (*first_half.rbegin()) << ' ';
    }
}