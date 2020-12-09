#include<bits/stdc++.h>
using namespace std;

struct fuel_station {
	int x, p, i;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fuel.in", "r", stdin); freopen("fuel.out", "w", stdout);
	int n, g, b, d;
	long long total_cost = 0;
	cin >> n >> g >> b >> d;
	vector<fuel_station> stations;
	vector<int> next_smallest(n);
	for (int i = 0; i < n; i++) {
		int x, p;
		cin >> x >> p;
		stations.push_back({ x,p });
	}
	sort(stations.begin(), stations.end(),
		[&](const fuel_station& a, const fuel_station& b)  {if (a.x == b.x) { return a.p < b.p; } return a.x < b.x; });
	
	int last = 0;
	for (int i = 0; i < n; i++) {
		stations[i].i = i;
		if (stations[i].x - last > g) {
			cout << -1;
			return 0;
		}
		last = stations[i].x;
	}

	int station_idx = 0;
	stack<fuel_station> s;
	for (int i = 0; i < n; i++) {
		while (!s.empty() and stations[i].p < s.top().p) {
			next_smallest[s.top().i] = i;
			s.pop();
		}
		s.push(stations[i]);
	}

	long long curr_gas = b - stations[0].x;
	int i = 0;
	while (i < n) {
		//cout << i << ' ' << curr_gas << ' ' << total_cost <<  '\n';
		if (next_smallest[i] == 0 or stations[next_smallest[i]].x - stations[i].x > g) {
			if (d > g + stations[i].x) {
				total_cost += (g - curr_gas) * stations[i].p;
				curr_gas = g - (stations[i + 1].x - stations[i].x);
				i++;
			}
			else {
				total_cost += (d - (curr_gas + stations[i].x)) * stations[i].p;
				break;
			}
			
		}
		else {
			long long dist = stations[next_smallest[i]].x - stations[i].x;
			if (dist > curr_gas) {
				total_cost += (dist - curr_gas) * stations[i].p;
				curr_gas = 0;
			}
			else {
				curr_gas -= dist;
			}
			i = stations[next_smallest[i]].i;
		}
	}
	
	cout << total_cost;
}