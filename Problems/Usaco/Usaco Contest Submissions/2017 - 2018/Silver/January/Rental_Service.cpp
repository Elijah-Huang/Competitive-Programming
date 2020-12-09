#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("rental.in", "r", stdin); freopen("rental.out", "w", stdout);
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> outputs;
	for (int i = 0; i < n; i++) {
		int o;
		cin >> o;
		outputs.push_back(o);
	}
	vector<pair<long long, long long>> milk;
	for (int i = 0; i < m; i++) {
		int quantity, cost;
		cin >> quantity >>  cost;
		milk.push_back({ cost, quantity });
	}
	vector<int> rent;
	for (int i = 0; i < r; i++) {
		int cost;
		cin >> cost;
		rent.push_back(cost);
	}
	sort(outputs.begin(), outputs.end(), greater<int>());
	sort(rent.begin(), rent.end(), greater<int>());
	sort(milk.begin(), milk.end(), greater<pair<long long, long long>>());
	long long profit = 0;
	int idx_milk = 0;
	for (int i = 0; i < n; i++) {
		long long milk_cow = 0;
		while (idx_milk < m and outputs[i]) {
			if (outputs[i] >= milk[idx_milk].second) {
				milk_cow += milk[idx_milk].second * milk[idx_milk].first;
				outputs[i] -= milk[idx_milk].second;
				idx_milk++;
			}
			else {
				milk_cow += milk[idx_milk].first * outputs[i];
				milk[idx_milk].second -= outputs[i];
				outputs[i] = 0;
			}
		}
		if (n - i > r or rent[n - i - 1] < milk_cow) {
			profit += milk_cow;
		}
		else {
			profit += accumulate(rent.begin(), rent.begin() + (n - i), 0ll);
			break;
		}
	}
	cout << profit;
}