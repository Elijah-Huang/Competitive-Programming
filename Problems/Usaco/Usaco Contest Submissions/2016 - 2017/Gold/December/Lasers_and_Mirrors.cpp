#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct point {
	int x, y, d, dir;
	bool operator==(const point& b) const {
		return x == b.x and y == b.y;
	}
};

struct point_cmp {
	bool operator()(const point& a, const point& b) const {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		else {
			return a.x < b.x;
		}
	}
};

struct point_cmp2 {
	int operator()(const point& a) const {
		return a.x ^ a.y;
	}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("lasers.in", "r", stdin); freopen("lasers.out", "w", stdout);
	int n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
	vector<map<int, unordered_set<point,point_cmp2>>> mirrors(2);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		mirrors[0][y].insert({ x,y });
		mirrors[1][x].insert({ x,y });
	}
	mirrors[0][y2].insert({ x2,y2 });
	mirrors[1][x2].insert({ x2,y2 });

	queue<point> q;
	q.push({ x1, y1, 0, 0 }), q.push({ x1,y1,0,1 });
	while (!q.empty()) {
		point curr = q.front(); q.pop();
		if (curr.x == x2 and curr.y == y2) {
			cout << curr.d - 1;
			return 0;
		}
		else {
			vector<point> to_erase;
			for (auto& neighbor : mirrors[curr.dir][(curr.dir ? curr.x : curr.y)]) {
				if (!(neighbor == curr)) {
					q.push({ neighbor.x, neighbor.y, curr.d + 1, !curr.dir });
					to_erase.push_back(neighbor);
				}
			}
			for (auto& p: to_erase) {
				mirrors[curr.dir][(curr.dir ? curr.x : curr.y)].erase(p);
				mirrors[!curr.dir][(!curr.dir ? curr.x : curr.y)].erase(p);
			}
		}

	}

	cout << -1;
}