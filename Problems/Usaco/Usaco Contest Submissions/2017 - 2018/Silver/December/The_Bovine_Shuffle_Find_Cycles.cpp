#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("shuffle.in", "r", stdin); freopen("shuffle.out", "w", stdout);
	int n; cin >> n;
	int total = 0;
	int time[100000]{};
	int adj[100000]{};
	for (int i = 0; i < n; i++) {
		int loc; 
		cin >> loc;
		adj[i] = --loc;
	}
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (!time[i]) {
			time[i] = ++t;
			int start = time[i];
			int curr = i;
			while (!time[adj[curr]]) {
				curr = adj[curr];
				time[curr] = ++t;
			}
			if (start <= time[adj[curr]]) {
				total += time[curr] - time[adj[curr]] + 1;
			}
		}
	}
	cout << total;
}