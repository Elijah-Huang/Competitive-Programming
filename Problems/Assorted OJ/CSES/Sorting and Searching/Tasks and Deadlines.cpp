#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	long long total_deadline = 0;
	long long total_duration = 0;
	long long curr = 0;
	vector<int> durations(n);
	for (int i = 0; i < n; i++) {
		cin >> durations[i];
		int a; cin >> a;
		total_deadline += a;
	}

	sort(durations.begin(), durations.end());

	for (int i = 0; i < n; i++) {
		curr += durations[i];
		total_duration += curr;
	}

	cout << total_deadline - total_duration;
}