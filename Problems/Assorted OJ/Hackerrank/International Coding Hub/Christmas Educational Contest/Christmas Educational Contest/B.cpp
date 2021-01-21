#include<bits/stdc++.h>
using namespace std;

struct rect {
	int x1, y1, x2, y2;
};

const int maxn = 1e4;
int n, colors;
rect rects[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
	}

	colors = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			if (rects[j].x1 <= rects[i].x1 and
				rects[j].x2 >= rects[i].x2 and
				rects[j].y1 <= rects[i].y1 and
				rects[j].y2 >= rects[i].y2) {
				colors--;
				break;
			}
		}
	}

	cout << colors << '\n';
}