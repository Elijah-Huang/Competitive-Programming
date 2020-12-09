#include<bits/stdc++.h>
using namespace std;

struct pap {
	int t, x, y;
};

bool can_get_to(pap& a, pap& b) {
	return b.t - a.t >= abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r, n; cin >> r >> n;
	vector<pap> paps(n + 1);
	paps[0] = { 0,1,1 };
	vector<int> psum(n + 1);
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> paps[i].t >> paps[i].x >> paps[i].y;
	}
	
	for (int i = 1; i <= n; i++) {
		ans[i] = can_get_to(paps[0], paps[i]);
		for (int j = i - 1; j >= max(0, i-(2*r-2)); j--) {
			if (ans[j] and can_get_to(paps[j], paps[i])) {
				ans[i] = max(ans[i], ans[j] + 1);
			}
		}
		if (i > 2 * r - 2) {
			ans[i] = max(ans[i], psum[i - (2 * r - 2) - 1] + 1);
		}
		psum[i] = max(ans[i], psum[i - 1]);
	}
	cout << *max_element(ans.begin(),ans.end());
}