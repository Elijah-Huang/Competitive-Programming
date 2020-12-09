#include<bits/stdc++.h>
using namespace std;

struct mountain {
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("mountains.in", "r", stdin); freopen("mountains.out", "w", stdout);
	int n;
	cin >> n;
	vector<mountain> mountains(n);
	vector<bool> visible(n, 1);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		mountains[i] = { x,y };
	}
	sort(mountains.begin(), mountains.end(),
		[&](const mountain& a, const mountain& b) {return a.x < b.x; });
	int lastx = mountains[0].x;
	int lasty = mountains[0].y;
	for (int i = 1; i < n; i++) {
		if (lasty - mountains[i].y >= mountains[i].x - lastx) {
			visible[i] = 0;
		}
		else {
			lastx = mountains[i].x;
			lasty = mountains[i].y;
		}
	}
	lasty = 0; 
	lastx = int(1e9);
	for (int i = n - 1; i >= 0; i--) {
		if (!visible[i]) continue;
		if (lasty - mountains[i].y >= lastx - mountains[i].x) {
			visible[i] = 0;
		}
		else {
			lastx = mountains[i].x;
			lasty = mountains[i].y;
		}
	}
	cout << accumulate(visible.begin(), visible.end(), 0);
}