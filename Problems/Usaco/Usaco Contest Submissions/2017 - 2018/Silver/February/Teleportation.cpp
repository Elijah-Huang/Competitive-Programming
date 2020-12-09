#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("teleport.in", "r", stdin); freopen("teleport.out", "w", stdout);
	int n;
	cin >> n;
	map<int, int> points;
	long long original = 0;
	long long max_change = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a < 0 and b < 0 or a > 0 and b > 0) {
			int change = abs(b) - 2 * abs(a);
			if (change > 0) {
				points[b] += 2;
				points[b + change]--;
				points[b - change]--;
			}
		}
		else {
			points[b] += 2;
			points[0]--;
			points[2 * b]--;
		}
		original += abs(a - b);
	}
	long long curr_pull = 0;
	long long curr_change = 0;
	int prev = points.begin()->first;
	for (auto point : points) {
		curr_change += (point.first - prev) * curr_pull;
		max_change = min(max_change, curr_change);
		prev = point.first;
		curr_pull += point.second;
	}
	cout << original + max_change;
}