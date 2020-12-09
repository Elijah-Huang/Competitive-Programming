/*
ID: elijahj1
TASK: wissqu
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

vector<string> operations;
bool visited[4][4];
vector<string> pasture(4, string(4, ' '));
vector<int> leftover = { 3,3,3,4,3 };
int found = 0;

void solve(int placed) {
	if (placed == 16) {
		found++;
		if (found == 1) {
			for (auto s : operations) {
				cout << s << '\n';
			}
		}
	}

	for (int to_place = 0; to_place <= 4; to_place++) {
		char tp = 'A' + to_place;
		if (placed == 0 and tp != 'D') continue;
		if (!leftover[to_place]) continue;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (visited[i][j]) continue;
				bool none_same = true;
				for (int i2 = max(i - 1, 0); i2 <= min(i + 1, 3); i2++) {
					for (int j2 = max(j - 1, 0); j2 <= min(j + 1, 3); j2++) {
						if (pasture[i2][j2] == tp) {
							none_same = false;
							break;
						}
					}
				}
				if (none_same) {
					if (!found) {
						operations.push_back(string(1, tp) + ' ' + char(49 + i) + ' ' + char(49 + j));
					}
					char old = pasture[i][j];
					pasture[i][j] = tp;
					leftover[to_place]--;
					visited[i][j] = 1;
					solve(placed + 1);
					visited[i][j] = 0;
					leftover[to_place]++;
					pasture[i][j] = old;
					if (!found) {
						operations.pop_back();
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("wissqu.in", "r", stdin); freopen("wissqu.out", "w", stdout);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> pasture[i][j];
		}
	}

	solve(0);
	cout << found << '\n';
}