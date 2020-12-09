#include<bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
	const bool operator==(point& b) const {
		return x == b.x and y == b.y;
	}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("reduce.in", "r", stdin); freopen("reduce.out", "w", stdout);
	int n;
	cin >> n;
	vector<point> pointsx;
	vector<point> pointsy;
	vector<bool> usedx(n);
	vector<bool> usedy(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pointsx.push_back({ x,y });
	}
	if (n <= 4) {
		cout << 0;
	}
	else {
		pointsy = pointsx;
		sort(pointsx.begin(), pointsx.end(), [&](const point& a, const point& b)
			{return a.x == b.x ? a.y < b.y : a.x < b.x; });
		sort(pointsy.begin(), pointsy.end(), [&](const point& a, const point& b)
			{return a.y == b.y ? a.x < b.x : a.y < b.y; });

		long long smallest_area = 1ll << 62;
		vector<bool> perm = { 0, 0, 0, 1, 1, 1 };
		int left = 0, right = 0, up = 0, down = 0;
		int lidx = 0, ridx = n - 1, uidx = n - 1, didx = 0;

		do {
			int i = 0;
			while (perm[i] == 0) {
				i++;
			}
			left = i;
			i++;
			while (perm[i] == 0) {
				i++;
			}
			right = i - left - 1;
			i++;
			while (perm[i] == 0) {
				i++;
			}
			up = i - left - right - 2;
			i++;
			down = 6 - up - left - right - 3;
			lidx = 0, ridx = n - 1, uidx = n - 1, didx = 0;
			for (int i = 0; i < 3; i++) {
				usedx[i] = 0, usedy[i] = 0, usedx[n - 1 - i] = 0, usedy[n - 1 - i] = 0;
			}
			
			while (left--) {
				while (usedx[lidx] == 1) {
					lidx++;
				}
				for (int i = 0; i < 3; i++) {
					if (pointsx[i] == pointsx[lidx]) { usedx[i] = 1; };
					if (pointsy[i] == pointsx[lidx]) { usedy[i] = 1; };
					if (pointsx[n - 1 - i] == pointsx[lidx]) { usedx[n - 1 - i] = 1; };
					if (pointsy[n - 1 - i] == pointsx[lidx]) { usedy[n - 1 - i] = 1; };
				}
				lidx++;
			}

			while (right--) {
				while (usedx[ridx] == 1) {
					ridx--;
				}
				for (int i = 0; i < 3; i++) {
					if (pointsx[i] == pointsx[ridx]) { usedx[i] = 1; };
					if (pointsy[i] == pointsx[ridx]) { usedy[i] = 1; };
					if (pointsx[n - 1 - i] == pointsx[ridx]) { usedx[n - 1 - i] = 1; };
					if (pointsy[n - 1 - i] == pointsx[ridx]) { usedy[n - 1 - i] = 1; };
				}
				ridx--;
			}

			while (up--) {
				while (usedy[uidx] == 1) {
					uidx--;
				}
				for (int i = 0; i < 3; i++) {
					if (pointsx[i] == pointsy[uidx]) { usedx[i] = 1; };
					if (pointsy[i] == pointsy[uidx]) { usedy[i] = 1; };
					if (pointsx[n - 1 - i] == pointsy[uidx]) { usedx[n - 1 - i] = 1; };
					if (pointsy[n - 1 - i] == pointsy[uidx]) { usedy[n - 1 - i] = 1; };
				}
				uidx--;
			}

			while (down--) {
				while (usedy[didx] == 1) {
					didx++;
				}
				for (int i = 0; i < 3; i++) {
					if (pointsx[i] == pointsy[didx]) { usedx[i] = 1; };
					if (pointsy[i] == pointsy[didx]) { usedy[i] = 1; };
					if (pointsx[n - 1 - i] == pointsy[didx]) { usedx[n - 1 - i] = 1; };
					if (pointsy[n - 1 - i] == pointsy[didx]) { usedy[n - 1 - i] = 1; };
				}
				didx++;
			}
			
			while (usedx[lidx] == 1) {
				lidx++;
			}
			while (usedx[ridx] == 1) {
				ridx--;
			}
			while (usedy[uidx] == 1) {
				uidx--;
			}
			while (usedy[didx] == 1) {
				didx++;
			}
			smallest_area = min(smallest_area, (long long)(pointsx[ridx].x - pointsx[lidx].x)
				* (pointsy[uidx].y - pointsy[didx].y));
		} while (next_permutation(perm.begin() , perm.end()));
		cout << smallest_area;
	}
}