#include<bits/stdc++.h>
using namespace std;

void total_people(long long curr, vector<long long>& people, vector<long long>& subtree_people,
	vector<vector<long long>>& adj, vector<int>& parent) {
	for (auto neighbor : adj[curr]) {
		if (parent[curr] != neighbor) {
			parent[neighbor] = curr;
			total_people(neighbor, people, subtree_people, adj, parent);
		}
	}
	subtree_people[curr] = people[curr];
	for (auto neighbor : adj[curr]) {
		subtree_people[curr] += subtree_people[neighbor];
	}
}
/*
void total_unhappy(long long curr, vector<long long>& req_unhappy, vector<long long>& subtree_unhappy,
	vector<vector<long long>>& adj, vector<bool>& visited) {
	visited[curr] = 1;
	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor]) {
			total_people(neighbor, req_unhappy, subtree_unhappy, adj, visited);
		}
	}
	subtree_unhappy[curr] = req_unhappy[curr];
	for (auto neighbor : adj[curr]) {
		subtree_unhappy[curr] += subtree_unhappy[neighbor];
	}
} 
*/

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long t;
	cin >> t;
	while (t--) {
		long long n, m;
		cin >> n >> m;
		vector<long long> people(n);
		vector<long long> subtree_people(n);
		vector<long long> happiness(n);
		vector<long long> req_unhappy(n);
		vector<long long> subtree_unhappy(n);
		vector<vector<long long>> adj(n);
		for (long long i = 0; i < n; i++) {
			cin >> people[i];
		}
		for (long long i = 0; i < n; i++) {
			cin >> happiness[i];
		}
		for (long long i = 0; i < n - 1; i++) {
			long long u, v;
			cin >> u >> v;
			u--;
			v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> parent(n);
		total_people(0, people, subtree_people, adj, parent);
		bool fail = false;
		for (long long i = 0; i < n; i++) {
			if (abs(happiness[i]) > subtree_people[i]) {
				fail = true;
				break;
			}
			if ((subtree_people[i] - happiness[i]) % 2 != 0) {
				fail = true;
				break;
			}
		}
		if (fail) {
			cout << "NO\n";
		}
		else {
			for (long long i = 0; i < n; i++) {
				req_unhappy[i] = (subtree_people[i] - happiness[i]) / 2;
			}
			//vector<bool> visited(n);
			//total_unhappy(0, req_unhappy, subtree_unhappy, adj, visited);
			bool fail = false;
			for (long long i = 0; i < n; i++) {
				long long sub_unhappy = 0;
				for (auto neighbor : adj[i]) {
					if (parent[i] != neighbor) {
						sub_unhappy += req_unhappy[neighbor];
					}
				}
				if (sub_unhappy < req_unhappy[i] - people[i]) {
					fail = true;
					break;
				}
			}
			cout << (fail ? "NO\n" : "YES\n");
		}
	}
}