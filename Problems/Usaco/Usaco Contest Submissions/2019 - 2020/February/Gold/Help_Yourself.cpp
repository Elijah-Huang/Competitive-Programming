#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("help.in", "r", stdin); freopen("help.out", "w", stdout);
	const int mod = 1e9 + 7;
	int n; cin >> n;
	vector<int> segs(n);
	vector<int> intersections(2 * n + 1);
	vector<int> powers(n);
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		intersections[l]++;
		intersections[r]--;
		segs[i] = l;
	}
	
	int curr = 0;
	for (int i = 0; i < 2 * n; i++) {
		curr += intersections[i];
		intersections[i] = curr;
	}
	
	curr = 1;
	for (int i = 0; i < n; i++) {
		powers[i] = curr;
		curr = (curr * 2) % mod;
	}

	int tot = 0;
	for (int i = 0; i < n; i++) {
		tot = (tot + powers[n - 1 - intersections[segs[i] - 1]]) % mod;
	}

	cout << tot;
}