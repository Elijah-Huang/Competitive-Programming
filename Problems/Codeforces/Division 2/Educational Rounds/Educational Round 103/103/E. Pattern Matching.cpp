#include<bits/stdc++.h>
using namespace std;

const int maxm = 1e5 + 1, maxn = 1e5 + 1;
int n, m, k;
map<string, int> pattern_idx;
string idx_pattern[maxn];
string strings[maxm];
int first_s[maxm];
vector<int> adj[maxn];


bool visited[maxn];
vector<int> order;
int idx_in_order[maxn];
void top_sort(int c) {
	visited[c] = 1;

	for (auto n : adj[c]) {
		if (!visited[n]) {
			top_sort(n);
		}
	}

	order.push_back(c);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		pattern_idx[s] = i;
		idx_pattern[i] = s;
	}

	for (int i = 0; i < m; i++) {
		cin >> strings[i] >> first_s[i];
	}

	for (int i = 0; i < m; i++) {
		bool has_match = false;

		for (int j = 0; j < (1 << k); j++) {
			string match = strings[i];
			for (int b = 0; b < k; b++) {
				if ((j >> b) & 1) {
					match[b] = '_';
				}
			}

			if (match != idx_pattern[first_s[i]] and pattern_idx.count(match)) {
				adj[pattern_idx[match]].push_back(first_s[i]);
			}

			if (match == idx_pattern[first_s[i]]) {
				has_match = true;
			}
		}

		if (!has_match) {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			top_sort(i);
		}
	}

	for (int i = 0; i < n; i++) {
		idx_in_order[order[i]] = i;
	}

	bool cycle = false;
	for (int i = 0; i < n and !cycle; i++) {
		for (auto ne : adj[order[i]]) {
			if (idx_in_order[ne] > i) {
				cycle = true;
				break;
			}
		}
	}

	if (!cycle) {
		cout << "YES\n";
		for (auto i : order) {
			cout << i << ' ';
		}
	}
	else {
		cout << "NO";
	}
}