#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct seg_tree {

    int n;
    vector<long long> t;

    seg_tree() {}
    seg_tree(vector<int>& a) {
        n = a.size();
        t.resize(4 * n);
        build(a);
    }

    void build(vector<int>& a) {
        build(a, 1, 0, n - 1);
    }
    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    long long sum(int l, int r) {
        return sum(l, r, 1, 0, n - 1);
    }
    long long sum(int l, int r, int v, int tl, int tr) {
        if (l > r)
            return 0ll;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(l, min(r, tm), v * 2, tl, tm)
            + sum(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
    }

    void update(int pos, long long new_val) {
        update(pos, new_val, 1, 0, n - 1);
    }
    void update(int pos, long long new_val, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = new_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(pos, new_val, v * 2, tl, tm);
            else
                update(pos, new_val, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void add(int pos, long long added_val) {
        add(pos, added_val, 1, 0, n - 1);
    }
    void add(int pos, long long added_val, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] += added_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                add(pos, added_val, v * 2, tl, tm);
            else
                add(pos, added_val, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("hopscotch.in", "r", stdin); freopen("hopscotch.out", "w", stdout);
	int r, c, k; cin >> r >> c >> k;
	vector<vector<int>> grid(r, vector<int>(c));
	vector<vector<int>> dp(r, vector<int>(c));
    vector<int> col_prefix(c);
    unordered_map<int, vector<int>> columns;
    unordered_map<int, seg_tree> seg_trees;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            if (columns[grid[i][j]].size() == 0 or columns[grid[i][j]].back() != j) {
                columns[grid[i][j]].push_back(j);
            }
        }
    }

    for (auto& c : columns) {
        vector<int> base(c.second.size());
        seg_trees[c.first] = seg_tree(base);
    }

	dp[0][0] = 1;
	const int mod = 1e9 + 7;
	for (int i = 1; i < r; i++) {
		long long curr_tot = 0;
		for (int j = 1; j < c; j++) {
			col_prefix[j - 1] = (col_prefix[j - 1] + dp[i - 1][j - 1]) % mod;
            curr_tot = (curr_tot + col_prefix[j - 1]) % mod;

            int update_col, query_col;
            int l = 0; int r = columns[grid[i - 1][j - 1]].size() - 1;
            while (l != r) {
                int m = (l + r) / 2;
                if (columns[grid[i - 1][j - 1]][m] >= j - 1) {
                    r = m;
                }
                else {
                    l = m + 1;
                }
            }
            update_col = l;
            seg_trees[grid[i - 1][j - 1]].add(update_col, dp[i - 1][j - 1]);

            long long overcount = 0;
            if (j - 1 >= columns[grid[i][j]].back()) {
                query_col = columns[grid[i][j]].size() - 1;
            }
            else {
                int l = 0; int r = columns[grid[i][j]].size() - 1;
                while (l != r) {
                    int m = (l + r) / 2;
                    if (columns[grid[i][j]][m] > j - 1) {
                        r = m;
                    }
                    else {
                        l = m + 1;
                    }
                }
                query_col = --l;
            }
            if (query_col != -1) {
                overcount = seg_trees[grid[i][j]].sum(0, query_col) % mod;
            }

            dp[i][j] = (curr_tot - overcount + mod) % mod;
		}
	}

    cout << dp[r - 1][c - 1] << '\n';
}