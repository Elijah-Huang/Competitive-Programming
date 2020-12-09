#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

vector<int> locations[int(1e6 + 1)];
unordered_set<int> groups[250000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("invite.in", "r", stdin); freopen("invite.out", "w", stdout);
	int n, g;
	cin >> n >> g;
	int s;
	int group = -1;
	while (cin >> s) {
		group++;
		int cow;
		while (s--) {
			cin >> cow;
			groups[group].insert(cow);
			locations[cow].push_back(group);
		}
	}
	unordered_set<int> st({ 1 });
	int invited = 0;
	while (!st.empty()) {
		int curr = *st.begin();
		st.erase(st.begin());
		invited++;
		for (auto neighbor : locations[curr]) {
			groups[neighbor].erase(curr);
			if (groups[neighbor].size() == 1) {
				st.insert(*groups[neighbor].begin());
			}
		}
	}
	cout << invited;
}