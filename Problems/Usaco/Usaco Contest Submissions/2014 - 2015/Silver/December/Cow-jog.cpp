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
	
	bool removed = true;
	while (removed) {
		vector<cow> nxtcows;
		removed = false;
		for (int i = 0; i < cows.size() - 1; i++) {
			if (cows[i].v > cows[i + 1].v and (cows[i + 1].x - cows[i].x) <= t * (cows[i].v - cows[i + 1].v)) {
				removed = true;
			}
			else {
				nxtcows.push_back(cows[i]);
			}
		}
		nxtcows.push_back(cows[cows.size() - 1]);
		cows = nxtcows;
	}

	cout << cows.size();
}