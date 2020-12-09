/*
ID: elijahj1
TASK : latin
LANG : C++14
*/
#include<bits/stdc++.h>
using namespace std;

int n;
long long ans = 0;
int square[8][8];
bool contained[8][7];
int stored[8][300];
int i, j;

int solve(int idx) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << square[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	if (idx == n - 1) {
		return 1;
	}

	if (idx == 2) {
		bool v[8];
		memset(v, 0, sizeof(v));
		i = 0, j = 1;
		for (int k = 0; k <= n-1; ++k) {
			if (v[k])continue;
			v[k] = true;
			int n2 = 1;
			for (int l = square[1][k]; l != k + 1; l = square[1][l-1]) {
				cout << "hi\n";
				v[l-1] = true;
				++n2;
			}
			++i;
			j *= n2;
		}

		cout << j << '\n';
		if (stored[i][j] != -1) {
			return stored[i][j];
		}
	}

	int res = 0;
	vector<int> start_perm;
	for (int i = 1; i <= n; i++) {
		if (i != idx + 1) {
			start_perm.push_back(i);
		}
	}

	do {
		bool free = true;
		for (int i = 0; i < start_perm.size(); i++) {
			if (contained[start_perm[i]][1 + i]) {
				free = false;
				break;
			}
		}
		if (free) {
			for (int i = 0; i < start_perm.size(); i++) {
				contained[start_perm[i]][1 + i] = 1;
				square[idx][1 + i] = start_perm[i];
			}
			res += solve(idx + 1);
			for (int i = 0; i < start_perm.size(); i++) {
				contained[start_perm[i]][1 + i] = 0;
			}
		}
	} while (next_permutation(start_perm.begin(), start_perm.end()));

	if (idx == 2) {
		return stored[i][j] = res;
	}
	else {
		return res;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("latin.in", "r", stdin); freopen("latin.out", "w", stdout);
	cin >> n;
	if (n == 2) {
		cout << 1 << '\n';
		return 0;
	}

	memset(stored, 0xff, sizeof(stored));

	for (int j = 0; j < n; j++) {
		contained[j + 1][j] = 1;
		square[0][j] = j + 1;
		square[j][0] = j + 1;
	}

	ans = solve(1);

	for (int i = 2; i <= n - 1; i++) {
		ans *= i;
	}

	cout << ans << '\n';
}
