#include<bits/stdc++.h>
using namespace std;

int n;
set<vector<int>> moves;
int alice = 0, bob = 0;
string order;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;

	char curr_player = 'A';
	for (int i = 0; i < 2*n*n - 2*n; i++) {
		order += curr_player;

		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

		if (x1 == x2) {
			if (y1 > y2) {
				swap(x1, x2);
				swap(y1, y2);
			}

			int completed = 0;
			if (moves.count({ x1 - 1,y2,x1,y2 }) and
				moves.count({ x1 - 1,y1,x1,y1 }) and
				moves.count({ x1 - 1,y1,x1 - 1,y2 })) {
				completed++;
			}
			if (moves.count({ x1,y2,x1+1,y2 }) and
				moves.count({ x1,y1,x1+1,y1 }) and
				moves.count({ x1 + 1,y1,x1 +1,y2 })) {
				completed++;
			}

			if (curr_player == 'A') {
				alice += completed;
			}
			else {
				bob += completed;
			}

			if (not completed) {
				if (curr_player == 'A') {
					curr_player = 'B';
				}
				else {
					curr_player = 'A';
				}
			}
		}
		else {
			if (x1 > x2) {
				swap(x1, x2);
				swap(y1, y2);
			}

			int completed = 0;
			if (moves.count({ x1,y1-1,x2,y1-1 }) and
				moves.count({ x1,y1-1,x1,y1 }) and
				moves.count({ x2,y1-1,x2,y1 })) {
				completed++;
			}
			if (moves.count({ x1,y1 + 1,x2,y1+1 }) and
				moves.count({ x1,y1 ,x1,y1+1 }) and
				moves.count({ x2,y1,x2,y1+1 })) {
				completed++;
			}

			if (curr_player == 'A') {
				alice += completed;
			}
			else {
				bob += completed;
			}

			if (not completed) {
				if (curr_player == 'A') {
					curr_player = 'B';
				}
				else {
					curr_player = 'A';
				}
			}
		}

		moves.insert({ x1,y1,x2,y2 });
	}

	cout << order << '\n';
	cout << alice << ' ' << bob << '\n';
}