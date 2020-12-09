#include <iostream>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

typedef set<pair<int, int> >::const_iterator iter;

#define MAXN 100000

int tree_size[MAXN];
set<pair<int, int> > E[MAXN];

int compute_subtree_size(int u, int p) {
    int res = 1;
    for (iter i = E[u].begin(); i != E[u].end(); ++i) {
        if (i->first != p) {
            res += compute_subtree_size(i->first, u);
        }
    }
    return tree_size[u] = res;
}

int b_offset;
int c_offset;
pair<int, int> B[MAXN * 2 + 1];
pair<int, int> C[MAXN * 2 + 1];

void count_partials(int u, int p, int w, int mnw, int mxw) {
    if (w == mnw || w == mxw) {
        mnw = min(mnw, w - 1);
        mxw = max(mxw, w + 1);
        C[c_offset + w].second++;
    }
    else {
        C[c_offset + w].first++;
    }
    for (iter i = E[u].begin(); i != E[u].end(); ++i) {
        if (i->first != p) {
            count_partials(i->first, u, w + i->second, mnw, mxw);
        }
    }
}

/* Computes the number of balanced paths in the connected tree containing u. */
long long solve(int u) {
    /* Precompute the subtree size of all rooted subtrees of the tree. */
    int N = compute_subtree_size(u, -1);

    /* Move u down the tree until we find a node that is a separator, having no
     * child subtrees with more than half of the nodes. */
    int p = -1;
    for (;;) {
        bool separator = true;
        for (iter i = E[u].begin(); i != E[u].end(); ++i) {
            int v = i->first;
            if (v != p && tree_size[v] >= N / 2) {
                separator = false;
                p = u;
                u = v;
                break;
            }
        }
        if (separator) break;
    }

    /* We'll use u as the root of our tree.  First compute the number of balanced
     * paths going through u. */
    long long result = 0;

    /* Initialize our count data structure.  We offset the array as nodes with
     * negative partial sums will have a negative index.  B[offset + x].first is
     * the number of nodes processed so far with partial sum x and an intermediate
     * node on the way to root with the same partial sum.  .second is the same but
     * with no intermediate node. */
    b_offset = N;
    fill(B, B + 2 * N + 1, make_pair(0, 0));

    /* The root has partial sum 0 with no intermediate. */
    B[b_offset + 0].second = 1;

    for (iter i = E[u].begin(); i != E[u].end(); ++i) {
        int v = i->first;
        c_offset = tree_size[v];
        fill(C, C + 2 * tree_size[v] + 1, make_pair(0, 0));
        count_partials(v, u, i->second, i->second, i->second);

        for (int w = -tree_size[v]; w <= tree_size[v]; w++) {
            result += (long long)C[c_offset + w].first * B[b_offset - w].first;
            result += (long long)C[c_offset + w].first * B[b_offset - w].second;
            result += (long long)C[c_offset + w].second * B[b_offset - w].first;
        }

        /* Nodes with partial sums of 0 can use the root as an intermediate. */
        result += (long long)C[c_offset + 0].second * (B[b_offset + 0].second - 1);

        for (int w = -tree_size[v]; w <= tree_size[v]; w++) {
            B[b_offset + w].first += C[c_offset + w].first;
            B[b_offset + w].second += C[c_offset + w].second;
        }
    }

    /* Next, cut the edges coming from u and recursively solve the subtrees. */
    for (iter i = E[u].begin(); i != E[u].end(); ++i) {
        int v = i->first;
        E[v].erase(make_pair(u, i->second));
        result += solve(v);
    }

    return result;
}

int main() {
    freopen("yinyang.in", "r", stdin);
    freopen("yinyang.out", "w", stdout);

    /* Input tree. */
    int N; cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        w = w == 0 ? -1 : 1; /* Adjust weight so it's -1/1 instead of 0/1. */

        E[u].insert(make_pair(v, w));
        E[v].insert(make_pair(u, w));
    }

    cout << solve(0) << endl;
    return 0;
}