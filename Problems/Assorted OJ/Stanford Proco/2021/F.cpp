#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int n;
long long donation[maxn];
long long ans = 0;
vector<pair<int, int>> anss;

vector<int> adj[maxn];
int degree[maxn];
vector<vector<int>> bamboos; // the bamboo graphs that protrude from the root
vector<int> curr_lens; // lengths of bamboo graphs up to the current minimum
map<int,multiset<int>,greater<int>> sorted_lens; // sorted lengths to get maximum quickly
vector<pair<int, int>> events; // updating bamboo graphs when decreasing the minimum
vector<vector<int>> next_small, prev_small; // for if path does not go through root

void find_bamboos(int root) {
	if (degree[root] == 0) {
		bamboos.push_back({ root });
	}
	else {
		for (auto ne : adj[root]) {
			bamboos.push_back({ root });

			int c = ne, p = root;
			bool found = 1;
			while (found) {
				bamboos.back().push_back(c);

				found = 0;
				for (auto ne : adj[c]) {
					if (ne != p) {
						found = 1;
						p = c;
						c = ne;
						break;
					}
				}
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> donation[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}

	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (degree[i] > 2) {
			root = i;
		}
	}

	if (root == 0) {
		for (int i = 1; i <= n; i++) {
			if (degree[i] <= 1) {
				root = i;
			}
		}
	}

	find_bamboos(root);

	// path goes through root
	if (degree[root] > 2) {
		// create events
		for (int b_idx = 0; b_idx < bamboos.size(); b_idx++) {
			long long curr_mn = donation[bamboos[b_idx][0]];
			for (int i = 1; i < bamboos[b_idx].size(); i++) {
				curr_mn = min(curr_mn, donation[bamboos[b_idx][i]]);
				events.push_back({ curr_mn, b_idx });
			}
		}
		sort(events.begin(), events.end(), greater<pair<int, int>>());

		// process events in order of decreasing 
		multiset<int> a;
		for (int i = 0; i < bamboos.size(); i++) {
			a.insert(bamboos[i][0]);
		}
		sorted_lens[1] = a;
		curr_lens.resize(bamboos.size(),1);
		for (auto [new_min,b_idx] : events) {
			// update
			multiset<int>& set_bamboo_in = sorted_lens[curr_lens[b_idx]];
			set_bamboo_in.erase(set_bamboo_in.find(bamboos[b_idx][curr_lens[b_idx]-1]));
			if (sorted_lens[curr_lens[b_idx]].size() == 0) {
				sorted_lens.erase(curr_lens[b_idx]);
			}
			sorted_lens[curr_lens[b_idx]+1].insert(bamboos[b_idx][curr_lens[b_idx]]);
			curr_lens[b_idx]++;

			long long mx1, mx2;
			int x1, y1;
			if (sorted_lens.begin()->second.size() >= 2) {
				mx1 = mx2 = sorted_lens.begin()->first;
				x1 = *(sorted_lens.begin()->second.begin());
				y1 = *(next(sorted_lens.begin()->second.begin()));
			}
			else {
				mx1 = sorted_lens.begin()->first;
				mx2 = next(sorted_lens.begin())->first;
				x1 = *(sorted_lens.begin()->second.begin());
				y1 = *(next(sorted_lens.begin())->second.begin());
			}

			if (x1 > y1) {
				swap(x1, y1);
			}

			if (ans < (mx1 + mx2 - 1) * new_min) {
				ans = (mx1 + mx2 - 1) * new_min;
				anss.clear();
				anss.push_back({ x1,y1 });
			}
			if (ans == (mx1 + mx2 - 1) * new_min) {
				anss.push_back({ x1,y1 });
			}
			
		}	
	}

	// path does not go through root
	for (int b_idx = 0; b_idx < bamboos.size(); b_idx++) {
		next_small.push_back(vector<int>(bamboos[b_idx].size(),bamboos[b_idx].size()));
		stack<pair<int, int>> s;
		for (int i = 0; i < bamboos[b_idx].size(); i++) {
			int c = donation[bamboos[b_idx][i]];

			while (!s.empty() and s.top().first > c) {
				next_small[b_idx][s.top().second] = i;
				s.pop();
			}

			s.push({ c,i });
		}

		prev_small.push_back(vector<int>(bamboos[b_idx].size(),-1));
		s = stack<pair<int, int>>();
		for (int i = bamboos[b_idx].size() - 1; i >= 0; i--) {
			int c = donation[bamboos[b_idx][i]];

			while (!s.empty() and s.top().first > c) {
				prev_small[b_idx][s.top().second] = i;
				s.pop();
			}

			s.push({ c,i });
		}

		for (int i = 0; i < bamboos[b_idx].size(); i++) {
			int l = prev_small[b_idx][i] + 1, r = next_small[b_idx][i] - 1;

			int x1 = bamboos[b_idx][l], y1 = bamboos[b_idx][r];
			if (x1 > y1) {
				swap(x1, y1);
			}

			if ((r - l + 1) * donation[bamboos[b_idx][i]] > ans) {
				ans = (r - l + 1) * donation[bamboos[b_idx][i]];
				anss.clear();
				anss.push_back({ x1,y1 });
			}
			if ((r - l + 1) * donation[bamboos[b_idx][i]] == ans) {
				anss.push_back({ x1,y1 });
			}
		}
	}

	sort(anss.begin(), anss.end());
	cout << ans << '\n';
	cout << anss[0].first << ' ' << anss[0].second << '\n';
}