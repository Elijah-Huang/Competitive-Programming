#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("wifi.in", "r", stdin); freopen("wifi.out", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> locations(n);
	for (int i = 0; i < n; i++) {
		cin >> locations[i];
	}
	sort(locations.begin(), locations.end());
	int total_dist = locations[n - 1] - locations[0];
	int total_stations = 1;
	double max_dist = 2.0 * a / b;
	for (int i = 0; i < n-1; i++) {
		if (locations[i+1] - locations[i] > max_dist ) {
			total_stations++;
			total_dist -= locations[i + 1] - locations[i];
		}
	}
	double cost = total_stations * a + total_dist / 2.0 * b;
	if (fabs(int(cost) - cost) < 1e-8) {
		cout << int(cost);
	}
	else {
		cout << fixed << setprecision(1) << cost;
	}
}