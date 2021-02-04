#include<bits/stdc++.h>
using namespace std;

struct mirror {
	int x, y, t;
};

struct loc {
	int x, y, dir;
};

struct query {
	int val1, val2, common;
};

struct BIT {
	int n;
	vector<int> a;

	BIT() {}
	BIT(int n) {
		this->n = n + 1;
		a.resize(this->n);
	}

	int sum_p(int idx) {
		int res = 0;
		for (idx++; idx > 0; idx -= idx & -idx) {
			res += a[idx];
		}
		return res;
	}

	int sum(int l, int r) {
		if (l > r) {
			return 0;
		}
		return sum_p(r) - sum_p(l - 1);
	}

	void update(int idx, int val) {
		int change = val - a[idx];
		if (change == 0) {
			return;
		}
		a[idx] = val;
		for (idx++; idx < n; idx += idx & -idx) {
			a[idx] += change;
		}
	}
};

const int maxn = 1e5+1;

long long ans = 0;

int n, bx, by;

mirror x_points[maxn], y_points[maxn];
map<int, int> convert_x, convert_y;
map<int, vector<mirror>> x_points2, y_points2;

// left = 0, right = 1, down = 2, up = 3 | '/' = 0, '\' = 1;
int convert_dir[4][2] = { {2,3}, {3,2}, {0,1}, {1,0} };
int rev_dir[4] = { 1,0,3,2 };

vector<mirror> end_mirrors[4];
vector<query> x_queries, y_queries;
BIT bits[4];

void search(loc curr, int type) {
	while (true) {
		//cout << curr.x << ' ' << curr.y << ' ' << curr.dir << '\n';
		if (type) {
			if (curr.dir >= 2) {
				auto curr_loc = lower_bound(end_mirrors[rev_dir[curr.dir]].begin(), end_mirrors[rev_dir[curr.dir]].end(), mirror{ curr.x, curr.y }, [&](const mirror& a, const mirror& b) {if (a.y == b.y) { return a.x < b.x; } return a.y < b.y; });
				//cout << curr_loc->x << ' ' << curr_loc->y << ' ' << curr_loc->t << '\n';
				if (curr_loc->t) {
					break;
				}
				else {
					curr_loc->t = 1;
				}
			}
			else {
				auto curr_loc = lower_bound(end_mirrors[rev_dir[curr.dir]].begin(), end_mirrors[rev_dir[curr.dir]].end(), mirror{ curr.x, curr.y }, [&](const mirror& a, const mirror& b) {if (a.x == b.x) { return a.y < b.y; } return a.x < b.x; });
				if (curr_loc->t) {
					break;
				}
				else {
					curr_loc->t = 1;
				}
			}
		}
		//cout << curr.x << ' ' << curr.y << ' ' << curr.dir << '\n';
		if (curr.dir >= 2) {
			vector<mirror>& ys = x_points2[curr.x];

			if (curr.dir == 2) {
				int idx = lower_bound(ys.begin(), ys.end(), mirror{ curr.x,curr.y }, [&](const mirror& a, const mirror& b) {return a.y < b.y; }) - ys.begin() - 1;
				if (idx < 0) {
					if (type ^ 1) {
						x_queries.push_back({ int(-1e9-1),curr.y,curr.x });
					}
					break;
				}

				if (type ^ 1) {
					x_queries.push_back({ ys[idx].y, curr.y,curr.x });
				}
				curr = { ys[idx].x,ys[idx].y, convert_dir[curr.dir][ys[idx].t] };
			}
			else {
				int idx = upper_bound(ys.begin(), ys.end(), mirror{ curr.x,curr.y }, [&](const mirror& a, const mirror& b) {return a.y < b.y; }) - ys.begin();
				if (idx == ys.size()) {
					if (type ^ 1) {
						x_queries.push_back({ curr.y,int(1e9+1),curr.x });
					}
					break;
				}

				if (type ^ 1) {
					x_queries.push_back({ curr.y,ys[idx].y,curr.x });
				}
				curr = { ys[idx].x,ys[idx].y, convert_dir[curr.dir][ys[idx].t] };
			}
		}
		else {
			vector<mirror>& xs = y_points2[curr.y];

			if (curr.dir == 0) {
				int idx = lower_bound(xs.begin(), xs.end(), mirror{ curr.x,curr.y }, [&](const mirror& a, const mirror& b) {return a.x < b.x; }) - xs.begin() - 1;
				if (idx < 0) {
					if (type ^ 1) {
						y_queries.push_back({ int(-1e9-1),curr.x,curr.y });
					}
					break;
				}

				if (type ^ 1) {
					y_queries.push_back({ xs[idx].x,curr.x,curr.y });
				}
				curr = { xs[idx].x,xs[idx].y, convert_dir[curr.dir][xs[idx].t] };
			}
			else {
				int idx = upper_bound(xs.begin(), xs.end(), mirror{ curr.x,curr.y }, [&](const mirror& a, const mirror& b) {return a.x < b.x; }) - xs.begin();
				if (idx == xs.size()) {
					if (type ^ 1) {
						y_queries.push_back({ curr.x,int(1e9+1),curr.y });
					}
					break;
				}

				if (type ^ 1) {
					y_queries.push_back({ curr.x,xs[idx].x,curr.y });
				}
				curr = { xs[idx].x,xs[idx].y, convert_dir[curr.dir][xs[idx].t] };
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("optics.in","r", stdin); freopen("optics.out","w", stdout);
	
	cin >> n >> bx >> by;

	for (int i = 0; i < n; i++) {
		char c;
		cin >> x_points[i].x >> x_points[i].y >> c;
		if (c == '/') {
			x_points[i].t = 0;
		}
		else {
			x_points[i].t = 1;
		}
	}
	x_points[n] = { bx,by,0 };

	convert_x[-1e9 - 1] = 0;
	convert_x[1e9 + 1] = n + 2;
	sort(x_points, x_points + n + 1, [&](const mirror& a, const mirror& b) {if (a.x == b.x) { return a.y < b.y; } return a.x < b.x; });
	for (int i = 0; i <= n; i++) {
		convert_x[x_points[i].x] = i+1;
		if (x_points[i].x != bx or x_points[i].y != by) {
			x_points2[x_points[i].x].push_back(x_points[i]);
		}
	}

	convert_y[-1e9 - 1] = 0;
	convert_y[1e9 + 1] = n + 2;
	memcpy(y_points, x_points, sizeof(x_points));
	sort(y_points, y_points + n + 1, [&](const mirror& a, const mirror& b) {if (a.y == b.y) { return a.x < b.x; }return a.y < b.y; });
	for (int i = 0; i <= n; i++) {
		convert_y[y_points[i].y] = i+1;
		if (y_points[i].x != bx or y_points[i].y != by) {
			y_points2[y_points[i].y].push_back(y_points[i]);
		}
	}

	for (auto& a : y_points2) {
		sort(a.second.begin(), a.second.end(), [&](const mirror& a, const mirror& b) {return a.x < b.x; });
	}
	for (auto& a : x_points2) {
		sort(a.second.begin(), a.second.end(), [&](const mirror& a, const mirror& b) {return a.y < b.y; });
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= n; j++) {
			end_mirrors[i].push_back(x_points[j]);
			end_mirrors[i].back().t = 0;
		}
	}
	for (int i = 2; i < 4; i++) {
		for (int j = 0; j <= n; j++) {
			end_mirrors[i].push_back(y_points[j]);
			end_mirrors[i].back().t = 0;
		}
	}

	// find the rays of the lazer from the start
	search({ 0,0,3 }, 0);
	// find the direction that a lazer needs to hit certain mirrors to reach the barn; call these mirrors "ending mirrors"
	for (int dir = 0; dir < 4; dir++) {
		search({ bx,by, dir }, 1);
	}

	y_points2[by].push_back({ bx,by });
	x_points2[bx].push_back({ bx,by });
	sort(x_points2[bx].begin(), x_points2[bx].end(), [&](const mirror& a, const mirror& b) {return a.y < b.y; });
	sort(y_points2[by].begin(), y_points2[by].end(), [&](const mirror& a, const mirror& b) {return a.x < b.x; });

	for (auto& a : y_points2) {
		int y = a.first;
		for (int i = 0; i < int(a.second.size()) - 1; i++) {
			int x1 = a.second[i].x, x2 = a.second[i + 1].x;
			auto loc1 = lower_bound(end_mirrors[0].begin(), end_mirrors[0].end(), mirror{ x1,y }, [&](const mirror& a, const mirror& b) {if (a.x == b.x) { return a.y < b.y; } return a.x < b.x; });
			auto loc2 = lower_bound(end_mirrors[1].begin(), end_mirrors[1].end(), mirror{ x2,y }, [&](const mirror& a, const mirror& b) {if (a.x == b.x) { return a.y < b.y; } return a.x < b.x; });

			if (loc1->t and loc2->t) {
				loc1->t = 0;
			}
		}
	}
	for (auto& a : x_points2) {
		int x = a.first;
		for (int i = 0; i < int(a.second.size()) - 1; i++) {
			int y1 = a.second[i].y, y2 = a.second[i + 1].y;
			auto loc1 = lower_bound(end_mirrors[2].begin(), end_mirrors[2].end(), mirror{ x,y1 }, [&](const mirror& a, const mirror& b) {if (a.y == b.y) { return a.x < b.x; } return a.y < b.y; });
			auto loc2 = lower_bound(end_mirrors[3].begin(), end_mirrors[3].end(), mirror{ x,y2 }, [&](const mirror& a, const mirror& b) {if (a.y == b.y) { return a.x < b.x; } return a.y < b.y; });

			if (loc1->t and loc2->t) {
				loc1->t = 0;
			}
		}
	}

	sort(x_queries.begin(), x_queries.end(), [&](const query& a, const query& b) {return a.common < b.common; });
	sort(y_queries.begin(), y_queries.end(), [&](const query& a, const query& b) {return a.common < b.common; });

	for (int i = 0; i < 4; i++) {
		bits[i] = BIT(n+3);
	}
	
	// sweepline and update bit offline, answering a query is just finding the number of possible "ending mirrors" that 
	// could be reached via redirecting the ray represented by the query
	int ptr = 0;
	for (int i = 0; i < x_queries.size(); i++) {
		while (ptr < end_mirrors[0].size()-1 and end_mirrors[0][ptr].x < x_queries[i].common) {
			bits[0].update(convert_y[end_mirrors[0][ptr].y], end_mirrors[0][ptr].t);
			ptr++;
		}

		ans += bits[0].sum(convert_y[x_queries[i].val1] + 1, convert_y[x_queries[i].val2] - 1);
	}
	ptr = end_mirrors[1].size()-1;
	for (int i = x_queries.size() - 1; i >= 0; i--) {
		while (ptr >= 0 and end_mirrors[1][ptr].x > x_queries[i].common) {
			bits[1].update(convert_y[end_mirrors[1][ptr].y], end_mirrors[1][ptr].t);
			ptr--;
		}

		ans += bits[1].sum(convert_y[x_queries[i].val1] + 1, convert_y[x_queries[i].val2] - 1);
	}
	ptr = 0;
	for (int i = 0; i < y_queries.size(); i++) {
		while (ptr < end_mirrors[2].size() - 1 and end_mirrors[2][ptr].y < y_queries[i].common) {
			bits[2].update(convert_x[end_mirrors[2][ptr].x], end_mirrors[2][ptr].t);
			ptr++;
		}

		ans += bits[2].sum(convert_x[y_queries[i].val1] + 1, convert_x[y_queries[i].val2] - 1);
	}
	ptr = end_mirrors[3].size() - 1;
	for (int i = y_queries.size() - 1; i >= 0; i--) {
		while (ptr >= 0 and end_mirrors[3][ptr].y > y_queries[i].common) {
			bits[3].update(convert_x[end_mirrors[3][ptr].x], end_mirrors[3][ptr].t);
			ptr--;
		}

		ans += bits[3].sum(convert_x[y_queries[i].val1] + 1, convert_x[y_queries[i].val2] - 1);
	}
	
	cout << ans;
}