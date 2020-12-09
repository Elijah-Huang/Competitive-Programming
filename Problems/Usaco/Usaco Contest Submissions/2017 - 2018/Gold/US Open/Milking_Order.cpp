#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int n, m;
vector<vector<int>> conditions(2e5);

vector<int> min_topsort(int len) {
	vector<unordered_set<int>> adj(n);
	vector<unordered_set<int>> radj(n);
	vector<int> top_sort;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < len; i++) {
		for (int j = 1; j < conditions[i].size(); j++) {
			adj[conditions[i][j]].insert(conditions[i][j - 1]);
			radj[conditions[i][j - 1]].insert(conditions[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (adj[i].size() == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int mn = pq.top(); pq.pop();
		top_sort.push_back(mn);
		for (auto neighbor : radj[mn]) {
			adj[neighbor].erase(mn);
			if (adj[neighbor].size() == 0) {
				pq.push(neighbor);
			}
		}
	}

	if (top_sort.size() == n) {
		return top_sort;
	}
	else {
		return vector<int>(0);
	}
}

bool topsort2(int len) {
	vector<vector<int>> adj(n);
	vector<int> top_sort(n);
	int idx = 0;
	vector<bool> visited(n);
	for (int i = 0; i < len; i++) {
		for (int j = 1; j < conditions[i].size(); j++) {
			adj[conditions[i][j]].push_back(conditions[i][j - 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			stack<int> s({ i });
			while (!s.empty()) {
				int curr = s.top();
				if (!visited[curr]) {
					visited[curr] = 1;
					for (auto neighbor : adj[curr]) {
						if (!visited[neighbor]) {
							s.push(neighbor);
						}
					}
				}
				else {
					s.pop();
					top_sort[curr] = idx;
					idx++;
				}
			}
		}
	}
	
	bool no_cycle = true;
	for (int i = 0; i < n; i++) {
		for (auto neighbor : adj[i]) {
			if (top_sort[neighbor] > top_sort[i]) {
				no_cycle = false;
				goto a;
			}
		}
	}
a:
	return no_cycle;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("milkorder.in", "r", stdin); freopen("milkorder.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int amt; cin >> amt;
		while (amt--) {
			int a; cin >> a; a--;
			conditions[i].push_back(a);
		}
	}

	int l = 0; int r = m;
	while (l != r) {
		int m2 = (l + r + 1) / 2;
		if (topsort2(m2)) {
			l = m2;
		}
		else {
			r = m2 - 1;
		}
	}

	vector<int> lexicographical_small = min_topsort(l);
	for (int i = 0; i < n; i++){
		cout << lexicographical_small[i] + 1 << ((i < n - 1) ? ' ' : '\n');
	}
}