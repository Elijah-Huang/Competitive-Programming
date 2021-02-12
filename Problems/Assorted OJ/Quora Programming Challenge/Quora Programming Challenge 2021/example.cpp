#include<bits/stdc++.h>
using namespace std;

int tot = 0, a = 0, n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	while (n--) {
		cin >> a;
		tot += a;
	}

	cout << tot;
}