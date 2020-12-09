#include <bits/stdc++.h>
using namespace std;
int main() {
	int k;
	cin >> k;
	int fake;
	if (k){
		fake = 1 << (ilogb(k) + 1);
	}
	else {
		fake = 1;
	}
	cout << 3 << " " << 2 << '\n';
	cout << fake + k << " " << fake << "\n";
	cout << k << " " << fake + k << "\n";
	cout << 0 << " " << k << '\n';
}