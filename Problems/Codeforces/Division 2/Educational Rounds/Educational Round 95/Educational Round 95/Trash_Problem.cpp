#include<bits/stdc++.h>
using namespace std;

set<int> points;
multiset<int> gaps;

void update(int t, int p) {
	if (t) {
		auto loc = points.insert(p).first;
		if (points.size() > 1) {
			if (--points.end() == loc) {
				loc--;
				gaps.insert(p - *loc);
			}
			else if (points.begin() == loc) {
				loc++;
				gaps.insert(*loc - p);
			}
			else {
				auto before = loc; before--;
				auto after = loc; after++;
				gaps.erase(gaps.find(*after - *before));
				gaps.insert(p - *before);
				gaps.insert(*after - p);
			}
		}
	}
	else {
		auto loc = points.find(p);
		if (points.size() > 1) {
			if (--points.end() == loc) {
				loc--;
				gaps.erase(gaps.find(p - *loc));
			}
			else if (points.begin() == loc) {
				loc++;
				gaps.erase(gaps.find(*loc - p));
			}
			else {
				auto before = loc; before--;
				auto after = loc; after++;
				gaps.insert(*after - *before);
				gaps.erase(gaps.find(p - *before));
				gaps.erase(gaps.find(*after - p));
			}
		}
		points.erase(p);
	}
}

int solve() {
	if (points.size() <= 1) {
		return 0;
	}
	return (*(--points.end()) - *points.begin() - *(--gaps.end()));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q; cin >> n >> q;
	while(n--) {
		int p; cin >> p;
		update(1, p);
	}

	cout << solve() << '\n';
	while (q--) {
		int t, p; cin >> t >> p;
		update(t, p);
		cout << solve() << '\n';
	}
}