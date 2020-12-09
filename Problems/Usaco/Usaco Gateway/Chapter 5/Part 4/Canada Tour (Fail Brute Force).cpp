/*
ID: elijahj1
TASK: tour
LANG: C++14
*/
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
int time1 = 0;
bool west_dfs(int curr, vector<vector<int>>& adj, vector<bool>& visited_east,
	vector<bool>& visited_west, int& start, int& end, int& mx) {
	if (curr == end) {
		mx = max(mx, int(visited_west.size() + visited_east.size()));
		if (visited_west.size() + visited_east.size() == adj.size()) {
			return true;
		}
	}
	visited_west[curr] = 1;
	for (auto neighbor : adj[curr]) {
		if (!visited_east[neighbor] and !visited_west[neighbor]) {
			bool found = west_dfs(neighbor, adj, visited_east, visited_west, start, end, mx);
			if (found) {

			}
		}
	}
	visited_west[curr] = 0;
	return false;
}
bool east_dfs(int curr, vector<vector<int>>& adj, vector<bool>& visited_east,
	vector<bool>& visited_west, int& start, int& end, int& mx) {
	if (curr == end) {
		if (west_dfs(start, adj, visited_east, visited_west, start, end, mx)) {
			return true;
		}
		//cout << (++time1) << '\n';
	}
	visited_east[curr] = 0;
	for (auto neighbor : adj[curr]) {
		if (!visited_east[neighbor]) {
			bool found = east_dfs(neighbor, adj, visited_east, visited_west, start, end, mx);
			if (found) {
				return true;
			}
		}
	}
	visited_east[curr] = 0;
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("tour.in", "r", stdin); freopen("tour.out", "w", stdout);
	int n, ve, mx = 1;
	cin >> n >> ve;
	unordered_map<string, int> name_to_num;
	vector<vector<int>> adj(n);
	vector<bool> visited_east(n), visited_west(n);
	int start = 0, end = n - 1;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		name_to_num[s] = i;
	}
	for (int i = 0; i < ve; i++) {
		string u, v;
		cin >> u >> v;
		cout << u << ' ' << v << '\n';
		if (name_to_num[u] < name_to_num[v]) {
			adj[name_to_num[u]].push_back(name_to_num[v]);
		}
		else {
			adj[name_to_num[v]].push_back(name_to_num[u]);
		}
	}
	east_dfs(start, adj, visited_east, visited_west, start, end, mx);
	cout << mx << '\n';
}