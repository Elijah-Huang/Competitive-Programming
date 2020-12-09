#include<bits/stdc++.h>
using namespace std;
struct cow {
	int arrival, seniority, time;
};

struct cow_cmp {
	bool operator()(const cow& a, const cow& b) const {
		return a.seniority > b.seniority;
	}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("convention2.in", "r", stdin); freopen("convention2.out", "w", stdout);
	int n, mx_wait = 0;
	cin >> n;
	vector<cow> cows(n);
	for (int i = 0; i < n; i++) {
		int arrival, time;
		cin >> arrival >> time;
		cows[i] = { arrival, i ,time };
	}
	sort(cows.begin(), cows.end(),
		[&](const cow& a, const cow& b) {return a.arrival < b.arrival; });

	int curr_time = 0;
	priority_queue<cow, vector<cow>, cow_cmp> pq;
	int i = 0;
	while (!pq.empty() or i < n) {
		if (pq.empty() and curr_time < cows[i].arrival) {
			curr_time = cows[i].arrival;
		}
		while (i < n and curr_time >= cows[i].arrival) {
			pq.push(cows[i]);
			i++;
		}
		mx_wait = max(mx_wait, curr_time - pq.top().arrival);
		curr_time += pq.top().time;
		pq.pop();
		
	}
	cout << mx_wait;
}