#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;
int t, n;
int a[maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cas = 1; cas <= t; cas++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int revs = 0;
		for (int i = 0; i < n - 1; i++) {
			int j = min_element(a + i, a + n) - a;
			revs += j - i + 1;
			reverse(a + i, a + j + 1);
		}

		cout << "Case #" << cas << ": " << revs << '\n';
	}
}