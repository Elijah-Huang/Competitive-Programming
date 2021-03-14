#include<bits/stdc++.h>
using namespace std;

struct bit {

	int n;
	vector<int> a;

	bit() {}
	bit(int n2) {
		n = n2 + 1;
		a.resize(n);
	}

	void add(int idx, int val) {
		for (idx++; idx < n; idx += idx & -idx) {
			a[idx] += val;
		}
	}

	int sum(int idx) {
		int tot = 0;
		for (idx++; idx > 0; idx -= idx & -idx) {
			tot += a[idx];
		}

		return tot;
	}

	int sumr(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

const int maxn = 2e5;
int n, q;
int a[maxn];
vector<pair<pair<int,int>, int>> queries;
int ans[maxn];
// locs of colors
vector<int> color_loc[maxn];
int next_color[maxn];
// end of last active segment of that color
int last_oc[maxn];
bool had_drop[maxn];
// updates to drops bit
// [i] -> drops that don't exist anymore after moving leftbound to i
vector<int> drop_loc[maxn];
bit colors(maxn), drops(maxn);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;

		if (color_loc[a[i]].size() == 0) {
			colors.add(i, 1);
			color_loc[a[i]].push_back(i);
		}
		else {
			next_color[color_loc[a[i]].back()] = i;
			color_loc[a[i]].push_back(i);
		}
	}

	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; a--; b--;
		queries.push_back({ {a,b},i });
	}

	sort(queries.begin(), queries.end());


	stack<int> s;
	for (int i = 0; i < n; i++) {
		while (!s.empty() and s.top() > a[i]) {
			had_drop[s.top()] = 1;
			s.pop();
		}
		if (s.empty() or s.top() < a[i]) {
			s.push(a[i]);
		}

		if (had_drop[a[i]]) {
			//cout << "drop_added " << i << '\n';
			drops.add(i, 1);
			drop_loc[last_oc[a[i]]+1].push_back(i);
			had_drop[a[i]] = 0;
		}

		last_oc[a[i]] = i;
	}


	int l = 0;
	for (auto q : queries) {
		// update bits
		while (l < q.first.first) {
			//cout << l << '\n';
			colors.add(l, -1);
			if (!next_color[l] == 0) {
				colors.add(next_color[l], 1);
			}
			for (auto upd : drop_loc[l+1]) {
				//cout << "upd1 " << l << ' ' << upd << '\n';
				drops.add(upd, -1);
			}
			l++;
		}

		// answer query
		//cout << q.first.first << ' ' << q.first.second << ' ' << colors.sum(q.first.second) << ' ' << drops.sum(q.first.second) << '\n';
		ans[q.second] = colors.sum(q.first.second) + drops.sum(q.first.second);
	}

	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
}