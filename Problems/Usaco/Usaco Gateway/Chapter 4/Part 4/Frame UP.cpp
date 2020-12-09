/*
ID: elijahj1
TASK: frameup
LANG: C++14
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
struct sides {
	int xmin = 30, xmax = -1, ymin = 30, ymax  = -1;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("frameup.in","r",stdin); freopen("frameup.out","w",stdout);
	int h, w;
	cin >> h >> w;
	vector<string> m(h);
	vector<string> orderings(1);
	for (int i = 0; i < h; i++) {
		cin >> m[i];
	}
	int time = 0;
	while (true) {
		unordered_map<char, sides> locations;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char curr = m[i][j];
				if (curr != '.') {
					locations[curr].xmin = min(locations[curr].xmin, i);
					locations[curr].xmax = max(locations[curr].xmax, i);
					locations[curr].ymin = min(locations[curr].ymin, j);
					locations[curr].ymax = max(locations[curr].ymax, j);
				}
			}
		}
		if (locations.empty()) {
			break;
		}
		else {
			string can_remove;
			for (auto letter : locations) {
				bool fail = false;
				for (int i = letter.second.xmin; i <= letter.second.xmax; i++) {
					if ((m[i][letter.second.ymin] != '.' and m[i][letter.second.ymin] !=  letter.first)
						or (m[i][letter.second.ymax] != '.' and m[i][letter.second.ymax] != letter.first)) {
						fail = true;
						break;
					}
				}
				for (int i = letter.second.ymin; i <= letter.second.ymax; i++) {
					if ((m[letter.second.xmin][i] != '.' and m[letter.second.xmin][i] != letter.first)
						or (m[letter.second.xmax][i] != '.' and m[letter.second.xmax][i] != letter.first)) {
						fail = true;
						break;
					}
				}
				if (!fail) {
					can_remove.push_back(letter.first);
				}
			}
			int initial_size = orderings.size();
			int permutations = 1;
			for (int i = 1; i <= can_remove.size(); i++) {
				permutations *= i;
			}
			/*
			for (int i = 0; i < permutations -1; i++) {
				orderings.insert(orderings.end(), orderings.begin(), orderings.begin() + initial_size);
			}*/
			orderings.resize(permutations * initial_size);
			for (int a = 1; a <= permutations - 1; a++) {
				for (int b = 0; b < initial_size; b++) {
					orderings[a * initial_size + b] = orderings[b];
				}
			}
			sort(can_remove.begin(), can_remove.end());
			int idx = 0;
			do {
				for (int i = 0; i < initial_size; i++) {
					orderings[idx + i] += can_remove;
				}
				idx += initial_size;
			} while (next_permutation(can_remove.begin(),can_remove.end()));
			for (auto l : can_remove) {
				sides letter = locations[l];
				for (int i = letter.xmin; i <= letter.xmax; i++) {
					m[i][letter.ymin] = '.';
					m[i][letter.ymax] = '.';
				}
				for (int i = letter.ymin; i <= letter.ymax; i++) {
					m[letter.xmin][i] = '.';
					m[letter.xmax][i] = '.';
				}
			}
		}
	}
	/*
	for (int j = orderings.size() - 1; j >= 0; j--) {
		string ordering = orderings[j];
		for (int i = ordering.size() - 1; i >= 0; i--) {
			cout << ordering[i];
		}
		cout << '\n';
	}
	*/
	for (auto& ordering : orderings) {
		reverse(ordering.begin(), ordering.end());
	}
	reverse(orderings.begin(), orderings.end());
	for (auto ordering : orderings) {
		cout << ordering << '\n';
	}
}