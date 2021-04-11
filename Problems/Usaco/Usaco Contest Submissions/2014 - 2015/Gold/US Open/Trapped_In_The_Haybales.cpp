// nlogn
// the idea is that every trapped segment must be contained in a segment of the form
// i..j where pos(j)-pos(i) <= min(sz(i),sz(j)) -> sz(i) and sz(j) must be > any sz(of bale between them)
// this means that no two segments can intersect at any place other than the endpoints 
// unless one is completely contained in another
// then the answer is the union of all these segments
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n;
long long ans = 0;
pair<int, int> haybales[maxn];
set<pair<int, int>> locs;
set<pair<int, int>> trapped;

template<typename T>
void add_trapped_seg(T L, T R) {
	if (min(L->second, R->second) >= R->first - L->first) {
		bool uncontained = true;
		if (trapped.size()) {
			auto seg_before = trapped.upper_bound({ L->first,1e9 + 1 });
			if (seg_before != trapped.begin() and prev(seg_before)->second >= R->first) {
				uncontained = false;
			}
		}

		if (uncontained) {
			trapped.insert({ L->first, R->first });
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> haybales[i].first >> haybales[i].second;
	}

	sort(haybales, haybales + n, greater<pair<int, int>>());

	for (int i = 0; i < n; i++) {
		auto loc = locs.insert({ haybales[i].second, haybales[i].first });

		if (loc.first != locs.begin()) {
			add_trapped_seg(prev(loc.first), loc.first);
		}
		if (loc.first != --locs.end()) {
			add_trapped_seg(loc.first, next(loc.first));
		}
	}

	for (auto seg : trapped) {
		ans += seg.second - seg.first;
	}

	cout << ans;
}