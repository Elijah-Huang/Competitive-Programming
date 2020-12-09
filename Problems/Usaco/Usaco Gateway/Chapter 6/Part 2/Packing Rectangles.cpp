/*
ID: elijahj1
TASK: packrec
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

struct rect {
	int a, b;
};

vector<rect> min_rects;

void solve(vector<rect>& rects) {
	vector<int> perm = { 0,1,2,3 };
	do {
		min_rects.push_back({ rects[perm[0]].a + rects[perm[1]].a + rects[perm[2]].a + rects[perm[3]].a,
			max({rects[perm[0]].b, rects[perm[1]].b, rects[perm[2]].b, rects[perm[3]].b}) });
		min_rects.push_back({ max({rects[perm[0]].a, rects[perm[1]].a + rects[perm[2]].a + rects[perm[3]].a}),
			rects[perm[0]].b + max({rects[perm[1]].b, rects[perm[2]].b, rects[perm[3]].b }) });
		min_rects.push_back({ rects[perm[1]].a + max(rects[perm[0]].a, rects[perm[2]].a + rects[perm[3]].a),
			max(rects[perm[1]].b, rects[perm[0]].b + max(rects[perm[2]].b, rects[perm[3]].b)) });
		min_rects.push_back({ rects[perm[0]].a + max(rects[perm[1]].a,rects[perm[3]].a) + rects[perm[2]].a ,
			max({rects[perm[0]].b, rects[perm[1]].b + rects[perm[3]].b, rects[perm[2]].b}) });
		min_rects.push_back({ max(rects[perm[3]].a,rects[perm[0]].a) + rects[perm[1]].a + rects[perm[2]].a,
			max({rects[perm[0]].b + rects[perm[3]].b, rects[perm[1]].b,rects[perm[2]].b }) });
		if (rects[perm[0]].b <= rects[perm[1]].b) {
			if (rects[perm[0]].b + rects[perm[3]].b > rects[perm[1]].b and rects[perm[2]].a > rects[perm[1]].a) {
				min_rects.push_back({ max(rects[perm[0]].a + rects[perm[1]].a, rects[perm[2]].a + rects[perm[3]].a),
					max(rects[perm[0]].b + rects[perm[3]].b, rects[perm[1]].b + rects[perm[2]].b) });
			}
			else {
				min_rects.push_back({ max(max(rects[perm[0]].a, rects[perm[3]].a) + rects[perm[1]].a,rects[perm[2]].a),
					max(rects[perm[0]].b + rects[perm[3]].b, rects[perm[1]].b + rects[perm[2]].b) });
			}
		}
	} while (next_permutation(perm.begin(), perm.end()));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("packrec.in", "r", stdin); freopen("packrec.out", "w", stdout);
	vector<rect> rectangles(4);
	for (int i = 0; i < 4; i++) {
		cin >> rectangles[i].a >> rectangles[i].b;
	}

	for (int i = 0; i < 16; i++) {
		vector<rect> new_rects;
		for (int j = 0; j < 4; j++) {
			if ((i >> j) & 1) {
				new_rects.push_back({ rectangles[j].b, rectangles[j].a });
			}
			else {
				new_rects.push_back(rectangles[j]);
			}
		}
		solve(new_rects);
	}

	int mn = 1e9;
	set<pair<int, int>> best;
	for (int i = 0; i < min_rects.size(); i++) {
		if (min_rects[i].a > min_rects[i].b) {
			swap(min_rects[i].a, min_rects[i].b);
		}
		if (min_rects[i].a * min_rects[i].b < mn){
			mn = min_rects[i].a * min_rects[i].b;
			best = { {min_rects[i].a , min_rects[i].b }};
		}
		else if (min_rects[i].a * min_rects[i].b == mn) {
			best.insert({ min_rects[i].a , min_rects[i].b });
		}
	}

	cout << mn << '\n';
	for (auto sides : best) {
		cout << sides.first << ' ' << sides.second << '\n';
	}
}