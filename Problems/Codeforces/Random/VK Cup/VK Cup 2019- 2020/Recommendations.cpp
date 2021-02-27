#include <bits/stdc++.h>
using namespace std;
bool comparator(pair<int, int> const& a, pair<int, int> const& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
	}
	sort(a.begin(), a.end(), comparator);
	priority_queue<int> pq;
	int idx = 0, number = 0;
	long long sum = 0;
	long long total_time = 0;
	while (!pq.empty() or number <= a[n - 1].first) {
		number = a[idx].first;
		while (idx < n and a[idx].first == number) {
			int next = a[idx].second;
			sum += next;
			pq.push(next);
			idx++;
		}
		sum -= pq.top();
		pq.pop();
		number++;
		total_time += sum;
		while ((idx == n or number != a[idx].first) and !pq.empty()) {
			sum -= pq.top();
			pq.pop();
			number++;
			total_time += sum;
		}
	}
	cout << total_time;

}