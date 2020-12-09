#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

int main() {
    freopen("stampede.in", "r", stdin); freopen("stampede.out", "w", stdout);

    int N;
    cin >> N;

    set<int> st;
    vector<pair<int, pair<int, int> > > A;
    for (int i = 0; i < N; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        x *= -r;
        A.push_back(make_pair(y, make_pair(x - r, x)));
        st.insert(x - r);
        st.insert(x);
    }
    sort(A.begin(), A.end());

    int result = 0;
    for (int i = 0; i < A.size(); i++) {
        auto it = st.lower_bound(A[i].second.first);
        auto jt = st.lower_bound(A[i].second.second);
        if (it != jt) {
            ++result;
            st.erase(it, jt);
        }
    }
    cout << result << endl;

    return 0;
}