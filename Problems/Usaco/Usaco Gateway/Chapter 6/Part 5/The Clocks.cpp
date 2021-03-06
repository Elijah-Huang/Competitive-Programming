/*
ID: elijahj1
TASK: clocks
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

struct loc {
	int loc, move, dist;
};

struct loc_cmp {
	bool operator()(const loc& a, const loc& b) const {
		if (a.dist == b.dist) {
			return a.move > b.move;
		}
		else {
			return a.dist > b.dist;
		}
	}
};

struct edge {
	int previous, move, dist = 1 << 20;
};

edge dp[1 << 18];

vector<vector<bool>> moves = {
	{1,1,0,1,1,0,0,0,0},
	{1,1,1,0,0,0,0,0,0},
	{0,1,1,0,1,1,0,0,0},
	{1,0,0,1,0,0,1,0,0},
	{0,1,0,1,1,1,0,1,0},
	{0,0,1,0,0,1,0,0,1},
	{0,0,0,1,1,0,1,1,0},
	{0,0,0,0,0,0,1,1,1},
	{0,0,0,0,1,1,0,1,1}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("clocks.in", "r", stdin); freopen("clocks.out", "w", stdout);
	loc start = { 0, 0, 0 };
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		start.loc += ((a / 3) % 4) * (1 << 2 * (8 - i));
	}

	priority_queue<loc, vector<loc>, loc_cmp> pq;
	pq.push(start);
	dp[start.loc].dist = 0;
	dp[start.loc].previous = -1;
	dp[start.loc].move = 0;
	int  b = 0;
	while (!pq.empty()) {
		loc curr = pq.top(); pq.pop();
		if (curr.dist == dp[curr.loc].dist and curr.move == dp[curr.loc].move) {
			for (int i = 0; i < 9; i++) {
				loc new_loc = { 0, i + 1, curr.dist + 1 };
				int a = curr.loc;
				for (int j = 0; j < 9; j++) {
					new_loc.loc += ((a + moves[i][8 - j]) % 4) * (1 << 2 * j);
					a >>= 2;
				}
				if (new_loc.dist <= dp[new_loc.loc].dist) {
					if (new_loc.dist < dp[new_loc.loc].dist or new_loc.move < dp[new_loc.loc].move) {
						dp[new_loc.loc].dist = new_loc.dist;
						dp[new_loc.loc].move = new_loc.move;
						dp[new_loc.loc].previous = curr.loc;
						pq.push(new_loc);
					}
				}

			}
		}
	}

	vector<int> path;
	int curr = 0;
	while (dp[curr].previous != -1) {
		path.push_back(dp[curr].move);
		curr = dp[curr].previous;
	}
	sort(path.begin(), path.end());
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << (i != path.size() - 1 ? ' ' : '\n');
	}
}
