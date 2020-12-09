#include<bits/stdc++.h>
using namespace std;

struct square {
	int l, r, d, u;
	const bool operator==(const square& b) const {
		return l == b.l and r == b.r and d == b.d and u == b.u;
	}
};

struct square_cmp {
	const bool operator()(const square& a, const square& b) const {
		if (a.u != b.u) {
			return a.u < b.u;
		}
		else {
			return a.l < b.l;
		}
	}
};

bool intersect(square a, square b, int& k) {
	return abs(a.u - b.u) < k and abs(a.l - b.l) < k;
}

long long intersect_area(square a, square b) {
	return (long long)((min(a.r, b.r) - max(a.l, b.l))) * (min(a.u, b.u) - max(a.d, b.d));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("squares.in", "r", stdin); freopen("squares.out", "w", stdout);
	int n, k;
	long long ans = 0;
	cin >> n >> k;
	vector<square> squares;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		squares.push_back({ x - k / 2, x + k / 2, y - k / 2, y + k / 2 });
		squares.push_back({ x + k / 2, x - k / 2, y - k / 2, y + k / 2 });
	}
	sort(squares.begin(), squares.end(),
		[&](const square& a, const square& b) {if (a.l == b.l) {return a.r < b.r;}
		return a.l < b.l; });
	set<square, square_cmp> st;
	bool had_intersection = false;
	bool double_intersection = false;
	for (int i = 0; i < 2 * n; i++) {
		square& curr = squares[i];
		square reverse = { curr.r, curr.l, curr.d, curr.u };
		if (st.count(reverse)) {
			st.erase(reverse);
		}
		else if (curr.l < curr.r) {
			st.insert(curr);
			auto loc = st.find(curr);
			auto above = loc; above++;
			if (above != st.end()) {
				if (intersect(curr, *above, k)) {
					if (had_intersection) {
						double_intersection = true;
						ans = -1;
						break;
					}
					else {
						had_intersection = true;
						ans = intersect_area(curr, *above);
						for (int i = 0; i < 2 * n; i++) {
							if (squares[i].l < squares[i].r and !(squares[i] == curr)
								and !(squares[i] == *above)) {
								if (intersect(curr, squares[i], k)) {
									double_intersection = true; 
									break;
								}
							}
							if (squares[i].l < squares[i].r and !(squares[i] == *above)
								and !(squares[i] == curr)) {
								if (intersect(*above, squares[i], k)) {
									double_intersection = true;
									break;
								}
							}
						}
						if (double_intersection) {
							ans = -1;
							break;
						}
						else {
							auto val_above = *above;
							st.erase(curr);
							st.erase(val_above);
							continue;
						}
					}
				}
			}
			if (loc != st.begin()) {
				auto below = loc; below--;
				if (intersect(curr, *below, k)) {
					if (had_intersection) {
						double_intersection = true;
						ans = -1;
						break;
					}
					else {
						had_intersection = true;
						ans = intersect_area(curr, *below);
						for (int i = 0; i < 2 * n; i++) {
							if (squares[i].l < squares[i].r and !(squares[i] == curr)
								and !(squares[i] == *below)) {
								if (intersect(curr, squares[i], k)) {
									double_intersection = true;
									break;
								}
							}
							if (squares[i].l < squares[i].r and !(squares[i] == *below)
								and !(squares[i] == curr)) {
								if (intersect(*below, squares[i], k)) {
									double_intersection = true;
									break;
								}
							}
						}
						if (double_intersection) {
							ans = -1;
							break;
						}
						else {
							auto val_below = *below;
							st.erase(curr);
							st.erase(val_below);
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
}