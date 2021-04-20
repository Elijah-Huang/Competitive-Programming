#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

struct seg_tree {

    int n;
    vector<long long> t;

    seg_tree() {}
    seg_tree(int sz, int element = 0) {
        n = sz;
        t.resize(4 * n);
    }

    void assign(int idx, long long new_val) {
        assign(idx, new_val, 1, 0, n - 1);
    }
    void assign(int idx, long long new_val, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = new_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (idx <= tm) {
                assign(idx, new_val, 2 * v, tl, tm);
            }
            else {
                assign(idx, new_val, 2 * v + 1, tm + 1, tr);
            }

            t[v] = gcd(t[2 * v], t[2 * v + 1]);
        }
    }

    long long sum(int l, int r) {
        return sum(l, r, 1, 0, n - 1);
    }
    long long sum(int l, int r, int v, int tl, int tr) {
        if (tr < l or r < tl) {
            return 0ll;
        }

        if (l <= tl and tr <= r) {
            return t[v];
        }

        int tm = (tl + tr) / 2;
        return gcd(sum(l, r, 2 * v, tl, tm), sum(l, r, 2 * v + 1, tm + 1, tr));
    }
};

const int maxn = 5e4 + 1;
int t, n, q;
long long answers[2*maxn];
vector<pair<int,int>> queries[maxn];
vector<pair<int,pair<int,long long>>> adj[maxn];
seg_tree st(2e5 + 1);

void dfs(int c, int p) {
    for (auto [weight, query_idx] : queries[c]) {
        answers[query_idx] = st.sum(0, weight);
    }

    for (auto n : adj[c]) {
        if (n.first == p) continue;
        
        // load, toll
        st.assign(n.second.first, n.second.second);
        dfs(n.first, c);
        st.assign(n.second.first, 0);
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cse = 1; cse <= t; cse++) {
        for (int i = 0; i < maxn; i++) {
            adj[i].clear();
            queries[i].clear();
        }

        cin >> n >> q;

       for (int i = 0; i < n - 1; i++) {
            long long ai;
            int x, y, li;
            cin >> x >> y >> li >> ai;

            adj[x].push_back({ y,{li,ai} });
            adj[y].push_back({ x,{li,ai} });
        }

        for (int i = 0; i < q; i++) {
            int c, w; cin >> c >> w;
            queries[c].push_back({ w,i });
        }

        dfs(1, 0);

        cout << "Case #" << cse << ": ";
        for (int i = 0; i < q; i++) {
            cout << answers[i] << ' ';
        }
        cout << '\n';
	}
}