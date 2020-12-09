#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cbarn.in", "r", stdin); freopen("cbarn.out", "w", stdout);
	int n;
	long long energy = 0;
	cin >> n;
	vector<int> rooms(n);
	priority_queue<int, vector<int>, greater<int>> moving_cows;
	for (int i = 0; i < n; i++) {
		cin >> rooms[i];
	}
	rooms.resize(2 * n, -1);
	int idx = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (i >= n and moving_cows.empty()) {
			break;
		}
		else if (i >= n) {
			if (rooms[i] == -1) {
				rooms[i] = i - moving_cows.top();
				moving_cows.pop();
			}
			else if (i - moving_cows.top() > rooms[i]) {
				moving_cows.push(i - rooms[i]);
				rooms[i] = i - moving_cows.top();
				moving_cows.pop();
			}
		}
		else {
			for (int j = 0; j < rooms[i]; j++) {
				moving_cows.push(i);
			}
			if (!moving_cows.empty()) {
				rooms[i + n] = i - moving_cows.top();
				moving_cows.pop();
			}
		}
	}
	for (int i = n; i < 2 * n; i++) {
		energy += (long long)(rooms[i]) * rooms[i];
	}
	cout << energy;
}