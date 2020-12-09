#include<bits/stdc++.h>
using namespace std;

struct event {
	int at_end, amt_change = 0;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a(n), b(n), loca(n + 1), locb(n + 1);
	vector<event> events(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		loca[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		locb[b[i]] = i;
		events[n - 1 - i].at_end = b[i];
	}

	long long mn_dist;
	long long curr_dist = 0;
	int curr_change = 0;
	for (int i = 1; i <= n; i++) {
		if (locb[i] >= loca[i]) {
			curr_change++;
		}
		else {
			curr_change--;
		}
		events[(n + loca[i] - locb[i]) % n].amt_change++;
		//cout << (n + loca[i] - locb[i]) % n << '\n';
		curr_dist += abs(locb[i] - loca[i]);
	}
	mn_dist = curr_dist;
	//cout << curr_dist << '\n';
	//cout << "curr_change: " << curr_change << '\n';
	curr_change -= 1;
	curr_dist -= n - 1 - loca[events[0].at_end];
	curr_dist += loca[events[0].at_end] - 0;

	/*for (auto i : events) {
		cout << i.at_end << ' ' << i.amt_change << '\n';
	}*/
	for (int i = 1; i <= n - 1; i++) {
		// add change from pos 2 to last idx
		//cout << curr_change << '\n';
		curr_dist += curr_change;
		//cout << curr_dist << '\n';
		mn_dist = min(mn_dist, curr_dist);

		//add change from first idx now
		curr_change -= 1;
		//update changes if passing same val in A
		curr_change += 2*events[i].amt_change;
		//invalidate last idx change
		curr_change -= 1;
		//add change from first
		curr_dist -= n - 1 - loca[events[i].at_end];
		curr_dist += loca[events[i].at_end] - 0;
	}

	cout << mn_dist;
}