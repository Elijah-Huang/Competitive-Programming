#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cownomics.in", "r", stdin); freopen("cownomics.out", "w", stdout);
	int n, m, number_sets = 0;
	cin >> n >> m;
	vector<string> spotty(n);
	vector<string> plain(n);
	unordered_map<char, int> convert = { {'A', 0}, {'T', 1} , {'C',2}, {'G',3} };
	for (int i = 0; i < n; i++) {
		cin >> spotty[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> plain[i];
	}
	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			for (int k = j + 1; k < m; k++) {
				bool plain3[64]{};
				for (int l = 0; l < n; l++) {
					plain3[16 * convert[plain[l][i]] +
						4 * convert[plain[l][j]] + convert[plain[l][k]]] = 1;
				}
				bool no_matches = true;
				for (int l = 0; l < n; l++) {
					if (plain3[16*convert[spotty[l][i]] 
						+ 4*convert[spotty[l][j]] + convert[spotty[l][k]]]) {
						no_matches = false;
						break;
					}
				}
				number_sets += no_matches;
			}
		}
	}
	cout << number_sets; 
}