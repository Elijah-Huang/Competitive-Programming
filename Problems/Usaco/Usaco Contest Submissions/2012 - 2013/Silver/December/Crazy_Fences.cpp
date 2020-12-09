#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

struct point {
	int x, y;
	bool operator==(const point& b) const {
		return b.x == x and b.y == y;
	}
};

struct point_cmp {
	size_t operator()(const point& a) const {
		return a.x ^ a.y;
	}
};

struct segment {
	int x1, x2, y1, y2;
};
bool intersect(segment a, segment b) {

	//setup x1,y1 as startpoint(leftmost endpoint)
	if (a.x1 > a.x2) {
		swap(a.x1, a.x2); swap(a.y1, a.y2);
	}
	if (b.x1 > b.x2) {
		swap(b.x1, b.x2); swap(b.y1, b.y2);
	}

	//impossible to intersect?
	if (b.x2 < a.x1 or a.x2 < b.x1) {
		return false;
	}
	
	// both vertical lines
	if (a.x1 == a.x2 and b.x1 == b.x2) {
		return a.x1 == b.x1 and (!(min(a.y1, a.y2) > max(b.y1, b.y2)
			or min(b.y1, b.y2) > max(a.y1, a.y2)));
	}

	// making start points equal
	if (a.x1 < b.x1) {
		a.y1 += double(a.y2 - a.y1) / (a.x2 - a.x1) * (b.x1 - a.x1);
		a.x1 = b.x1;
	}
	else if (b.x1 < a.x1) {
		b.y1 += double(b.y2 - b.y1) / (b.x2 - b.x1) * (a.x1 - b.x1);
		b.x1 = a.x1;
	}

	// one vertical line
	if (a.x1 == a.x2) {
		return a.y1 >= b.y1 and b.y1 >= a.y2;
	}
	else if (b.x1 == b.x2) {
		return b.y1 >= a.y1 and a.y1 >= b.y2;
	}

	// both are diagonals or horizontal
	if (a.y1 < b.y1) {
		swap(a, b);
	}
	double m1 = (double(a.y2 - a.y1) / (a.x2 - a.x1));
	double m2 = (double(b.y2 - b.y1) / (b.x2 - b.x1));
	return (a.y1 - b.y1 - 1e-8 <= (m2 - m1) * (min(a.x2, b.x2) - a.x1));
}

bool inside_polygon(point& test, vector<point>& polygon) {
	bool ans = 0;
	for (int i = 0; i < polygon.size() - 1; i++) {
		point v1 = polygon[i];
		point v2 = polygon[i + 1];
		// the ray you pick should be (x,y) and (x + 1, max y in prob)
		ans ^= intersect({ v1.x,v2.x,v1.y,v2.y }, { test.x, test.x + 1, test.y, int(1e6) });
	}
	return ans;

}

// polygon has all points in polygon except also with start point repeated at the end
// one edge case is when vertical line with y = test.y is an edge
/*
bool inside_polygon(point& test, vector<point>& polygon) {
	bool ans = 0;
	for (int i = 0; i < polygon.size() - 1; i++) {
		point v1 = polygon[i];
		point v2 = polygon[i + 1];
		if ((v1.y < test.y and v2.y < test.y) or (v1.y > test.y and v2.y > test.y)) {
			continue;
		}
		else if (v1.y == v2.y and test.y == v1.y) {
			ans ^= 1;
			continue;
		}
		double x_cord = x_cord = v1.x + double(v2.x - v1.x) / (v2.y - v1.y) * (test.y - v1.y);
		if (fabs(test.x - x_cord) < 1e-3) {
			return 0;
		}
		ans ^= (x_cord < test.x);
	}
	// if a vertex has y = test.y u double count it if this vertex "acts as an edge"
	for (int i = 0; i < polygon.size() - 1; i++) {
		ans ^= (polygon[i].y == test.y
			and (polygon[(i + 1)].y > test.y and test.y > polygon[(i - 1 - (i == 0)) % polygon.size()].y
			or polygon[(i + 1)].y < test.y and test.y < polygon[(i - 1 - (i == 0)) % polygon.size()].y)
			and polygon[i].x < test.x);
	}
	return ans;
}
*/
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("crazy.in", "r", stdin); freopen("crazy.out", "w", stdout);
	int n, c;
	cin >> n >> c;
	vector<point> points;
	vector<point> cows;
	unordered_map<point, vector<point>, point_cmp> adj;
	vector<vector<point>> polygons;
	vector<pair<point,int>> polygon_idx;
	vector<int> community_size;
	unordered_map<point, bool, point_cmp> visited;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		point point1 = { x1,y1 };
		point point2 = { x2,y2 };
		points.push_back(point1);
		points.push_back(point2);
		adj[point1].push_back(point2);
		adj[point2].push_back(point1);
		visited[point1] = 0;
		visited[point2] = 0;
	}
	for (int i = 0; i < c; i++) {
		int x, y;
		cin >> x >> y;
		cows.push_back({ x,y });
	}
	int curr_polygon = -1;
	for (point p : points) {
		if (!visited[p]) {
			curr_polygon++;
			polygons.resize(curr_polygon + 1);
			point curr = p;
			bool found = true;
			while (found) {
				visited[curr] = 1;
				polygons[curr_polygon].push_back(curr);
				found = false;
				for (auto neighbor : adj[curr]) {
					if (!visited[neighbor]) {
						found = true;
						curr = neighbor;
						break;
					}
				}
			}
			polygons[curr_polygon].push_back(p);
		}
	}
	for (int i = 0; i < polygons.size(); i++) {
		point highest = polygons[i][0];
		for (int j = 1; j < polygons[i].size(); j++) {
			if (highest.y < polygons[i][j].y) {
				highest = polygons[i][j];
			}
		}
		polygon_idx.push_back({ highest, i });
	}

	sort(polygon_idx.begin(), polygon_idx.end(),
		[&](const pair<point, int>& a, const pair<point, int> b) {return a.first.y < b.first.y; });

	community_size.resize(curr_polygon + 2);
	for (auto c : cows) {
		bool found = false;
		for (int i = 0; i < polygons.size(); i++) {
			auto p = polygons[polygon_idx[i].second];
			if (inside_polygon(c, p)) {
				found = true;
				community_size[i]++;
				break;
			}
		}
		if (!found) {
			community_size[community_size.size() - 1]++;
		}
	}
	
	/*cout << '\n';
	for (auto p : polygons) {
		for (auto i : p) {
			cout << i.x << ' ' << i.y << '\n';
		}
		cout << '\n';
	}
	for (auto i : community_size) {
		cout << i << '\n';
	}
	*/
	cout << *max_element(community_size.begin(), community_size.end());
}