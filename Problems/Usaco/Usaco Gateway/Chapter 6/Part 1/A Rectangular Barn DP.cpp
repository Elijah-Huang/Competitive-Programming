/*
ID: elijahj1
TASK: rectbarn
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("rectbarn.in", "r", stdin); freopen("rectbarn.out", "w", stdout);
    int best_area = 0;
    int r, c, p; cin >> r >> c >> p;
    vector<vector<int>> points(r + 1);
    vector<int> active_damaged(c + 1);
    vector<int> furthest_left(c + 1), furthest_right(c + 1, c + 1);
    while (p--) {
        int x, y; cin >> x >> y;
        points[x].push_back(y);
    }

    for (int max_x = 1; max_x <= r; max_x++) {
        int max_l = 0, min_r = c + 1;
        vector<bool> filled(c + 1);

        for (auto y : points[max_x]) {
            filled[y] = 1;
            active_damaged[y] = max_x;
        }

        for (int y = 1; y <= c; y++) {
            if (filled[y]) {
                max_l = y;
                furthest_left[y] = 0;
            }
            else {
                furthest_left[y] = max(furthest_left[y], max_l);
            }

        }
        for (int y = c; y >= 1; y--) {
            if (filled[y]) {
                min_r = y;
                furthest_right[y] = c + 1;
            }
            else {
                furthest_right[y] = min(furthest_right[y], min_r);
            }
        }
        
        for (int y = 1; y <= c; y++) {
            if (!filled[y]) {
                best_area = max(best_area, (max_x - active_damaged[y]) * (furthest_right[y] - furthest_left[y] - 1));
            }
        }
    }

    cout << best_area << '\n';
}