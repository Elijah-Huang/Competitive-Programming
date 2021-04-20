// O(t*n) the graph is shaped like a bunch of directed lines
// (sequence of nodes where each edge points to the next node in the sequence)
// that end in a cycle
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int t, n;
int frien[maxn];
vector<int> frien_of[maxn];
int mx_cycle, sum_lines;
bool visited[maxn];

int dfs(int c) {
	int mx_len = 0;

	for (auto ne : frien_of[c]) {
		if (!visited[ne]) {
			visited[ne] = 1;
			mx_len = max(mx_len, dfs(ne));
		}
	}

	return mx_len + 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cse = 1; cse <= t; cse++) {
		fill(frien_of, frien_of + maxn, vector<int>());
		memset(visited, 0, sizeof(visited));
		mx_cycle = sum_lines = 0;

		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> frien[i];
			frien_of[frien[i]].push_back(i);
		}

		// find disjoint lines
		for (int i = 1; i <= n; i++) {
			if (!visited[i] and frien[frien[i]] == i) {
				visited[i] = visited[frien[i]] = 1;
				// find the two longest directed lines that end at i and frien[i] respectively
				// this line(set of points) satisfies the adjacent BFF condition and thus 
				// any line of this type can be put together to make a circle
				sum_lines += dfs(i) + dfs(frien[i]);
			}
		}
		
		// find cycles
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				visited[i] = 1;
				vector<int> path = { i };
				while (!visited[frien[path.back()]]) {
					path.push_back(frien[path.back()]);
					visited[path.back()] = 1;
				}

				mx_cycle = max(mx_cycle, int(path.end() - find(path.begin(), path.end(), frien[path.back()])));
			}
		}
		

		cout << "Case #" << cse << ": " << max(mx_cycle, sum_lines) << '\n';
	}
}