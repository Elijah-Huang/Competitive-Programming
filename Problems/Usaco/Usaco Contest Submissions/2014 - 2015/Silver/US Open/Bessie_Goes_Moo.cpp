#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

long long dp[3][5][7];
unordered_map<char, vector<int>> values;
vector<vector<pair<char, int>>> to_place =
{ {{'I',1},{'B',1},{'E',2},{'S',2}}, {{'G',1},{'O',1},{'E',1},{'S',1}},{{'M',1},{'O',2}} };

void solve(vector<pair<char, int>>& to_place, long long dp[5][7]) {
	dp[0][0] = 1;
	for (int i = 0; i < to_place.size(); i++) {
		for (int residue = 0; residue < 7; residue++) {
			if (dp[i][residue]) {
				for (auto val : values[to_place[i].first]) {
					dp[i + 1][(residue + val * to_place[i].second) % 7] += dp[i][residue];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("bgm.in", "r", stdin); freopen("bgm.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c; int val;
		cin >> c >> val;
		values[c].push_back(val);
	}

	for (int i = 0; i < 3; i++) {
		solve(to_place[i], dp[i]);
	}
	
	long long total = 0;
	total = dp[0][4][0] * (7 * 7 * 7) + dp[1][4][0] * (7 * 7 * 7) + dp[2][2][0] * (7 * 7 * 7 * 7)
		- 

	cout << total;
}