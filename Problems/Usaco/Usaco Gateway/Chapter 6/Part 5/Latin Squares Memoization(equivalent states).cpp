/*
ID: elijahj1
TASK: latin
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

int n, len;
int a[8], cnt[8];
long long ans = 0;
bool visx[8][8], visy[8][8], vis[8];

int compute_length() {
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
	}

	int x = 2;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		int u = i, t = 0;
		do {
			vis[u] = 1;
			u = a[u];
			t++;
		} while (!vis[u]);
		if (t > x) {
			x = t;
		}
	}

	return x;
}

void dfs(int x, int y) {
	if (x == n) {
		ans++;
		cnt[len]++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visx[i][x] and !visy[i][y]) {
			if (x == 2) {
				a[y] = i;
				if (y == n) {
					len = compute_length();
					if (cnt[len] > 0) {
						ans += cnt[len];
						return;
					}
				}
			}
			visx[i][x] = 1, visy[i][y] = 1;
			if (y < n) { 
				dfs(x, y + 1); 
			}
			else {
				dfs(x + 1, 2);
			}
			visx[i][x] = 0, visy[i][y] = 0;
		}
	}
}

int main() {
	freopen("latin.in", "r", stdin); freopen("latin.out", "w", stdout);
	cin >> n;
	if (n == 2) {
		cout << 1 << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		visy[i][i] = 1;
	}
	for (int i = 2; i < n; i++) {
		visx[i][i] = 1;
	}
	a[1] = 2;
	dfs(2, 2);

	for (int i = 2; i <= n - 1; i++) {
		ans *= i;
	}

	cout << ans << '\n';
	return 0;
}