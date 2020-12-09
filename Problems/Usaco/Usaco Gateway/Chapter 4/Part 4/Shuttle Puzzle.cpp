/*
ID: elijahj1
TASK: shuttle
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
bool dfs(string& curr, vector<int>& path, int& mx_length, int& length, int space_location, string& finish) {
	if (length == mx_length) {
		if (curr == finish){
			return true;
		}
		else {
			return false;
		}
	}
	vector<int> moves;
	if (space_location >= 2 and curr[space_location - 1] == 'b' and curr[space_location - 2] == 'w') {
		moves.push_back(space_location - 2);
	}
	else if(space_location >= 1 and curr[space_location - 1] == 'w') {
		moves.push_back(space_location - 1);
	}
	if (space_location < curr.size() - 1 and curr[space_location + 1] == 'b') {
		moves.push_back(space_location + 1);
	}
	else if (space_location < curr.size() - 2 and curr[space_location + 1] == 'w' and curr[space_location + 2] == 'b') {
		moves.push_back(space_location + 2);
	}
	bool worked = false;
	for (auto move : moves) {
		curr[space_location] = curr[move];
		curr[move] = ' ';
		path.push_back(move+1);
		length++;
		worked = dfs(curr, path, mx_length,length, move, finish);
		length--;
		if (worked) {
			return true;
		}
		path.pop_back();
		curr[move] = curr[space_location];
		curr[space_location] = ' ';
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("shuttle.in", "r", stdin); freopen("shuttle.out", "w", stdout);
	int n;
	cin >> n;
	bool found = false;
	vector<int> path;
	int mx_length = n*n + 2*n - 1;
	string start = string(n, 'w') + ' ' + string(n, 'b');
	string finish = string(n, 'b') + ' ' + string(n, 'w');
	while (!found) {
		mx_length++;
		int length = 0;
		found = dfs(start, path, mx_length, length, n, finish);
	}
	for (int i = 0; i < mx_length / 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << path[20 * i + j] << (j == 19 ? '\n' : ' ');
		}
	}
	for (int j = 0; j < mx_length % 20; j++) {
		cout << path[20 * (mx_length / 20) + j] << (j == mx_length % 20 - 1 ? '\n' : ' ');
	}
}