#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 1;
int n, m, q;
int friendship[maxn];
vector<pair<int, int>> friends;
bool visited[maxn];
bool original[maxn];
vector<int> adj[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m >> q;

	visited[1] = original[1] = 1;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		
		original[a] = 1;
		friendship[a] = b;
		pq.push({ b,a });
	}

	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	
	while (!pq.empty()) {
		auto curr = pq.top(); pq.pop();
		
		int d = curr.first;
		int c = curr.second;

		if (!visited[c]) {
			visited[c] = 1;
			friends.push_back({ d,c });

			int new_d = d / 2;
			if (new_d) {
				for (auto ne : adj[c]) {
					if (!original[ne] and friendship[ne] < new_d) {
						friendship[ne] = new_d;
						pq.push({ new_d,ne });
					}
				}
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (!visited[i]) {
			friends.push_back({ 0,i });
		}
	}

	sort(friends.begin(), friends.end(), 
		[&](pair<int, int>& a, pair<int, int>& b) {if (a.first == b.first) { return a.second < b.second; } return a.first > b.first; });

	for (auto i : friends) {
		cout << i.second << ' ' << i.first << '\n';
	}
}