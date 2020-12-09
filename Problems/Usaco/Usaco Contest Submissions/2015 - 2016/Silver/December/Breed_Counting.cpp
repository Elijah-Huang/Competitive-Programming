#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("bcount.in", "r", stdin); freopen("bcount.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<int> cows(n);
	vector<int> holsteins(n + 1), guernseys(n + 1), jerseys(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> cows[i];
	}
	for (int i = 1; i <= n; i++) {
		holsteins[i] = holsteins[i - 1] + (cows[i - 1] == 1);
		guernseys[i] = guernseys[i - 1] + (cows[i - 1] == 2);
		jerseys[i] = jerseys[i - 1] + (cows[i - 1] == 3);
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << holsteins[b] - holsteins[a - 1] << ' ' << guernseys[b] - guernseys[a - 1]
			<< ' ' << jerseys[b] - jerseys[a - 1] << '\n';
	}
}