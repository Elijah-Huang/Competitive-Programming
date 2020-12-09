#include<bits/stdc++.h>
using namespace std;

long long ans = 0;
int n, d;
int v[1 << 17][2][2]; 
const int first = 1 << 16;

int mx(int l, int r, bool e1, bool e2) {
	return max({ v[l][e1][1] + v[r][0][e2], v[l][e1][0] + v[r][1][e2], v[l][e1][0] + v[r][0][e2] });
}

int update(int i) {
	int l = 2 * i, r = 2 * i + 1;
	int mx_milk = 0;
	for (int e1 = 0; e1 <= 1; e1++) {
		for (int e2 = 0; e2 <= 1; e2++) {
			mx_milk = max(mx_milk, v[i][e1][e2] = mx(l, r, e1, e2));
		}
	}
	
	return mx_milk;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("optmilk.in","r",stdin); freopen("optmilk.out","w",stdout);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> v[first + i][1][1];
	}

	for (int i = first - 1; i >= 1; i--) {
		update(i);
	}

	while (d--) {
		int cow; cin >> cow; cow--;
		cin >> v[first + cow][1][1];
		for (int parent = (first + cow) / 2; parent >= 2; parent /= 2) {
			update(parent);
		}
		ans += update(1);
	}

	cout << ans;
}