/*
ID: elijahj1
TASK: latin
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

int n;
long long ans = 0;
bool contained[2][8][7];
int placed = 1;

void solve(int idx, bool type) {
	if (idx == n ) {
		if (placed == 1) {
			ans++;
		}
		else {
			ans += n-2;
		}
		return;
	}

	vector<int> start_perm;
	for (int i = 1; i <= n; i++) {
		if (!contained[type^1][i][idx]) {
			start_perm.push_back(i);
		}
	}

	do {
		bool free = true;
		for (int i = 0; i < start_perm.size(); i++) {
			if (contained[type][start_perm[i]][idx + i + type + (idx == 1 and !type)]) {
				free = false;
				break;
			}
		}
		if (free) {
			for (int i = 0; i < start_perm.size(); i++) {
				contained[type][start_perm[i]][idx + i + type + (idx == 1 and !type)] = 1;
			}
			if (type) {
				solve(idx + 1, 0);
			}
			else {
				solve(idx, 1);
			}
			for (int i = 0; i < start_perm.size(); i++) {
				contained[type][start_perm[i]][idx + i + type + (idx == 1 and !type)] = 0;
			}
		}
	} while (next_permutation(start_perm.begin(), start_perm.end()));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("latin.in", "r", stdin); freopen("latin.out", "w", stdout);
	cin >> n;
	if (n == 2) {
		cout << 1 << '\n';
		return 0;
	}

	for (int j = 0; j < n; j++) {
		contained[0][j + 1][j] = 1;
		contained[1][j + 1][j] = 1;
	}

	contained[0][1][1] = 1;
	contained[1][1][1] = 1;
	solve(1, 0);
	contained[0][1][1] = 0;
	contained[1][1][1] = 0;
	contained[0][3][1] = 1;
	contained[1][3][1] = 1;
	placed = 3;
	solve(1, 0);

	for (int i = 2; i <= n - 1; i++) {
		ans *= i;
	}

	cout << ans << '\n';
}