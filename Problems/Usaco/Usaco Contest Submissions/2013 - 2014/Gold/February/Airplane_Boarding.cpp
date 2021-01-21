#include<bits/stdc++.h>
using namespace std;

struct cow {
	int s, t;
};

const int maxn = 2e5;
int n, ans = 0;
cow cows[maxn];

int bit[maxn+2];

void add(int idx, int a) {
	for (idx++; idx < maxn+2; idx += idx & -idx) {
		bit[idx] = max(bit[idx], a);
	}
}

int mx(int idx) {
	int res = 0;
	for (idx++; idx > 0; idx -= idx & -idx) {
		max(res, bit[idx]);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("boarding.in", "r", stdin); freopen("boarding.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cows[i].s >> cows[i].t;
	}

	for (int i = n-1; i >= 0; i--) {
		/*int time = max((n - 1 + cows[i].s - i), cows[i].s + mx(cows[i].s-1)) + cows[i].t;
		ans = max(ans, time);
		add(cows[i].s, time);*/
		int time = n - 1 + cows[i].s - i + mx(cows[i].s - 1) + cows[i].t;
		ans = max(ans, time);
		add(cows[i].s, time);
	}

	cout << ans;
}