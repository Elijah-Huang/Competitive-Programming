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
	map<int, int, greater<int>> outputs = { {g,int(1e5 + 1)} };
	for (int i = 0; i < n; i++) {
		int day, cow, amount;
		cin >> day >> cow >> amount;
		logs[i] = { day, cow, amount };
	}
	sort(logs.begin(), logs.end(),
		[&](const measurement& a, const measurement& b) {return a.day < b.day; });

	for (int i = 0; i < n; i++) {
		int prev_size = (outputs.begin())->second;
		int prev_max = (outputs.begin())->first;
		int old;
		if (!cows.count(logs[i].cow)) {
			outputs[g]--;
			cows[logs[i].cow] = g + logs[i].amount;
			old = g;
		}
		else {
			outputs[cows[logs[i].cow]]--;
			old = cows[logs[i].cow];
			if (!outputs[cows[logs[i].cow]]) {
				outputs.erase(cows[logs[i].cow]);
			}
			cows[logs[i].cow] += logs[i].amount;
		}
		outputs[cows[logs[i].cow]]++;
		int new_max = (outputs.begin())->first;
		if ((new_max == cows[logs[i].cow] and old != prev_max) 
			or (old == prev_max and new_max != cows[logs[i].cow])){
			changes++;
			continue;
		}
		int new_size = (outputs.begin())->second;
		if (new_size != prev_size) {
			changes++;
		}
	}
	cout << changes;
}