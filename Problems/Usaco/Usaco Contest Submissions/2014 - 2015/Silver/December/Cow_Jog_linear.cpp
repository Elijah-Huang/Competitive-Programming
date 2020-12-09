#include<bits/stdc++.h>
using namespace std;

struct cow {
	int x, v;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowjog.in", "r", stdin); freopen("cowjog.out", "w", stdout);
	long long n, t; cin >> n >> t;
	vector<cow> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i].x >> cows[i].v;
	}
	int groups = n;
	int slowest = n - 1;
	for (int i = cows.size() - 2; i >= 0; i--) {
		if (cows[i].v > cows[slowest].v and (cows[slowest].x - cows[i].x) <= t * (cows[i].v - cows[slowest].v)) {
			groups--;
		}
		else {
			slowest = i;
		}
	}

	cout << groups;
}