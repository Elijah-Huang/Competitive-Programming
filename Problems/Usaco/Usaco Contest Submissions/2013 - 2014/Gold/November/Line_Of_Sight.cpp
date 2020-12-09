#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("sight.in", "r", stdin); freopen("sight.out", "w", stdout);
	double pi = 4 * atan(1);
	int ans = 0;
	int n, r; cin >> n >> r;
	vector<pair<double, double>> original_endpoints;
	vector<pair<double, double>> endpoints;
	for (int i = 0; i < n; i++) {
		long long x, y; cin >> x >> y;
		double a = acos(r / sqrt(x * x + y * y));
		double mid = atan2(y , x);
		original_endpoints.push_back({ mid - a, mid + a });
		endpoints.push_back({ mid - a, mid + a });
		// edge case of angle "wrapping around" and going from pi -> -pi
		endpoints.push_back({ mid - a - 2 * pi, mid + a - 2 * pi });
		endpoints.push_back({ mid - a + 2 * pi, mid + a + 2 * pi });
	}

	sort(endpoints.begin(), endpoints.end());

	for (int i = 0; i < n; i++) {
		ans += int(upper_bound(endpoints.begin(), endpoints.end(), make_pair(original_endpoints[i].second,0.0 )) - 
			upper_bound(endpoints.begin(),endpoints.end(),make_pair(original_endpoints[i].first-1e-12,0.0))) - 1;
	}

	cout << ans << '\n';
}