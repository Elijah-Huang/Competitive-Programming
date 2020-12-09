#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("nocow.in", "r", stdin); freopen("nocow.out", "w", stdout);
	int n, k; cin >> n >> k;
	vector<unordered_set<string>> adjectives_set(30);
	vector<vector<string>> adjectives;
	vector<vector<string>> missing(n);
	int num_adjectives;
	int total = 1;
	for (int i = 0; i < n; i++) {
		int wordnum = 0;
		string curr;
		while (1) {
			cin >> curr;
			if (curr != "cow.") {
				wordnum++;
				if (wordnum > 4) {
					missing[i].push_back(curr);
					adjectives_set[wordnum - 5].insert(curr);
				}
			}
			else {
				num_adjectives = wordnum - 4;
				break;
			}
		}
	}

	for (int i = 0; i < num_adjectives; i++) {
		total *= adjectives_set[i].size();
	}
	adjectives.resize(num_adjectives);
	for (int i = 0; i < num_adjectives; i++) {
		for (auto adj : adjectives_set[i]) {
			adjectives[i].push_back(adj);
		}
	}
	for (int i = 0; i < num_adjectives; i++) {
		sort(adjectives[i].begin(), adjectives[i].end());
	}

	vector<int> location_missing;
	for (auto adjs : missing) {
		int location = 1;
		int curr = total;
		for (int i = 0; i < num_adjectives; i++) {
			curr /= adjectives[i].size();
			for (int j = 0; j < adjectives[i].size(); j++) {
				if (adjectives[i][j] == adjs[i]) {
					location += curr * j;
				}
			}
		}
		location_missing.push_back(location);
	}

	sort(location_missing.begin(), location_missing.end());
	int idx = 0;
	while (idx < n and location_missing[idx] <= k) {
		k++;
		idx++;
	}

	k--;
	int curr = total;
	int i = 0;
	vector<string> description;
	while (i < num_adjectives) {
		curr /= adjectives[i].size();
		description.push_back(adjectives[i][k / curr]);
		k %= curr;
		i++;
	}

	for (int i = 0; i < description.size(); i++) {
		cout << description[i] << (i < description.size() - 1 ? ' ' : '\n');
	}
}