#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("walk.in", "r", stdin); freopen("walk.out", "w", stdout);
	int n, k; cin >> n >> k;
	cout << 2019201997 + ((k - 1) * (-84) + n * (-48));
}