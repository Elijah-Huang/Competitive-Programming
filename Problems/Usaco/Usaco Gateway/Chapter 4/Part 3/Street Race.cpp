/*
ID: elijahj1
TASK: race3
LANG: C++14
*/
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
void dfs(int curr, int& p, vector<int> adj[], unordered_set<int>& visited) {
	visited.insert(curr);
	for (auto neighbor : adj[curr]) {
		if (neighbor != p and visited.count(neighbor) == 0) {
			dfs(neighbor, p, adj, visited);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("race3.in", "r", stdin); freopen("race3.out", "w", stdout);
	vector<int> adj[50];
	int point = 0;
	int curr = 0;
	while (curr != -1) {
		cin >> curr;
		if (curr >= 0) {
			adj[point].push_back(curr);
		}
		else {
			point++;
		}
	}
	point--;
	vector<int> unavoidable, split;
	for (int p = 1; p < point -1; p++) {
		unordered_set<int> visited;
		dfs(0, p, adj, visited);
		if (visited.count(point - 1) == 0) {
			unavoidable.push_back(p);
			bool splitable = true;
			for (int i = 1; i < point - 1; i++) {
				if (!splitable) {
					break;
				}
				if (visited.count(i) == 0) {
					for (auto neighbor : adj[i]) {
						if (visited.count(neighbor)) {
							splitable = false;
							break;
						}
					}
				}
			}
			if (splitable) {
				split.push_back(p);
			}
		}
	}
	cout << unavoidable.size();
	for (int i = 0; i < unavoidable.size(); i++) {
		cout << ' ' << unavoidable[i];
	}
	cout << '\n';
	cout << split.size();
	for (int i = 0; i < split.size(); i++) {
		cout << ' ' << split[i];
	}
	cout << '\n';

}