#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
struct measurement {
	int day, cow, amount;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("measurement.in", "r", stdin); freopen("measurement.out", "w", stdout);
	int n, g, changes = 0;
	cin >> n >> g;
	vector<measurement> logs(n);
	unordered_map<int, int> cows;
	map<int, int> outputs = { {g,int(1e5 + 1)} };
	for (int i = 0; i < n; i++) {
		int day, cow, amount;
		cin >> day >> cow >> amount;
		logs[i] = { day, cow, amount };
	}
	sort(logs.begin(), logs.end(),
		[&](const measurement& a, const measurement& b) {return a.day < b.day; });
	int curr_max = g;
	for (int i = 0; i < n; i++) {
		int prev;
		if (!cows.count(logs[i].cow)) {
			cows[logs[i].cow] = g + logs[i].amount;
			prev = g;
		}
		else {
			outputs[cows[logs[i].cow]]--;
			if (!outputs[cows[logs[i].cow]]) {
				outputs.erase(cows[logs[i].cow]);
			}
			prev = cows[logs[i].cow];
			cows[logs[i].cow] += logs[i].amount;
		}
		outputs[cows[logs[i].cow]]++;
		int old_max = curr_max;
		curr_max = max(g, (--outputs.end()) -> first);
		if (cows[logs[i].cow] == curr_max) {
			if (!(old_max == prev and !outputs.count(old_max) and outputs[curr_max] == 1)) {
				changes++;
			}
		}
		else if (prev == curr_max) {
			changes++;
		}
	}
	cout << changes;
}