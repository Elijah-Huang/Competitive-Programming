#include<bits/stdc++.h>
using namespace std;

struct cow {
	int w, l, r;
};

const int maxn = 301;
int ans = 0, prefix_ptr = 0;
int mx_weights[maxn][maxn], mx_prefix[maxn];
vector<cow> cows;

void update(int idx, int val, int bit[maxn]) {
	idx = 300 - idx;
	for (idx++; idx < maxn; idx += idx & -idx) {
		bit[idx] = max(bit[idx], val);
	}
}

void suffix_mx(int idx, int val, int bit[maxn]) {
	int ret = 0;
	idx = 300 - idx;
	for (idx++; idx > 0; idx -= idx & -idx) {
		ret = max(ret, bit[idx]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("pieaters.in","r",stdin); freopen("pieaters.out","w",stdout);

	int n, m; cin >> n >> m;	
	for (int i = 0; i < m; i++) {
		int w, l, r; cin >> w >> l >> r;
		cows.push_back({ w,l,r });
	}

	sort(cows.begin(), cows.end(), [&](const cow& a, const cow& b) {if (a.r == b.r) { return a.l > b.l; } return a.r < b.r; });

	for (auto& c : cows) {
		while (prefix_ptr < c.r) {
			prefix_ptr++;
			mx_prefix[prefix_ptr] = mx_prefix[prefix_ptr - 1];
		}

		update(c.r, mx_prefix[c.l - 2] + c.w, mx_weights[c.l]);
		
		for (int i = )
		for (int i = 1; i < c.)
	}
}