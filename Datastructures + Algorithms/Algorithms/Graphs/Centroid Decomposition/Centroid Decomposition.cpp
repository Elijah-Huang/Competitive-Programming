#include<bits/stdc++.h>
using namespace std;

/* The centroid of a tree is a vertex v such that the sizes of the connected components
* that remain after removing v are all <= n/2 where n is the size of the tree
* There are at most 2 centroids in a tree and if there are 2 they are adjacent
* Note this also means that the centroids are also vertices such that removing them 
* leaves the smallest largest connected component
*/

const int maxn = 1e5 + 1;
vector<int> adj[maxn];
bool removed[maxn];
int sizes[maxn];
int currn, centroid, parent_of_centroid;

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
	currn = n;
	find_centroid(v, -1);
	int curr_centroid = centroid;
	int curr_parent_of_centroid = parent_of_centroid;

	// solve the tree rooted at the centroid

	removed[curr_centroid] = 1;
	for (auto c : adj[curr_centroid]) {
		if (!removed[c]) {
			if (c != curr_parent_of_centroid) {
				solve(c, sizes[c]);
			}
			else {
				solve(c, currn - sizes[curr_centroid]);
			}
		}
	}
}