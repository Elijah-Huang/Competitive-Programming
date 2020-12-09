/*
ID: elijahj1
TASK: lgame
LANG: C++14
*/
#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	unordered_map<char, int> values = { {'q',7},{'w',6},{'e',1},{'r',2},{'t',2},{'y',5},
		{'u',4},{'i',1},{'o',3},{'p',5},{'a',2},{'s',1},{'d',4},{'f',6},{'g',5},{'h',5},
		{'j',7} ,{'k',6} ,{'l',3} ,{'z',7} ,{'x',7} ,{'c',4} ,{'v',6} ,{'b',5} ,{'n',2} ,{'m',5} };
	unordered_set<string> dict;
	freopen("lgame.dict","r",stdin);
	string curr;
	while (curr != "."){
		dict.insert(curr);
		cin >> curr;
	}
	fclose(stdin);
	freopen("lgame.in", "r", stdin); freopen("lgame.out", "w", stdout);
	string collected;
	cin >> collected;
	int num_subsets = 1 << collected.size();
	unordered_map<string, int> subsetsmp;
	for (int i = 1; i < num_subsets; i++) {
		bitset<7> curr = bitset<7>(i);
		int value = 0;
		string subset;
		for (int idx = 0; idx < 7; idx++) {
			if (curr[idx] == 1) {
				value += values[collected[idx]];
				subset.push_back(collected[idx]);
			}
		}
		sort(subset.begin(), subset.end());
		subsetsmp.insert({ subset,value });
	}
	vector<pair<int, string>> subsets;
	for (auto i: subsetsmp) {
		subsets.push_back({ i.second,i.first });
	}
	sort(subsets.begin(), subsets.end(), greater<pair<int,string>>());
	int mx_value;
	unordered_set<string> mx_perms;
	bool found = false;
	int i = 0;
	while (i < subsets.size()) {
		if (subsets[i].second.size() < 3) {
			i++;
			if (i >= subsets.size()) {
				break;
			}
		}
		mx_value = subsets[i].first;
		vector<pair<string, string>> perms;
		while (i < subsets.size() and mx_value == subsets[i].first) {
			do {
				perms.push_back({ subsets[i].second,"&" });
				for (int j = 1; j <= subsets[i].second.size() / 2; j++) {
					string first = subsets[i].second.substr(0, j);
					string second = subsets[i].second.substr(j, subsets[i].second.size() - j);
					if (first.compare(second) <= 0) {
						perms.push_back({ first,second });
					}
					else {
						perms.push_back({ second,first });
					}
				}
			} while (next_permutation(subsets[i].second.begin(), subsets[i].second.end()));
			i++;
		}
		for (auto perm : perms) {
			if (perm.second == "&") {
				if (dict.count(perm.first)) {
					mx_perms.insert(perm.first);
				}
			}
			else {
				if (dict.count(perm.first) and dict.count(perm.second)) {
					mx_perms.insert(perm.first + ' ' + perm.second);
				}
			}
		}
		if (!mx_perms.empty()) {
			found = true;
			break;
		}
	}
	if (found) {
		vector<string> mx_permsvector;
		for (auto perm : mx_perms) {
			mx_permsvector.push_back(perm);
		}
		sort(mx_permsvector.begin(), mx_permsvector.end());
		cout << mx_value << '\n';
		for (auto perm : mx_permsvector) {
			cout << perm << '\n';
		}
	}
	else {
		cout << 0 << '\n';
	}
}