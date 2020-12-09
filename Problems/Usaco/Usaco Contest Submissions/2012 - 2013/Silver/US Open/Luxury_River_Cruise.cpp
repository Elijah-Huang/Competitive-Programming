#include<bits/stdc++.h>
using namespace std;

struct neighbors {
	int l, r;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cruise.in", "r", stdin); freopen("cruise.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<neighbors> adj(n);
	string path;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		adj[i].l = --l;
		adj[i].r = --r;
	}
	for (int i = 0; i < m; i++) {
		char direction;
		cin >> direction;
		path.push_back(direction);
	}

	vector<int> visited_time(n);
	int time = 0;
	int curr = 0;
	while (true) {
		for (int i = 0; i < m; i++) {
			if (path[i] == 'L') {
				curr = adj[curr].l;
			}
			else {
				curr = adj[curr].r;
			}
		}
		if (visited_time[curr]) {
			break;
		}
		visited_time[curr] = ++time;
	}

	int to_go = k - time;
	int cycle_length = time - visited_time[curr] + 1;
	if (to_go <= 0) {
		for (int i = 0; i < n; i++) {
			if (visited_time[i] == k) {
				cout << i + 1;
				break;
			}
		}
	}
	else {
		to_go %= cycle_length;
		int time_at_finish = (to_go - 1 >= 0 ? to_go - 1 : cycle_length - 1) + visited_time[curr];
		for (int i = 0; i < n; i++) {
			if (visited_time[i] == time_at_finish) {
				cout << i + 1;
				break;
			}
		}
	}
}