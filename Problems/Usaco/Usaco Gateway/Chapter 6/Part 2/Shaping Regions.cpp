/*
ID: elijahj1
TASK: rect1
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

struct rect {
	int x1, y1, x2, y2, c;
};

vector<rect> rectangles;

int solve(rect curr, int idx) {
	if (idx == rectangles.size() or curr.x1 == curr.x2 or curr.y1 == curr.y2) {
		return (curr.y2 - curr.y1) * (curr.x2 - curr.x1);
	}
	else {
		if (not(rectangles[idx].x1 >= curr.x2 or rectangles[idx].x2 <= curr.x1) and
			not(rectangles[idx].y1 >= curr.y2 or rectangles[idx].y2 <= curr.y1)) {
			int l_bound = max(rectangles[idx].x1, curr.x1);
			int r_bound = min(rectangles[idx].x2, curr.x2);
			int u_bound = min(rectangles[idx].y2, curr.y2);
			int d_bound = max(rectangles[idx].y1, curr.y1);
			return solve({ l_bound, u_bound, r_bound, curr.y2 }, idx + 1) +
				solve({ l_bound, curr.y1, r_bound, d_bound }, idx + 1) +
				solve({ curr.x1, curr.y1, l_bound, curr.y2 }, idx + 1) +
				solve({ r_bound, curr.y1, curr.x2, curr.y2 }, idx + 1);
		}
		else {
			return solve(curr, idx + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("rect1.in", "r", stdin); freopen("rect1.out", "w", stdout);
	int a, b, n; cin >> a >> b >> n;
	vector<int> colors(2501);
	rectangles.resize(n + 1);
	rectangles[0] = { 0,0,a,b,1 };
	for (int i = 1; i <= n; i++) {
		cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >> rectangles[i].y2 >> rectangles[i].c;
	}

	for (int i = 0; i <= n; i++) {
		colors[rectangles[i].c] += solve(rectangles[i], i + 1);
	}

	for (int c = 1; c <= 2500; c++) {
		if (colors[c]) {
			cout << c << ' ' << colors[c] << '\n';
		}
	}
}