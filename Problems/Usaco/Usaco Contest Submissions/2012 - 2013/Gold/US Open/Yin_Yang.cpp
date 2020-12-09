#include<bits/stdc++.h>
using namespace std;

/* The centroid of a tree is a vertex v such that the sizes of the connected components
* that remain after removing v are all <= n/2 where n is the size of the tree
* There are at most 2 centroids in a tree and if there are 2 they are adjacent
* Note this also means that the centroids are also vertices such that removing them
* leaves the smallest largest connected component
*/

const int maxn = 1e5 + 1;
vector<pair<int, int>> adj2[maxn];
vector<int> adj[maxn];
bool removed[maxn];
int sizes[maxn];
int currn, centroid, parent_of_centroid;

long long ans = 0;
int curr_path = 0;
int amts[2][2*maxn];
int on_path[2*maxn];
vector<pair<int, int>> subtree_amts;
vector<pair<int,int>> affected;
int two_to_root;

void solve_paths(int curr, int p) {
	subtree_amts.push_back({ on_path[curr_path + maxn] > 0,curr_path });
	if (curr_path == 0 and on_path[maxn] >= 2) {
		two_to_root++;
	}
	on_path[curr_path + maxn]++;

	for (auto c : adj2[curr]) {
		if (!removed[c.first] and c.first != p) {
			curr_path += c.second;
			solve_paths(c.first, curr);
			curr_path -= c.second;
		}
	}

	--on_path[curr_path + maxn];
}

/* Finds the sizes of the connected components leftover from removing every node
* Uses this to find the centroid
*/
bool find_centroid(int curr, int p) {
	int largest = 0;

	sizes[curr] = 1;
	for (auto c : adj[curr]) {
		if (!removed[c] and c != p) {
			if (find_centroid(c, curr)) {
				return 1;
			}

			sizes[curr] += sizes[c];
			largest = max(largest, sizes[c]);
		}
	}
	largest = max(largest, currn - sizes[curr]);

	if (largest <= currn / 2) {
		centroid = curr, parent_of_centroid = p;
		return 1;
	}
	else {
		return 0;
	}
}

/* Finds the centroid of the tree that v is in
* Solves the tree rooted at the centroid
* Recursively calls solve on the subtrees of the root/centroid
*/
void solve(int v, int n) {
	if (n <= 3) {
		return;
	}
	currn = n;
	find_centroid(v, -1);
	int curr_centroid = centroid;
	int curr_parent_of_centroid = parent_of_centroid;

	// solve the tree rooted at the centroid
	two_to_root = 0;
	on_path[maxn]++;
	for (auto c : adj2[centroid]) {
		if (!removed[c.first]) {
			curr_path += c.second;
			solve_paths(c.first, centroid);
			curr_path -= c.second;
			for (auto& i: subtree_amts){
				if (i.first == 0) {
					ans += amts[1][maxn - i.second];
				}
				else {
					if (i.second) {
						ans += amts[0][maxn - i.second] + amts[1][maxn - i.second];
					}
					else {
						ans += amts[1][maxn];
					}
				}
			}

			for (auto& i : subtree_amts) {
				amts[i.first][maxn + i.second]++;
			}
			affected.insert(affected.end(), subtree_amts.begin(), subtree_amts.end());
			subtree_amts.clear();
		}
	}
	on_path[maxn]--;

	ans += two_to_root;

	for (auto& i : affected) {
		amts[i.first][maxn + i.second]--;
	}
	affected.clear();

	// recursively solve leftover components
	removed[curr_centroid] = 1;
	for (auto c : adj[curr_centroid]) {
		if (!removed[c]) {
			if (c != curr_parent_of_centroid) {
				solve(c, sizes[c]);
			}
			else {
				solve(c, n - sizes[curr_centroid]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("yinyang.in", "r", stdin); freopen("yinyang.out", "w", stdout);
	int n; cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b, t; cin >> a >> b >> t;
		t = t ? 1 : -1;
		adj[a].push_back(b);
		adj[b].push_back(a);
		adj2[a].push_back({ b,t });
		adj2[b].push_back({ a,t });
	}
	
	solve(1, n);
	
	cout << ans << '\n';
}