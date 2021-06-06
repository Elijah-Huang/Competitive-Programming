#include<bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n;

		set<int> curr;

		int b; cin >> b;

		curr.insert(b);
		int curr_med = b;
		
		n--;
		bool fail = 0;
		while (n--) {
			int b; cin >> b;

			if (b < curr_med) {
				auto loc = curr.find(curr_med);

				if (loc == curr.begin() or *prev(loc) <= b) {
					if (loc == curr.begin() or *prev(loc) < b) {
						curr.insert(b);
					}

					curr_med = b;
				}
				else {
					fail = 1;
				}
			}
			else if (b > curr_med) {
				auto loc = curr.find(curr_med);

				if (loc == prev(curr.end()) or *next(loc) >= b) {
					if (loc == prev(curr.end()) or *next(loc) > b) {
						curr.insert(b);
					}

					curr_med = b;
				}
				else {
					fail = 1;
				}
			}
		}

		if (fail) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
}