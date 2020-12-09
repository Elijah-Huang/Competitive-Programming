#include<bits/stdc++.h>
using namespace std;

struct line {
	int x1, y1, x2, y2;
	bool operator==(const line& b) const {
		return x1 == b.x1 and y1 == b.y1 and x2 == b.x2 and y2 == b.y2;
	}
};

struct line_cmp {
	bool operator()(const line& a, const line& b) const {
		if (a.x1 == b.x1) {
			return a.y1 > b.y1;
		}
		else if (a.x1 < b.x1) {
			double new_y = a.y1 + (double(a.y2 - a.y1) / (a.x2 - a.x1)) * (b.x1 - a.x1);
			return new_y > b.y1;
		}
		else {
			double new_y = b.y1 + (double(b.y2 - b.y1) / (b.x2 - b.x1)) * (a.x1 - b.x1);
			return a.y1 > new_y;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("hillwalk.in", "r", stdin); freopen("hillwalk.out", "w", stdout);
	int n; cin >> n;
	int hills_visited = 0;
	line curr_hill;
	line_cmp above;
	set<line, line_cmp> active;
	vector<line> hills(n);
	for (int i = 0; i < n; i++) {
		cin >> hills[i].x1 >> hills[i].y1 >> hills[i].x2 >> hills[i].y2;
		hills.push_back({ hills[i].x2,hills[i].y2,hills[i].x1,hills[i].y1 });
	}
	
	sort(hills.begin(), hills.end(), [&](const line& a, const line& b) {if (a.x1 == b.x1) { return a.y1 < b.y1; } else { return a.x1 < b.x1; }});
	
	curr_hill = hills[0];
	hills_visited++;
	for (int i = 1; i < 2 * n; i++) {
		if (hills[i].x1 > hills[i].x2) {
			line true_hill = { hills[i].x2,hills[i].y2,hills[i].x1,hills[i].y1 };
			if (true_hill == curr_hill) {
				if (!active.empty()) {
					curr_hill = *active.begin();
					active.erase(active.begin());
					hills_visited++;
				}
				else {
					break;
				}
			}
			else {
				active.erase(true_hill);
			}
		}
		else {
			if (above(curr_hill, hills[i])) {
				active.insert(hills[i]);
			}
		}
	}

	cout << hills_visited;
}