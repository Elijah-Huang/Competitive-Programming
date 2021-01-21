#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n, m;
// indices in array a are "i" and indices in array b are "j" 
int val_to_idx[maxn], j_to_i[maxn], j_to_i_copy[maxn];
vector<int> j_vals[maxn], bits[maxn];

struct query {
	int t, li, ri, lj, rj;
};
query queries[maxn];

void set_bits(int j) {
	for (int i = j_to_i[j]; i < maxn; i += i & -i) {
		j_vals[i].push_back(j);
	}
}

void add(int i, int j2, int val) {
	for (; i < maxn; i += i & -i) {
		for (int j = lower_bound(j_vals[i].begin(), j_vals[i].end(), j2) - j_vals[i].begin() + 1; j < bits[i].size(); j += j & -j) {
			bits[i][j] += val;
		}
	}
}

int sum(int i, int j2) {
	int ret = 0;
	for (; i > 0; i -= i & -i) {
		for (int j = upper_bound(j_vals[i].begin(), j_vals[i].end(), j2) - j_vals[i].begin(); j > 0; j -= j & -j) {
			ret += bits[i][j];
		}
	}

	return ret;
}

// upper left || bottom right
int rect_sum(int i1, int j1, int i2, int j2) {
	return sum(i2, j2) - sum(i1 - 1, j2) - sum(i2, j1 - 1) + sum(i1 - 1, j1 - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		val_to_idx[a] = i;
	}

	for (int j = 1; j <= n; j++) {
		int b; cin >> b;
		j_to_i[j] = val_to_idx[b];
	}

	for (int j = 1; j <= n; j++) {
		set_bits(j);
	}

	memcpy(j_to_i_copy, j_to_i, sizeof(j_to_i));

	for (int i = 0; i < m; i++) {
		cin >> queries[i].t;

		if (queries[i].t == 1) {
			cin >> queries[i].li >> queries[i].ri >> queries[i].lj >> queries[i].rj;
		}
		else {
			cin >> queries[i].li >> queries[i].ri;

			swap(j_to_i[queries[i].li], j_to_i[queries[i].ri]);
			set_bits(queries[i].li);
			set_bits(queries[i].ri);
		}
	}

	memcpy(j_to_i, j_to_i_copy, sizeof(j_to_i));

	for (int i = 1; i <= n; i++) {
		sort(j_vals[i].begin(), j_vals[i].end());
		j_vals[i].resize(unique(j_vals[i].begin(), j_vals[i].end()) - j_vals[i].begin());
		bits[i].resize(j_vals[i].size() + 1);
	}

	for (int j = 1; j <= n; j++) {
		add(j_to_i[j], j, 1);
	}

	for (int i = 0; i < m; i++) {
		query& q = queries[i];

		if (q.t == 1) {
			cout << rect_sum(q.li, q.lj, q.ri, q.rj) << '\n';
		}
		else {
			add(j_to_i[q.li], q.li, -1);
			add(j_to_i[q.ri], q.ri, -1);
			swap(j_to_i[q.li], j_to_i[q.ri]);
			add(j_to_i[q.li], q.li,1);
			add(j_to_i[q.ri], q.ri, 1);
		}
	}
}