/*
ID: elijahj1
TASK: picture
LANG: C++14
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define f first
#define s second

struct rectangle {
	vector<vector<int>> coord;
	rectangle() {
		coord = vector<vector<int>>(2, vector<int>(2));
	}
};

struct line {
	vector<int> endpoints;
};

// official solution much simpler but this works independent of sizes of rectangles
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("picture.in", "r", stdin); freopen("picture.out", "w", stdout);
	int n; cin >> n;
	vector<vector<rectangle>> rectangles(2,vector<rectangle>(n));
	vector<vector<unordered_map<int, vector<line>>>> lines(2, vector<unordered_map<int, vector<line>>>(2));
	for (int i = 0; i < n; i++) {
		cin >> rectangles[0][i].coord[0][0] >> rectangles[0][i].coord[1][0] >> rectangles[0][i].coord[0][1] >> rectangles[0][i].coord[1][1];
		rectangles[1][i] = rectangles[0][i];
		for (int axis = 0; axis < 2; axis++) {
			for (int side = 0; side < 2; side++) {
				lines[axis][side][rectangles[0][i].coord[axis][side]].push_back({ rectangles[0][i].coord[axis ^ 1] });
			}
		}
	}

	sort(rectangles[0].begin(), rectangles[0].end(), [&](rectangle& a, rectangle& b) {return a.coord[0][0] < b.coord[0][0]; });
	sort(rectangles[1].begin(), rectangles[1].end(), [&](rectangle& a, rectangle& b) {return a.coord[1][0] < b.coord[1][0]; });

	int total_perimeter = 0;
	for (int axis = 0; axis < 2; axis++) {
		for (int side = 0; side < 2; side++) {
			for (auto a = lines[axis][side].begin(); a != lines[axis][side].end();) {
				auto st = *a;
				for (int i = 0; i < st.s.size(); i++) {
					for (int j = 0; j < st.s.size(); j++){
						if (i == j) continue;
						if (st.s[j].endpoints[0] <= st.s[i].endpoints[1] and st.s[i].endpoints[1] <= st.s[j].endpoints[1]) {
							st.s[i].endpoints[1] = max(st.s[i].endpoints[0], st.s[j].endpoints[0]);
						}
						else if (st.s[j].endpoints[0] <= st.s[i].endpoints[0] and st.s[i].endpoints[0] <= st.s[j].endpoints[1]) {
							st.s[i].endpoints[0] = min(st.s[i].endpoints[1], st.s[j].endpoints[1]);
						}
					}
				}
				sort(st.s.begin(), st.s.end(), [&](const line& a, const line& b) {return a.endpoints[0] < b.endpoints[0]; });
				int start_j = 0;
				for (int i = 0; i < n; i++) {
					if (rectangles[axis^1][i].coord[axis][0] < st.f and st.f < rectangles[axis^1][i].coord[axis][1]
						or rectangles[axis^1][i].coord[axis][side^1] == st.f) {
						while (start_j < st.s.size() and st.s[start_j].endpoints[1] < rectangles[axis ^ 1][i].coord[axis ^ 1][0]) {
							start_j++;
						}
						if (start_j == st.s.size()) {
							break;
						}
						for (int j = start_j; j < st.s.size(); j++) {
							if (rectangles[axis^1][i].coord[axis^1][0] <= st.s[j].endpoints[1] and st.s[j].endpoints[1] <= rectangles[axis^1][i].coord[axis ^ 1][1]) {
								st.s[j].endpoints[1] = max(st.s[j].endpoints[0], rectangles[axis^1][i].coord[axis ^ 1][0]);
							}
							else if (rectangles[axis^1][i].coord[axis ^ 1][0] <= st.s[j].endpoints[0] and st.s[j].endpoints[0] <= rectangles[axis^1][i].coord[axis ^ 1][1]) {
								st.s[j].endpoints[0] = min(st.s[j].endpoints[1], rectangles[axis^1][i].coord[axis ^ 1][1]);
							}
							else if (st.s[j].endpoints[0] <= rectangles[axis^1][i].coord[axis ^ 1][0] and rectangles[axis^1][i].coord[axis ^ 1][1] <= st.s[j].endpoints[1]) {
								st.s.push_back({ {rectangles[axis^1][i].coord[axis ^ 1][1], st.s[j].endpoints[1]} });
								st.s[j].endpoints[1] = rectangles[axis^1][i].coord[axis ^ 1][0];
							}
						}
					}
				}
				for (auto& l : st.s) {
					total_perimeter += l.endpoints[1] - l.endpoints[0];
				}
				auto nxt = a;
				nxt++;
				lines[axis][side].erase(a);
				a = nxt;
			}
		}
	}

	cout << total_perimeter << '\n';
}