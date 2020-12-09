#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("hayfeast.in", "r", stdin); freopen("hayfeast.out", "w", stdout);
	long long n, m; cin >> n >> m;
	int least_spicy = 2e9;
	multiset<int, greater<int>> curr_spicy;
	vector<long long> tot_taste(n + 1);
	vector<pair<int, int>> haybales(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> haybales[i].first >> haybales[i].second;
	}
	for (int i = 1; i <= n; i++) {
		tot_taste[i] = tot_taste[i-1] + haybales[i].first;
	}

	int end = 1;
	for (int start = 1; start <= n; start++) {
		int loc = lower_bound(tot_taste.begin(), tot_taste.end(), tot_taste[start-1] + m) - tot_taste.begin();
		if (loc == n + 1) {
			break;
		}
		while (end <= loc) {
			curr_spicy.insert(haybales[end].second);
			end++;
		}
		least_spicy = min(least_spicy, *curr_spicy.begin());
		curr_spicy.erase(curr_spicy.find(haybales[start].second));
	}

	cout << least_spicy;
}