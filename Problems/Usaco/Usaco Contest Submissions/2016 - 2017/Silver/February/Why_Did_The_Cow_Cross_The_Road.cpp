#include<bits/stdc++.h>
using namespace std;
struct interval {
	int a, b;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("helpcross.in", "r", stdin); freopen("helpcross.out", "w", stdout);
	int c, n;
	cin >> c >> n;
	vector<int> help_times(c);
	vector<interval> cross_times(n);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < c; i++) {
		cin >> help_times[i];
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cross_times[i] = { a,b };
	}
	sort(help_times.begin(), help_times.end());
	sort(cross_times.begin(), cross_times.end(),
		[&](const interval& a, const interval& b) {return a.a < b.a; });
	int j = 0, max_helped = 0;
	for (int i = 0; i < c; i++) {
		int curr = help_times[i];
		while (!pq.empty() and pq.top() < curr) {
			pq.pop();
		}
		while (j < n and cross_times[j].a <= curr) {
			if (cross_times[j].b >= curr) {
				pq.push(cross_times[j].b);
			}
			j++;
		}
		if (!pq.empty()) {
			pq.pop();
			max_helped++;
		}
	}
	cout << max_helped;
}