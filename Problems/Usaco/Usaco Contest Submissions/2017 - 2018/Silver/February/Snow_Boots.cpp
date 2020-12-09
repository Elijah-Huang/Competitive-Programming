#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("snowboots.in", "r", stdin); freopen("snowboots.out", "w", stdout);
	int n, b;
	cin >> n >> b;
	vector<int> depths(n);
	vector<bool> visitable(n);
	for (int i = 0; i < n; i++) {
		int d; cin >> d;
		depths[i] = d;
	}
	visitable[0] = 1;
	for (int i = 0; i < b; i++) {
		int depth, max_step;
		cin >> depth >> max_step;
		for (int loc = 0; loc < n; loc++) {
			if (visitable[loc] and depth >= depths[loc]) {
				for (int step = 1; step <= max_step; step++) {
					if (loc + step < n and depths[loc + step] <= depth) {
						visitable[loc + step] = 1;
					}
				}
			}
		}
		if (visitable[n - 1]) {
			cout << i;
			break;
		}
	}
}