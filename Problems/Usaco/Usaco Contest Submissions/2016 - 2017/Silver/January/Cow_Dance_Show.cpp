#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowdance.in", "r", stdin); freopen("cowdance.out", "w", stdout);
	int n, tmax;
	cin >> n >> tmax;
	vector<int> times(n);
	for (int i = 0; i < n; i++) {
		cin >> times[i];
	}
	int L = 1, R = n;
	while (L != R) {
		int m = (L + R) / 2;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < m; i++) {
			pq.push(times[i]);
		}
		for (int i = m; i < n; i++) {
			int finished = pq.top();
			pq.pop();
			pq.push(finished + times[i]);
		}
		for (int i = 0; i < m - 1; i++) {
			pq.pop();
		}
		int time_took = pq.top();
		if (time_took <= tmax) {
			R = m;
		}
		else {
			L = m + 1;
		}
	}
	cout << L;
}