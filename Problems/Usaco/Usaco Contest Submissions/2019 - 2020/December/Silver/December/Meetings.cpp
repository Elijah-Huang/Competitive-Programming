#include<bits/stdc++.h>
using namespace std;

struct cow {
	int w, x, d;
};

bool cow_cmp(const cow& a, const cow& b) {
	return a.x < b.x;
}

const int maxn = 5e4 + 1;
int n, l, total_weight = 0, added_weight = 0, t;
int r = -1, passed = 0, meetings = 0;
cow cows[maxn];
vector<cow> added_weights;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("meetings.in","r",stdin); freopen("meetings.out","w",stdout);
	
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> cows[i].w >> cows[i].x >> cows[i].d;
		total_weight += cows[i].w;
	}

	sort(cows, cows + n, cow_cmp);

	for (int i = 0; i < n; i++) {
		q.push(cows[i].w);

		if (cows[i].d == -1) {
			added_weights.push_back({ q.front(), cows[i].x});
			q.pop();
		}
	}
	q = queue<int>();

	for (int i = n-1; i >= 0; i--) {
		q.push(cows[i].w);

		if (cows[i].d == 1) {
			added_weights.push_back({ q.front(), l-cows[i].x});
			q.pop();
		}
	}
	q = queue<int>();

	sort(added_weights.begin(), added_weights.end(), cow_cmp);

	for (int i = 0; i < n; i++) {
		added_weight += added_weights[i].w;

		if (added_weight >= (total_weight + 1) / 2) {
			t = added_weights[i].x;
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		while (r + 1 < n and cows[r + 1].x - cows[i].x <= 2 * t) {
			r++;
			if (cows[r].d == -1) {
				passed++;
			}
		}

		if (cows[i].d == 1) {
			meetings += passed;
		}

		passed -= cows[i].d == -1;
	}

	cout << meetings;
}