#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("lemonade.in", "r", stdin); freopen("lemonade.out", "w", stdout);
	int n;
	cin >> n;
	int mn = n;
	vector<int> ws(n);
	for (int i = 0; i < n; i++) {
		cin >> ws[i];
	}
	sort(ws.begin(), ws.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		if (i > ws[i]) {
			mn = i;
			break;
		}
	}
	cout << mn;
}