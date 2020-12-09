#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
/*
vector<int> dx = { 1 , 0, -1, 0 };
vector<int> dy = { 0, 1, 0, -1 };
*/
struct point {
	int x, y;
	const bool operator==(const point& b) const {
		return x == b.x and y == b.y;
	}
};

struct point_hash {
	const size_t operator()(const point& a) const {
		return 2*a.x ^ a.y;
	}
};

struct point_cmp {
	const bool operator()(const point& a, const point& b) const {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		else {
			return a.x < b.x;
		}
	}
};

/*bool isvalid(point& a, point& b, unordered_set<point, point_hash>& bales) {
	if (a.x == b.x) {
		return bales.count({ a.x,min(a.y,b.y) }) ^ bales.count({ a.x - 1,min(a.y,b.y) });
	}
	else {
		return bales.count({ min(a.x,b.x),a.y }) ^ bales.count({ min(a.x,b.x),a.y - 1 });
	}
}
void dfs(point curr, point parent, unordered_set<point, point_hash>& vertices,
	int& mx_perimeter ) {

}*/
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("perimeter.in", "r", stdin); freopen("perimeter.out", "w", stdout);
	int n;
	cin >> n;
	point start = { 1 << 30, 1 << 30 };
	unordered_set<point, point_hash> bales;
	//unordered_set<point, point_hash> vertices;
	//unordered_set<point, point_hash> visited;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		bales.insert({ x,y });
		if (x < start.x) {
			start = { x,y };
		}
		else if (x == start.x) {
			start.y = min(start.y, y);
		}
	}
	int perimeter = 0;
	point curr = start;
	int direction;
	while (!(curr == start) or perimeter == 0) {
		vector<int> worked;
		if (bales.count(curr) and !bales.count({ curr.x,curr.y - 1 })) {
			worked.push_back(0);
		}
		if (bales.count({ curr.x - 1, curr.y }) 
			and !bales.count(curr)) {
			worked.push_back(1);
		}
		if (bales.count({ curr.x - 1, curr.y - 1 })
			and !bales.count({ curr.x - 1,curr.y })) {
			worked.push_back(2);
		}
		if (bales.count({ curr.x, curr.y - 1 })
			and !bales.count({ curr.x -1,curr.y - 1 })) {
			worked.push_back(3);
		}
		if (perimeter) {
			while (direction != worked[0] and (worked.size() == 1 or direction != worked[1])) {
				direction = (direction + 3) % 4;
			}
		}
		else {
			direction = worked[0];
		}
		switch (direction) {
			case 0:
				curr.x++;
				break;
			case 1:
				curr.y++;
				break;
			case 2:
				curr.x--;
				break;
			case 3:
				curr.y--;
				break;
		}
		perimeter++;
	}
	cout << perimeter;
	/*for (auto bale : bales) {
		vector<point> consider = { {bale.x,bale.y}, {bale.x + 1, bale.y},
			{bale.x + 1, bale.y + 1}, {bale.x, bale.y + 1} };
		for (auto p : consider) {
			if (!vertices.count(p)) {
				bool surround = true;
				for (int i = 0; i < 4; i++) {
					if (!bales.count({ p.x + dx[i], p.x + dy[i] })) {
						surround = false;
						break;
					}
				}
				if (!surround) {
					vertices.insert(p);
				}
			}
		}
	}*/
}