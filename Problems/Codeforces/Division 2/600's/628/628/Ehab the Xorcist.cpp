#include <bits/stdc++.h>
using namespace std;
int main() {
	long long u, v;
	cin >> u >> v;
	if (u > v) {
		cout << -1;
	}
	else if ((v - u) % 2 != 0) {
		cout << -1;
	}
	else if (v == u) {
		if (v != 0) {
			cout << 1 << '\n';
			cout << u;
		}
		else {
			cout << 0;
		}
	}
	else {
		long long need = (v - u) / 2;
		if ((need ^ u) == need + u) {
			cout << 2 << '\n';
			cout << u + need << " " << need;
		}
		else {
			cout << 3 << '\n';
			cout << u << " " << need << " " << need;
		}
	}
}