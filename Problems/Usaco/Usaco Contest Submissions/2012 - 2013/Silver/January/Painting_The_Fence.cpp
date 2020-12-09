#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("paint.in", "r", stdin); freopen("paint.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	int loc = 0;
	char curr_direction = '$';
	for (int i = 0; i < n; i++) {
		int displacement;
		char direction;
		cin >> displacement >> direction;
		if (direction != curr_direction) {
			if (direction == 'R') {
				mp[loc] += 1 + (i != 0);
			}
			else {
				mp[loc] -= 1 + (i != 0);
			}
			curr_direction = direction;
		}
		loc += (-1 + 2 * (curr_direction == 'R')) * displacement;
	}
	if (curr_direction == 'R') {
		mp[loc]--;
	}
	else {
		mp[loc]++;
	}
	int last;
	int coats = 0;
	int covered = 0;
	for (auto loc : mp) {
		if (coats >= k) {
			covered += loc.first - last;
		}
		coats += loc.second;
		last = loc.first;
	}
	cout << covered;
}