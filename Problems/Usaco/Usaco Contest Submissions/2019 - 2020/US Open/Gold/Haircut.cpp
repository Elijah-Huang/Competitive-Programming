#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 2;
int n;
long long curr_ans = 0;
long long inversions[maxn], ans[maxn];
int hairs[maxn], bit[maxn];

void add(int idx, int val) {
	for (idx++; idx < maxn; idx += idx & -idx) {
		bit[idx] += val;
	}
}

int sum(int idx) {
	int ret = 0;
	for (idx++; idx > 0; idx -= idx & -idx) {
		ret += bit[idx];
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("haircut.in", "r", stdin); freopen("haircut.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> hairs[i];
	}

	for (int i = 0; i < n; i++) {
		int invers = sum(n) - sum(hairs[i]);
		curr_ans += invers;
		inversions[hairs[i]] += invers;
		add(hairs[i], 1);
	}

	for (int i = n - 1; i >= 0; i--) {
		curr_ans -= inversions[i];
		ans[i] = curr_ans;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
}