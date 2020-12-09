#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
void reroot(vector<vector<int>> &adj_list, int dp[], int dp_final[], unordered_set<int> &visited, int curr) {
	for (int i = 0; i < adj_list[curr].size() - 1; i++) {
		int neighbor = adj_list[curr][i];
		if (not visited.count(neighbor)) {
			visited.insert(neighbor);
			int change_to_child, change_to_root;
			change_to_child = max(0, dp[neighbor]);
			dp[curr] -= change_to_child;
			change_to_root = dp[curr];
			dp[neighbor] += max(0, change_to_root);
			dp_final[neighbor] = dp[neighbor];
			reroot(adj_list, dp, dp_final, visited, neighbor);
			dp[neighbor] -= max(0,change_to_root);
			dp[curr] += change_to_child;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	int a,b,n;
	cin >> n;
	int dp[200001]{}, colors[200001], dp_final[200001];
	vector<vector<int>> adj_list(n+1);
	for (int i = 1; i < n+1; i++) {
		cin >> colors[i];
	}
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	for (int i = 1; i < n + 1; i++) {
		adj_list[i].push_back(0);
	}
	stack<int> s({ 1 });
	unordered_set<int> visited;
	int curr, length, neighbor;
	bool had_neighbor;
	while (s.size()) {
		curr = s.top();
		visited.insert(curr);
		had_neighbor = false;
		length = adj_list[curr].size() - 1;
		for (int i = adj_list[curr][length]; i < length; i++) {
			neighbor = adj_list[curr][i];
			if (not visited.count(neighbor)) {
				s.push(neighbor);
				adj_list[curr][length] = i + 1;
				had_neighbor = true;
				break;
			}
		}
		if (not had_neighbor) {
			if (colors[curr] == 1) {
				dp[curr] = 1;
			}
			else {
				dp[curr] = -1;
			}
			for (int i = 0; i < length; i++) {
				dp[curr] += max(0,dp[adj_list[curr][i]]);
			}
			s.pop();
		}
	}
	dp_final[1] = dp[1];
	visited.clear();
	visited.insert(1);
	reroot(adj_list, dp, dp_final, visited, 1);
	for (int i = 1; i < n + 1; i++) {
		cout << dp_final[i] << " ";
	}
}