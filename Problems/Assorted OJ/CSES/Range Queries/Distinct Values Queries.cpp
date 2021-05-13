// O(nlogn + qlogq) The idea is to process queries offline and use a segtree on an array where the value at
// index i = 1 if it is the first occurence of that element from the current leftbound else 0
// now sum(l,r) is the desired answer if leftbound = l
#include<bits/stdc++.h>
using namespace std;

struct query {
	int l, r, i;
};

const int maxn = 2e5;
int n, q;
int next_el[maxn];
map<int, int> last_oc;
vector<query> queries;
int answers[maxn];

int t[4*maxn];

void update(int idx, int val, int v = 1, int tl = 0, int tr = maxn - 1) {
	if (tl == tr) {
		t[v] = val;
		return;
	}

	int tm = (tl + tr) / 2;
	if (idx <= tm) {
		update(idx, val, 2 * v, tl, tm);
	}
	else {
		update(idx, val, 2 * v + 1, tm + 1, tr);
	}

	t[v] = t[2 * v] + t[2 * v + 1];
}

int sum(int l, int r, int v = 1, int tl = 0, int tr = maxn - 1) {
	if (tr < l or r < tl) {
		return 0;
	}
	
	if (l <= tl and tr <= r) {
		return t[v];
	}

	int tm = (tl + tr) / 2;
	return (sum(l, r, 2 * v, tl, tm) + sum(l, r, 2 * v + 1, tm + 1, tr));
}


int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;

		// will be used later to help update the values of the segtree (finding next occurence of the element)
		if (last_oc.count(a)) {
			next_el[last_oc[a]] = i;
		}
		else {
			update(i, 1);
		}
		last_oc[a] = i;
	}

	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; a--, b--;
		queries.push_back({ a,b,i });
	}

	// process queries offline sorted by leftbound (that way there are O(n) segtree updates)
	sort(queries.begin(), queries.end(), [&](query& a, query& b) {return a.l < b.l; });

	int curr_l = 0; // leftbound from where we determine first occurences
	for (auto [l, r, i] : queries) {
		// update segtree so that curr_l = l and 
		// change elements to 1 or 0 based on if they are the first unique element from the new leftbound
		while (l > curr_l) {
			update(curr_l, 0);
			if (next_el[curr_l]) {
				update(next_el[curr_l], 1);
			}

			curr_l++;
		}

		answers[i] = sum(l, r);
	}

	for (int i = 0; i < q; i++) {
		cout << answers[i] << '\n';
	}
}