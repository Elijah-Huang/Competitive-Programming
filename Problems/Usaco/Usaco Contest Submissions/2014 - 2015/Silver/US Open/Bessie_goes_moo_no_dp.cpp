#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

unordered_map<char, vector<int>> values;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("bgm.in", "r", stdin); freopen("bgm.out", "w", stdout);
	int n;
	cin >> n;
	vector<char> chars = { 'B','E','S','I','G','O','M' };
	for (auto c : chars) {
		values[c] = vector<int>(7);
	}

	for (int i = 0; i < n; i++) {
		char c; int val;
		cin >> c >> val;
		values[c][(7 + (val % 7)) % 7]++;
	}

	unsigned long long total = 0;
	for (int i1 = 0; i1 < 7; i1++) {
		for (int i2 = 0; i2 < 7; i2++) {
			for (int i3 = 0; i3 < 7; i3++) {
				for (int i4 = 0; i4 < 7; i4++) {
					for (int i5 = 0; i5 < 7; i5++) {
						for (int i6 = 0; i6 < 7; i6++) {
							for (int i7 = 0; i7 < 7; i7++) {
								if ((i1 + i2 * 2 + i3 * 2 + i4) * (i5 + i6 + i2 + i3) * (i7 + 2 * i6) % 7 == 0) {
									vector<int> residues = { i1,i2,i3,i4,i5,i6,i7 };
									unsigned long long res = 1;
									for (int j = 0; j < 7; j++) {
										res *= values[chars[j]][residues[j]];
									}
									total += res;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << total;
}