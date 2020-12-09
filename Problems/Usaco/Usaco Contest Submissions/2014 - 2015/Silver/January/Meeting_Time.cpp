#include<bits/stdc++.h>
using namespace std;

struct edge {
	int v, t;
};

vector<edge> adj[2][100];
bool dp[2][100][10001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("meeting.in", "r", stdin); freopen("meeting.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, t1, t2; cin >> u >> v >> t1 >> t2; u--; v--;
		adj[0][u].push_back({ v, t1 });
		adj[1][u].push_back({ v, t2 });
	}
	
	dp[0][0][0] = 1;
	dp[1][0][0] = 1;
	for (int person = 0; person < 2; person++) {
		for (int loc = 0; loc < n - 1; loc++) {
			for (int time = 0; time <= 10000; time++) {
				if (dp[person][loc][time]) {
					for (auto neighbor : adj[person][loc]) {
						dp[person][neighbor.v][time + neighbor.t] = 1;
					}
				}
			}
		}
	}

	for (int meet_time = 0; meet_time <= 10000; meet_time++) {
		if (dp[0][n - 1][meet_time] and dp[1][n - 1][meet_time]) {
			cout << meet_time;
			return 0;
		}
	}
	
	cout << "IMPOSSIBLE";	
}