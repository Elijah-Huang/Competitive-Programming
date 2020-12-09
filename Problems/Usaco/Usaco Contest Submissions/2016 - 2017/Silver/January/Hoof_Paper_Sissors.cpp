#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("hps.in", "r", stdin); freopen("hps.out", "w", stdout);
	int n, max_wins = 0;
	cin >> n;
	string FJ;
	vector<int> dph(n + 1), dpp(n+1), dps(n + 1);
	for (int i = 0; i < n; i++) {
		char j;
		cin >> j;
		FJ.push_back(j);
	}
	for (int i = 0; i < n; i++) {
		dpp[i + 1] = dpp[i] + (FJ[i] == 'H');
		dph[i + 1] = dph[i] + (FJ[i] == 'S');
		dps[i + 1] = dps[i] + (FJ[i] == 'P');
	}
	for (int i = 0; i < n; i++) {
		max_wins = max({ max_wins,
			dpp[i] + dps[n] - dps[i], dpp[i] + dph[n] - dph[i],
			dph[i] + dps[n] - dps[i], dph[i] + dpp[n] - dpp[i],
			dps[i] + dpp[n] - dpp[i], dps[i] + dph[n] - dph[i] });
	}
	cout << max_wins;

}