#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    srand(stoi(argv[1]));
    int n = stoi(argv[2]);
    int m = stoi(argv[3]);
    int k = stoi(argv[4]);

    if (m < n || m > n * (n - 1) / 2 || k > n) {
        cout << "bad\n";
        return 0;
    }

    set<pair<int, int>> s;
    vector<array<int, 3>> edge;

    for (int i = 2; i <= n; i++) {
        int p = rand() % (i - 1) + 1;
        s.insert({ p, i });
        edge.push_back({ p, i, rand() });
    }

    int left = m - (n - 1);

    while (left) {
        int a, b;
        a = rand() % n + 1;
        b = rand() % n + 1;
        if (a > b) swap(a, b);
        if (s.count({ a, b })) {
            continue;
        }

        s.insert({ a, b });
        edge.push_back({ a, b, rand() });
        left--;
    }

    set<int> picked;
    while ((int)(picked.size()) < k) {
        int p = rand() % n + 1;
        picked.insert(p);
    }

    cout << n << ' ' << k << ' ';
    for (int x : picked) {
        cout << x << ' ';
    }
    cout << '\n';
    for (auto [a, b, c] : edge) {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}