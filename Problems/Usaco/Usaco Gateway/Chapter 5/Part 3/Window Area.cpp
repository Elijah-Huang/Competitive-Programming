/*
ID: elijahj1
TASK: window
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
struct window {
	int l, d, r, u;
	char w;
}; 
void dfs(int l, int r, int u, int d, int layer, int& visible, vector<window> windows) {
	if (layer == windows.size()) {
		visible += (u - d) * (r - l);
	}
	else {
		window& w = windows[layer];
		if ((w.r <= l or w.l >= r) or (w.u <= d or w.d >= u)) {
			dfs(l, r, u, d, layer + 1, visible, windows);
		}
		else {
			if (u > w.u) {
				dfs(max(l, w.l), min(r, w.r), u, w.u, layer + 1, visible, windows);
			}
			if (d < w.d) {
				dfs(max(l, w.l), min(r, w.r), w.d, d, layer + 1, visible, windows);
			}
			if (l < w.l) {
				dfs(l, w.l, u, d, layer + 1, visible, windows);
			}
			if (r > w.r) {
				dfs(w.r, r, u, d, layer + 1, visible, windows);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("window.in", "r", stdin); freopen("window.out", "w", stdout);
	cout << fixed << setprecision(3);
	vector<window> windows;
	int x, y, X, Y;
	char t, w, s;
	while (cin >> t) {
		if (t == 'w') {
			cin >> s >> w >> s >> x >> s >> y >> s >> X >> s >> Y >> s;
			windows.push_back(window{ min(x,X), min(y,Y) , max(x,X) , max(y,Y), w});
		}
		else if (t == 't'){
			cin >> s >> w >> s;
			window curr;
			for (int i = 0; i < windows.size(); i++) {
				if (windows[i].w == w) {
					windows.push_back(windows[i]);
					windows.erase(windows.begin() + i);
					break;
				}
			}
		}
		else if (t == 'b') {
			cin >> s >> w >> s;
			for (int i = 0; i < windows.size(); i++) {
				if (windows[i].w == w) {
					windows.insert(windows.begin(),windows[i]);
					windows.erase(windows.begin() + i + 1);
					break;
				}
			}
		}
		else if (t == 'd') {
			cin >> s >> w >> s;
			for (int i = 0; i < windows.size(); i++) {
				if (windows[i].w == w) {
					windows.erase(windows.begin() + i);
					break;
				}
			}
		}
		else {
			cin >> s >> w >> s;
			int start, total, visible = 0;
			for (int i = 0; i < windows.size(); i++) {
				if (windows[i].w == w) {
					start = i + 1;
					break;
				}
			}
			window& curr = windows[start - 1];
			total = (curr.r - curr.l) * (curr.u - curr.d);
			dfs(curr.l, curr.r, curr.u, curr.d, start, visible, windows);
			cout << (100.0 * visible / total) << '\n';
		}
	}
}