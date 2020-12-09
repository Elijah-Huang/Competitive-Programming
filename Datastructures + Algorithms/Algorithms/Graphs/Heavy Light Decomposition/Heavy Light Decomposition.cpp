#include<bits/stdc++.h>
using namespace std;

int t = 0;
const int maxn = 1e5 + 1;
int sizes[maxn], tin[maxn], tout[maxn], top_segment[maxn];
vector<int> adj[maxn];

void dfs_size(int curr, int parent) {
	for (auto& neighbor : adj[curr]) {
		if (neighbor == parent) continue;
		dfs_size(neighbor, curr);
		sizes[curr] += sizes[neighbor];
		if (sizes[neighbor] > sizes[adj[curr][0]]) {
			swap(neighbor, adj[curr][0]);
		}
	}
	sizes[curr]++;
}

void dfs_hld(int curr, int parent) {
	tin[curr] = t++;
	for (auto& neighbor : adj[curr]) {
		if (neighbor == parent) continue;
		top_segment[neighbor] = (neighbor == adj[curr][0] ? top_segment[curr] : neighbor);
		dfs_hld(neighbor, curr);
	}
	tout[curr] = t++;
}
