/*
ID: elijahj1
TASK: theme
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; 
	freopen("theme.in", "r", stdin); freopen("theme.out", "w", stdout);
	cin >> n;
	vector<int> notes(n);
	for (int i = 0; i < n; i++) {
		cin >> notes[i];
	}
	vector<int> diffs(n - 1);
	for (int i = 1; i < n; i++) {
		diffs[i - 1] = notes[i] - notes[i - 1];
	}
	vector<int> compare(n);
	int ans = 0;
	for (int start = 4; start <= n - 6; start++) {
		compare[0] = 0;
		int j;
		for (int i = start + 2; i < n - 1; i++) {
			j = compare[i - start - 2];
			while (j > 0 and diffs[i] != diffs[start + 1 + j]) {
				j = compare[j - 1];
			}
			compare[i - start - 1] = (diffs[i] == diffs[start + 1 + j]) ? j + 1 : 0;
		}
		j = 0;
		for (int end = 0; end < start; end++) {
			while (j > 0 and diffs[end] != diffs[start + 1 + j]) {
				j = compare[j - 1];
			}
			j = (diffs[end] == diffs[start + 1 + j]) ? j + 1 : 0;
			ans = max(ans, j + 1);
		}
	}
	cout << (ans >= 5 ? ans : 0) << '\n';
}