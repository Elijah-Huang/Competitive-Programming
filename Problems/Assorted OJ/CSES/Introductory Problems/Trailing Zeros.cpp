#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int ans = 0;
	int curr = 1;
	while (curr <= n/5) {
		curr *= 5;
		ans += n / curr;
	}
	
	cout << ans << '\n';
}