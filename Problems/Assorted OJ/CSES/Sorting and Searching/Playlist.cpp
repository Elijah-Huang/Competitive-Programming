#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	queue<int> q;
	set<int> active;
	int mx = 0;
	while (n--) {
		int a; cin >> a;
		if (active.count(a)) {
			while (q.front() != a) {
				active.erase(q.front());
				q.pop();
			}
			active.erase(q.front());
			q.pop();
		}
		q.push(a);
		active.insert(a);
		mx = max(mx, (int)q.size());
	}

	cout << mx;
}