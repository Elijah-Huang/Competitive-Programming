#include<bits/stdc++.h>
using namespace std;

struct cow {
	int x, y;
};

const int maxn = 200;
int n, ans = 1;
cow cows[maxn], cowsy[maxn];
vector<cow> top_cows, bot_cows;

void solve(bool perfect) {
	sort(cows, cows + n, [&](const cow& a, const cow& b) {return a.x < b.x; });
	sort(cowsy, cowsy + n, [&](const cow& a, const cow& b) {return a.y < b.y; });

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int l = cows[j].x - cows[i].x;

			cow top, bot;
			if (cows[i].y > cows[j].y) {
				top = cows[i];
				bot = cows[j];
			}
			else {
				top = cows[j];
				bot = cows[i];
			}

			if (top.y - l > bot.y) {
				continue;
			}

			set<int> events;
			set<int> y_vals = { top.y,bot.y };
			for (int k = 0; k < n; k++) {
				if (cows[i].x < cowsy[k].x and cowsy[k].x < cows[j].x) {
					if (top.y < cowsy[k].y and cowsy[k].y <= bot.y + l) {
						events.insert(cowsy[k].y);
						y_vals.insert(cowsy[k].y);
					}
					else if (top.y - l <= cowsy[k].y and cowsy[k].y < bot.y) {
						events.insert(cowsy[k].y + 1 + l);
						y_vals.insert(cowsy[k].y);
					}
				}
			}

			ans += 1 + events.size();
			if (!perfect) {
				for (auto i: y_vals) {
					ans -= (y_vals.count(i + l));
				}
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> cows[i].x >> cows[i].y;
	}

	memcpy(cowsy, cows, sizeof(cows));
	solve(1);
	for (int i = 0; i < n; i++) {
		swap(cows[i].x, cows[i].y);
	}
	memcpy(cowsy, cows, sizeof(cows));
	solve(0);

	cout << ans;
}