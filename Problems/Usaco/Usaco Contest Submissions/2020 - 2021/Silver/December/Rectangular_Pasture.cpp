#include<bits/stdc++.h>
using namespace std;

struct cow {
	int x, y;
};

const int maxn = 2501;
int n;
long long ans = 1;
cow cows[maxn];
int a[maxn+5];
unordered_map<int, int> converty;

void add(int idx, int val) {
	for (idx++; idx <= maxn; idx += idx & -idx) {
		a[idx] += val;
	}
}

long long sum(int idx) {
	long long tot = 0;
	for (idx++; idx > 0; idx -= idx & -idx) {
		tot += a[idx];
	}

	return tot;
}

long long sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cows[i].x >> cows[i].y;
	}

	sort(cows, cows + n, [&](const cow& a, const cow& b) {return a.y < b.y; });

	for (int i = 0; i < n; i++) {
		converty[cows[i].y] = i;
	}

	sort(cows, cows + n, [&](const cow& a, const cow& b) {return a.x < b.x; });

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			add(converty[cows[j].y], 1);

			int miny = min(cows[i].y, cows[j].y);
			int maxy = max(cows[i].y, cows[j].y);

			ans += sum(converty[maxy], maxn-1) * sum(0, converty[miny]);
		}

		memset(a, 0, sizeof(a));
	}

	cout << ans;
}