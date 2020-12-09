#include<bits/stdc++.h>
using namespace std;

int n, m, q;
const int maxn = 1e5 + 1;
int back[maxn], cycle[maxn], idx[maxn];
bool on_path[maxn];
vector<int> path;
vector<vector<int>> cycles(1);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("shufflegold.in", "r", stdin); freopen("shufflegold.out","w",stdout);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		back[a - 1] = i;
	}

	int curr = 0;
	do {
		curr = back[curr];
		path.push_back(curr);
		on_path[curr] = 1;
		idx[curr] = path.size() - 1;
	} while (curr != m);

	for (int i = 1; i <= m; i++) {
		if (!on_path[i] and cycle[i] == 0) {
			int start = i, curr = start;
			cycles.resize(cycles.size() + 1);
			do {
				curr = back[curr];
				cycles.back().push_back(curr);                                 
				cycle[curr] = cycles.size() - 1;
				idx[curr] = cycles.back().size() - 1;
			} while (start != curr);
		}
	}

	while (q--) {
		int loc; cin >> loc;
		if (loc <= m - 1) {
			loc = m - loc;
			if (on_path[loc]) {
				int leftover = n - (m - 1);
				if (leftover >= path.size()-1-idx[loc]) {
					cout << m + (leftover - (path.size() - 1 - idx[loc])) << '\n';
				}
				else {
					cout << path[idx[loc] + leftover] << '\n';
				}
			}
			else {
				cout << cycles[cycle[loc]][(idx[loc] + (n - (m - 1))) % cycles[cycle[loc]].size()] << '\n';
			}
		}
		else {
			int leftover = n - (loc - 1);
			if (leftover >= path.size()) {
				cout << m + (leftover - path.size()) << '\n';
			}
			else {
				cout << path[leftover - 1] << '\n';
			}
		}
	}
}