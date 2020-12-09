#include<bits/stdc++.h>
using namespace std;

struct cow {
	vector<int> values;
	int t, i, d;
	cow(int v1, int v2, int t1, int i1, int d1) {
		values = { v1,v2 };
		t = t1;
		i = i1;
		d = d1;
	}
};

struct cow_cmp1 {
	bool operator()(const cow& a, const cow& b) const {
		if (a.values[0] == b.values[0]) {
			return a.values[1] < b.values[1];
		}
		return a.values[0] < b.values[0];
	}
};

struct cow_cmp2 {
	bool operator()(const cow& a, const cow& b) const {
		if (a.values[1] == b.values[1]) {
			return a.values[0] < b.values[0];
		}
		return a.values[1] < b.values[1];
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("piepie.in", "r", stdin); freopen("piepie.out", "w", stdout);
	int n, d; cin >> n >> d;
	vector<int> ans(2*n,-1);
	set<cow, cow_cmp2> bessie; set<cow, cow_cmp1> elsie;
	queue<cow> q;
	map<pair<pair<int,int>,int>,vector<int>> mp;
	for (int i = 0; i < 2*n; i++) {
		int v1, v2; cin >> v1 >> v2;
		mp[{ { v1, v2 }, i / n }].push_back(i);
		cow curr(v1, v2, i / n, i, 1);
		if (i / n) {
			if (curr.values[0] == 0) {
				q.push(curr);
			}
			else {
				elsie.insert(curr);
			}
		}
		else {
			if (curr.values[1] == 0) {
				q.push(curr);
			}
			else {
				bessie.insert(curr);
			}
		}
	}

	while (!q.empty()) {
		auto curr = q.front(); q.pop();
		for (auto i : mp[{ {curr.values[0], curr.values[1]}, curr.t}]) {
			ans[i] = curr.d;
		}
		if (curr.t) {
			curr.values[0] = 1e9 + 1;
			auto loc = bessie.upper_bound(curr);
			if (loc != bessie.begin()) {
				loc--;
			}
			else {
				continue;
			}
			while (loc->values[1] + d >= curr.values[1]) {
				cow child = *loc;
				child.d = curr.d + 1;
				q.push(child);
				if (loc == bessie.begin()) {
					bessie.erase(loc);
					break;
				}
				else {
					auto nxt = loc;
					nxt--;
					bessie.erase(loc);
					loc = nxt;
				}
			}
		}
		else {
			curr.values[1] = 1e9 + 1;
			auto loc = elsie.upper_bound(curr);
			if (loc != elsie.begin()) {
				loc--;
			}
			else {
				continue;
			}
			while (loc->values[0] + d >= curr.values[0]) {
				cow child = *loc;
				child.d = curr.d + 1;
				q.push(child);
				if (loc == elsie.begin()) {
					elsie.erase(loc);
					break;
				}
				else {
					auto nxt = loc;
					nxt--;
					elsie.erase(loc);
					loc = nxt;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
}