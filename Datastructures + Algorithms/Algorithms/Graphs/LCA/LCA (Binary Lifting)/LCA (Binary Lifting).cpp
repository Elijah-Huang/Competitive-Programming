#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
vector<int> adj[maxn];

int max_p;
vector<vector<int>> ancestor;
int t = 0;
int tin[maxn], tout[maxn];

void dfs(int curr, int parent) 
{
	tin[curr] = t++;

	ancestor[curr][0] = parent;
	for (int i = 1; i <= max_p; i++)
	{
		ancestor[curr][i] = ancestor[ancestor[curr][i - 1]][i - 1];
	}

	for (auto neighbor : adj[curr])
	{
		if (neighbor != parent)
		{
			dfs(neighbor, curr);
		}
	}

	tout[curr] = t++;
}

// returns 1 if u is an ancestor of v else 0
bool is_ancestor(int u, int v) 
{
	return tin[u] <= tin[v] and tout[v] <= tout[u];
}

int lca(int u, int v) 
{
	if (is_ancestor(u, v)) 
	{
		return u;
	}
	else if (is_ancestor(v, u)) 
	{
		return v;
	}
	else 
	{
		for (int i = max_p; i >= 0; i--) 
		{
			if (!is_ancestor(ancestor[u][i], v))
			{
				u = ancestor[u][i];
			}
		}

		return ancestor[u][0];
	}
}

void precompute(int root) 
{
	max_p = ilogb(maxn-2);
	ancestor.assign(maxn, vector<int>(max_p + 1));

	dfs(root, root);
}