#include<bits/stdc++.h>
using namespace std;

int vertex = 0;
unordered_map<char, int> children[int(3e5 + 1)];
bool endpoint[int(3e5 + 1)], visited[26], in_path[26];
vector<vector<int>> adj;
vector<int> path;

void insert(string& s) {
	int curr_vertex = 0;
	for (auto& c : s) {
		if (children[curr_vertex].count(c)) {
			curr_vertex = children[curr_vertex][c];
		}
		else {
			children[curr_vertex][c] = ++vertex;
			curr_vertex = vertex;
		}
	}
	endpoint[curr_vertex] = 1;
}

bool check_conditions(int curr) {
	visited[curr] = 1;
	in_path[curr] = 1;
	for (auto& neighbor : adj[curr]) {
		if (!visited[neighbor]) {
			if (!check_conditions(neighbor)) {
				return false;
			}
		}
		else {
			if (in_path[neighbor]) {
				return false;
			}
		}
	}
	in_path[curr] = 0;
	return true;
}

bool can_be_lex_min(string& s) {
	adj = vector<vector<int>>(26);
	memset(visited, 0, sizeof(visited));
	memset(in_path, 0, sizeof(path));
	int curr_vertex = 0;
	for (auto& c : s) {
		if (endpoint[curr_vertex]) {
			return false;
		}
		for (auto& child : children[curr_vertex]) {
			if (child.first != c) {
				adj[child.first-'a'].push_back(c-'a');
			}
		}
		curr_vertex = children[curr_vertex][c];
	}

	for (int i = 0; i < 26; i++) {
		if (!visited[i]) {
			if (!check_conditions(i)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("first.in", "r", stdin); freopen("first.out", "w", stdout);
	int n; cin >> n;
	vector<string> strings(n);
	vector<string> ans;
	for (int i = 0; i < n; i++) {
		cin >> strings[i];
		insert(strings[i]);
	}

	for (auto& s : strings) {
		if (can_be_lex_min(s)) {
			ans.push_back(s);
		}
	}

	cout << ans.size() << '\n';
	for (auto& s : ans) {
		cout << s << '\n';
	}
}