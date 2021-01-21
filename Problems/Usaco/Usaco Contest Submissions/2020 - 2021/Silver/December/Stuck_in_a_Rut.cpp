#include<bits/stdc++.h>
using namespace std;

struct cow {
	char dir;
	int x, y;
};

struct stop {
	int i, j, t_j, t_i;
};

const int maxn = 1001;
int n, t;
cow cows[maxn];
vector<int> adj[maxn];
vector<stop> stops;
int stopped[maxn];
int blame[maxn];

void dfs(int c){
	for (auto n : adj[c]) {
		if (blame[n] == 0) {
			dfs(n);
		}

		blame[c] += blame[n];
	}

	blame[c] += 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cows[i].dir >> cows[i].x >> cows[i].y;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}

			if (cows[i].dir == cows[j].dir) {
				if (cows[i].dir == 'E') {
					if (cows[i].y == cows[j].y and
						cows[i].x > cows[j].x) {
						stops.push_back({ i, j, cows[i].x - cows[j].x, 1 });
					}
				}
				else {
					if (cows[i].x == cows[j].x and
						cows[i].y > cows[j].y) {
						stops.push_back({ i, j, cows[i].y - cows[j].y, 1 });
					}
				}
			}
			else {
				if (cows[i].dir == 'E') {
					if (cows[i].y > cows[j].y and cows[i].x <= cows[j].x and
						cows[i].y-cows[j].y > cows[j].x - cows[i].x) {
						stops.push_back({ i, j, cows[i].y - cows[j].y, cows[j].x - cows[i].x + 1 });
					}
				}
				else {
					if (cows[i].y <= cows[j].y and cows[i].x > cows[j].x and
						cows[i].x - cows[j].x > cows[j].y - cows[i].y) {
						stops.push_back({ i, j, cows[i].x - cows[j].x, cows[j].y - cows[i].y + 1 });
					}
				}
			}
		}
	}
	
	sort(stops.begin(), stops.end(), [&](const stop& a, const stop& b) {return a.t_j < b.t_j; });

	for (stop& s : stops) {
		if (stopped[s.j]) {
			continue;
		}

		if (stopped[s.i] == 0) {
			adj[s.i].push_back(s.j);
			stopped[s.j] = s.t_j;
		}
		else {
			if (stopped[s.i] >= s.t_i) {
				adj[s.i].push_back(s.j);
				stopped[s.j] = s.t_j;
			}
		}
		
	}

	for (int i = 0; i < n; i++) {
		if (blame[i] == 0) {
			dfs(i);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << blame[i] - 1 << '\n';
	}
}