/*
ID: elijahj1
LANG: C++
TASK: ariprog
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;

int N, M;
bool bisquare[125001];
vector<pair<int, int> > ans;

bool cmp(const pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    freopen("ariprog.in", "r", stdin); freopen("ariprog.out", "w", stdout);
    cin >> N >> M;
    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= M; ++j) {
            int p_sq = i * i;
            int q_sq = j * j;
            bisquare[p_sq + q_sq] = 1;
        }
    }
    for (int a = 0; a <= 125000; ++a) {
        if (bisquare[a]) {
            int b;
            int max_check = (125000 - a) / N;
            for (int i = a + 1; i <= a + max_check; ++i) {
                if (bisquare[i]) {
                    b = i - a;
                    int x = a + b;
                    bool ok = 1;
                    for (int cnt = 2; cnt < N; ++cnt) {
                        x += b;
                        if (x > 125000) {
                            ok = 0;
                            break;
                        }
                        if (!bisquare[x]) {
                            ok = 0;
                            break;
                        }
                    }
                    if (ok)
                        ans.pb({ a,b });
                }
            }
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    if ((int)ans.size() == 0) {
        cout << "NONE" << endl;
        return 0;
    }
    for (auto u : ans) {
        cout << u.first << " " << u.second << endl;
    }
    return 0;
}