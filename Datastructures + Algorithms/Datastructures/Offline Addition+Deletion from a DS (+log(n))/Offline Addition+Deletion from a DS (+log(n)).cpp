// current implementation solves the dynamic connectivity problem 
// curr ans = (val)^(n - #comps) % mod;
// q*log^2(q)
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1, mod = 1e9 + 7;
long long n, m, q, val;
map<pair<int, int>, int> curr_edges;
int parent[maxn];
vector<int> sizes(maxn, 1);
long long ans[maxn];
long long val_inv;
long long curr_ans = 1;

// store previous state for rollbacks
vector<pair<int, int>> events;

int find_set(int v) {
    if (parent[v] == v) {
        return v;
    }
    // I don't wanna save this for rollback extra log(n) prob fine anyway
    //return parent[v] = find_set(parent[v]);
    return find_set(parent[v]);
}

// add event
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizes[a] < sizes[b]) {
            swap(a, b);
        }
        curr_ans = (val * curr_ans) % mod;
        events.push_back({ a, b });

        parent[b] = a;
        sizes[a] += sizes[b];
    }
    else {
        events.push_back({ -1,-1 });
    }
}

// rollback event
void split_sets() {
    int a, b;
    tie(a, b) = events.back(); events.pop_back();
    if (a != -1) {
        parent[b] = b;
        sizes[a] -= sizes[b];
        curr_ans = (curr_ans * val_inv) % mod;
    }
}

// answers offline queries about the structure of a datastructure after 
// adding and removing elements with an extra log(n) factor via a seg tree + dfs
struct offline_add_and_remove {

    int n;
    pair<int, int> e;
    vector<vector<pair<int, int>>> t;

    offline_add_and_remove() {}
    offline_add_and_remove(int sz) {
        n = sz;
        t.resize(4 * n);
    }

    // events are of the form:
    // l, query when this element is added,
    // r, last query where this element still exists
    // e, the event/ element
    void add_event(int l, int r, pair<int, int> e) {
        this->e = e;
        add_event(l, r, 1, 0, n - 1);
    }
    void add_event(int l, int r, int v, int tl, int tr) {
        if (tr < l or r < tl) {
            return;
        }

        if (l <= tl and tr <= r) {
            // store event for answer_queries() later
            t[v].push_back(e);
            return;
        }

        int tm = (tl + tr) / 2;
        add_event(l, r, 2 * v, tl, tm);
        add_event(l, r, 2 * v + 1, tm + 1, tr);
    }

    // answers the queries via dfs, adding, and rollbacking
    // ans[i] is the answer to the ith query
    void answer_queries() {
        answer_queries(1, 0, n - 1);
    }
    void answer_queries(int v, int tl, int tr) {
        for (auto& e : t[v]) {
            // add event
            union_sets(e.first, e.second);
        }

        if (tl == tr) {
            ans[tl] = curr_ans;
        }
        else {
            int tm = (tl + tr) / 2;
            answer_queries(2 * v, tl, tm);
            answer_queries(2 * v + 1, tm + 1, tr);
        }

        for (auto& e : t[v]) {
            // remove event
            split_sets();
        }
    }
};

long long modexp(long long b, long long exp) {
    b %= mod;
    long long ret = 1;
    while (exp) {
        if (exp & 1) {
            ret = (ret * b) % mod;
        }

        b = (b * b) % mod;
        exp >>= 1;
    }

    return ret;
}

offline_add_and_remove ofd;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q >> val;

    iota(parent, parent + n + 1, 0);

    val = (val + 1) % mod;
    val_inv = modexp(val, mod - 2);

    ofd = offline_add_and_remove(q + 1);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        curr_edges[{u, v}] = 0;
    }
    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        if (curr_edges.count({ u,v })) {
            ofd.add_event(curr_edges[{u, v}], i - 1, { u,v });
            curr_edges.erase({ u,v });
        }
        else {
            curr_edges[{u, v}] = i;
        }
    }
    for (auto& e : curr_edges) {
        ofd.add_event(e.second, q, e.first);
    }

    ofd.answer_queries();

    for (int i = 0; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}