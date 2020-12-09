#include<bits/stdc++.h>
using namespace std;

struct seg_tree {

	int n;
	vector<int> t;

	seg_tree() {}
	seg_tree(int sz, int element) {
		n = sz;
		t.resize(4 * n);
		vector<int> a(n, element);
		build(a);
	}
	seg_tree(vector<int>& a) {
		n = a.size();
		t.resize(4 * n);
		build(a);
	}

	void build(vector<int>& a) {
		build(a, 1, 0, n - 1);
	}
	void build(vector<int>& a, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = a[tl];
		}
		else {
			int tm = (tl + tr) / 2;
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v] = min(t[v * 2] , t[v * 2 + 1]);
		}
	}

	int sum(int l, int r) {
		return sum(l, r, 1, 0, n - 1);
	}
	int sum(int l, int r, int v, int tl, int tr) {
		if (l > r)
			return 1e6;
		if (l == tl and r == tr) {
			return t[v];
		}
		int tm = (tl + tr) / 2;
		return min(sum(l, min(r, tm), v * 2, tl, tm),
			 sum(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr));
	}

	void update(int pos, int new_val) {
		update(pos, new_val, 1, 0, n - 1);
	}
	void update(int pos, int new_val, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = new_val;
		}
		else {
			int tm = (tl + tr) / 2;
			if (pos <= tm)
				update(pos, new_val, v * 2, tl, tm);
			else
				update(pos, new_val, v * 2 + 1, tm + 1, tr);
			t[v] = min(t[v * 2] , t[v * 2 + 1]);
		}
	}
};

seg_tree earliest;
set<pair<int, int>> segments;
set<pair<int, int>> gaps;

void new_update_erase(int gap, int start) {
	auto loc = gaps.lower_bound({ gap,-1 });
	if (*loc == make_pair(gap, start)) {
		loc++;
		if (loc->first == gap) {
			earliest.update(gap, loc->second);
		}
		else {
			earliest.update(gap, 1e6);
		}
	}
}

void new_update_insert(int gap, int start) {
	auto loc = gaps.lower_bound({ gap,-1 });
	if (*loc == pair<int, int>{gap, start}) {
		earliest.update(gap, start);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("seating.in", "r", stdin); freopen("seating.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> start(n + 1, 1e6);
	earliest = seg_tree(start);
	segments.insert({ 0,1 });
	segments.insert({ n + 1,1 });
	gaps.insert({ n,1 });
	earliest.update(n,1);
	int couldnt_seat = 0;

	while (m--) {
		char type; cin >> type;
		if (type == 'A') {
			int amt; cin >> amt;
			int loc = earliest.sum(amt,n);
			if (loc == 1e6) {
				couldnt_seat++;
			}
			else {
				auto after = segments.lower_bound({ loc,-1 });
				auto add_to = prev(after);
				new_update_erase(after->first - (add_to->first + add_to->second), add_to->first + add_to->second);
				gaps.erase({ after->first - (add_to->first + add_to->second), add_to->first + add_to->second });
				gaps.insert({ after->first - (add_to->first + add_to->second) - amt,add_to->first + add_to->second + amt });
				new_update_insert(after->first - (add_to->first + add_to->second) - amt, add_to->first + add_to->second + amt);
				auto new_seg = *add_to;
				new_seg.second += amt;
				segments.erase(add_to);
				segments.insert(new_seg);
			}
		}
		else {
			int a, b; cin >> a >> b;
			auto start = --segments.upper_bound({ a,-1 });
			if (b < start->first + start->second - 1) {
				if (start->first == a) {
					auto before = prev(start);
					segments.insert({ b + 1,start->second - (b - a + 1) });
					segments.erase(start);
					auto gap = --gaps.find({ a - (before->first + before->second),before->first + before->second });
					gaps.insert({ b + 1 - gap->second, gap->second });
					new_update_insert(b + 1 - gap->second, gap->second);
					new_update_erase(gap->first, gap->second);
					gaps.erase(gap);
				}
				else {
					gaps.insert({ b - a + 1,a });
					new_update_insert(b - a + 1, a);
					segments.insert({ start->first,a - start->first });
					segments.insert({ b + 1,start->first + start->second - (b + 1) });
					segments.erase(start);
				}
			}
			else {
				start = --segments.lower_bound({ a,-1 });
				for (auto loc = start; loc->first <= b;) {
					if (a <= loc->first and loc->first + loc->second - 1 <= b) {
						auto after = next(loc);
						new_update_erase(after->first - (loc->first + loc->second), loc->first + loc->second);
						gaps.erase({ after->first - (loc->first + loc->second),loc->first + loc->second });
						segments.erase(loc);
						loc = after;
					}
					else if (loc->first < a) {
						auto after = next(loc);
						new_update_erase(after->first - (loc->first + loc->second), loc->first + loc->second);
						gaps.erase({ after->first - (loc->first + loc->second),loc->first + loc->second });
						if (a <= loc->first + loc->second - 1) {
							segments.insert({ loc->first,a - loc->first });
							segments.erase(loc);
						}
						loc = after;
						
					}
					else if (a <= loc->first and loc->first <= b) {
						segments.insert({ b + 1,loc->first + loc->second - (b + 1) });
						auto after = next(loc);
						segments.erase(loc);
						loc = after;
					}
				}
				auto right = segments.lower_bound({ b,-1 });
				auto left = prev(right);
				gaps.insert({ right->first - (left->first + left->second),left->first + left->second });
				new_update_insert(right->first - (left->first + left->second), left->first + left->second);
			}
		}
	}

	cout << couldnt_seat << '\n';
}