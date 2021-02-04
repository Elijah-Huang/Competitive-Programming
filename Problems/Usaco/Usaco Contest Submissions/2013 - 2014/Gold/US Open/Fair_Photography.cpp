#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, k;
pair<int, int> cows[maxn];
int amts[8];
map<vector<int>, vector<pair<int, int>>> rel_amts;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> cows[i].first >> cows[i].second;
		cows[i].second--;
	}

	sort(cows, cows + n);
	
	for (int i = 0; i < n; i++) {
		amts[cows[i].second]++;

		vector<int> rel_amt(8);
		int mn = 1e6;
		for (int i = 0; i < 8; i++) {
			if (amts[i] != 0) {
				mn = min(mn, amts[i]);
			}
		}
		for (int i = 0; i < 8; i++) {
			if (amts[i] != 0) {
				rel_amt[i] = amts[i] - mn;
			}
			else {
				rel_amt[i] = -1;
			}
		}

		rel_amts[rel_amt].push_back({})
	}
}