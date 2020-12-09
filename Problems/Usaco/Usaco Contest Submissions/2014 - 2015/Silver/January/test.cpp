#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXV 1010

bool vis[MAXV];
pair<long long, int> cost_a2u[MAXV];
pair<long long, int> cost[MAXV][MAXV];

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);

    int A, B, N;
    cin >> A >> B >> N;

    /* Initialize cost matrix to infinity. */
    memset(cost, 0x3F, sizeof(cost));
    for (int i = 0; i < MAXV; i++) {
        cost[i][i] = make_pair(0, 0);
    }

    for (int i = 0; i < N; i++) {
        long long route_cost;
        int route_len;
        cin >> route_cost >> route_len;

        vector<int> route(route_len);
        for (int j = 0; j < route_len; j++) {
            cin >> route[j];

            /* Update the cost from everything before this city to this city. */
            for (int k = 0; k < j; k++) {
                cost[route[k]][route[j]] = min(cost[route[k]][route[j]],
                    make_pair(route_cost, j - k));
            }
        }
    }

    /* Perform Dijkstra without a heap in O(V^2) time. */
    memset(vis, 0, sizeof(vis));
    memset(cost_a2u, 0x3F, sizeof(cost_a2u));
    cost_a2u[A] = make_pair(0, 0);
    for (int i = 0; i < MAXV; i++) {
        /* Find the closest unvisited vertex. */
        int u = -1;
        for (int j = 0; j < MAXV; j++) {
            if (vis[j]) {
                continue;
            }
            else if (u == -1 || cost_a2u[j] < cost_a2u[u]) {
                u = j;
            }
        }

        /* Relax vertex u. */
        vis[u] = true;
        for (int j = 0; j < MAXV; j++) {
            pair<long long, int> rlx = cost_a2u[u];
            rlx.first += cost[u][j].first;
            rlx.second += cost[u][j].second;
            cost_a2u[j] = min(cost_a2u[j], rlx);
        }
    }

    /* Output the cheapest cost and length if possible. */
    if (cost_a2u[B].second <= MAXV) {
        cout << cost_a2u[B].first << ' ' << cost_a2u[B].second << endl;
    }
    else {
        cout << "-1 -1\n";
    }

    return 0;
}