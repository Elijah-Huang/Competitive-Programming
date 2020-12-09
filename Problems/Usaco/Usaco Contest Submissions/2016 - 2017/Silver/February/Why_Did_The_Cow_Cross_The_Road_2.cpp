#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("maxcross.in", "r", stdin); freopen("maxcross.out", "w", stdout);
	int n, k, b, mn_fix = 100000, curr_fix = 0;
	cin >> n >> k >> b;
	bool broken[100000]{};
	for (int i = 0; i < b; i++) {
		int broke;
		cin >> broke;
		broken[--broke] = 1;
	}
	for (int i = 0; i < k; i++) {
		curr_fix += broken[i];
	}
	mn_fix = min(curr_fix, mn_fix);
	for (int i = k; i < n; i++) {
		curr_fix += broken[i] - broken[i - k];
		mn_fix = min(mn_fix, curr_fix);
	}
	cout << mn_fix;
}