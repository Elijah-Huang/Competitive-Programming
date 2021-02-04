#include<bits/stdc++.h>
using namespace std;

int n, odd = 0, even = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a % 2) {
			odd++;
		}
		else {
			even++;
		}
	}

	if (odd <= even) {
		if (odd == even) {
			cout << 2*even;
		}
		else {
			cout << 2*odd + 1;
		}
	}
	else {
		odd -= even;
		vector<int> effect = { 0,-1,1 };
		cout << 2*even + 2 * (odd / 3) + (effect[odd%3]);
	}
}