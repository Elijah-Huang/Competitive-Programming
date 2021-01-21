#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5, prec = 1e5;
int n;
int a[maxn];
long long tot;

bool check(long long z) {
	long long mn = 1e18;
	long long curr_mn = 0;

	for (int i = 1; i < n-1; i++) {
		curr_mn = min(z - prec * a[i], curr_mn + z - prec * a[i]);
		mn = min(mn, curr_mn);
	}

	return z * n >= prec * tot + mn;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("sabotage.in", "r", stdin); freopen("sabotage.out", "w", stdout);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	tot = accumulate(a, a + n, 0);

	int l = 0, r = 1e4*prec;
	while (l != r) {
		int m = (l + r) / 2;
		
		if (check(m)) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}

	cout << fixed << setprecision(3) << l/double(prec);
}