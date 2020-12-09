#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int n, m, k;
map<vector<int>, double> mp;
map<vector<int>, double> probability;

void dfs(vector<int> curr) {
	for (int i = 0; i < curr.size(); i++) {
		cout << curr[i] << ' ';
	}
	cout << '\n' << '\n';
	if (mp.count(curr)) {
		return;
	}
	else if (curr.empty()) {
		return;
	}
	else {
		double expected = 0;
		double prob = 0;
		vector<pair<vector<int>, double>> used;
		unordered_map<int, int> counts;
		unordered_set<int> seen;
		for (int i = 0; i < curr.size(); i++) {
			counts[curr[i]]++;
		}
		for (int i = 0; i < curr.size(); i++) {
			if (curr[i] != 0 and !seen.count(curr[i])) {
				vector<int> child = curr;
				child[i]--;
				sort(child.begin(), child.end());
				if (child[0] == 0) {
					child.erase(child.begin());
				}

				double other;
				if (counts.count(curr[i] - 1)) {
					other = counts[curr[i] - 1] + 1;
				}
				else if (curr[i] - 1 == 0) {
					other = m - counts.size() + 1;
				}
				else {
					other = 1;
				}

				dfs(child);
				if (child.size() == 0) {
					prob += (other/m)*1;
					used.push_back({ child,(other / m) });
				}
				else {
					used.push_back({ child,(other / m) });
					prob += (other/m)*probability[child];
				}
				seen.insert(curr[i]);
			}
		}
		for (auto child : used) {
			if (child.first.size()) {
				expected += (1 / child.second + mp[child.first]) * child.second * probability[child.first] / prob;
			}
			else {
				expected += (1 / child.second) * child.second / prob;
			}
		}
		mp[curr] = expected;
		probability[curr] = prob;
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	int t, c = 0;
	cin >> t;
	while (t--) {
		mp.clear();
		cin >> n >> m >> k;
		vector<int> start(k);
		for (int i = 0; i < k; i++) {
			cin >> start[i];
		}
		c++;
		dfs(start);
		cout << "Case #" << c << ": " << mp[start] << '\n';
	}
}
