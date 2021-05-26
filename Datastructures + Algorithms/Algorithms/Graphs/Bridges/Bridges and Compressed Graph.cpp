// finds bridges and creates a compressed graph 
// can count multiple edges as a bridge, so fix that if necessary
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, m;
vector<int> adj[2][maxn]; // adj[0] is the normal graph 
/* adj[1] is the graph where nodes are connected components if bridges are removed 
and the only edges are bridges. Guaranteed to be a forest*/

// for finding bridges
int t = 1;
int tin[maxn];
int low[maxn]; // lowest tin of a node in a path created by dfs that includes this node 
// (assuming paths end if it creates a cycle)
set<pair<int, int>> bridges;

// for finding comps after removing bridges
int curr_comp = 0; // in compressed graph adj[1]
int comp[maxn];

void dfs_bridges(int c, int p)
{
	tin[c] = low[c] = t++;

	for (auto ne : adj[0][c])
	{
		if (ne != p)
		{
			if (tin[ne])
			{
				low[c] = min(low[c], tin[ne]); // take on value of tin since cycle was made
			}
			else
			{
				dfs_bridges(ne, c);

				low[c] = min(low[c], low[ne]); // pass on value of tin from cycle

				if (low[ne] > tin[c])
				{
					// low[ne] <= tin[c] if edge ne->c was in a cycle otherwise it is a bridge
					bridges.insert({ ne,c });
				}
			}
		}
	}
}

void find_bridges()
{
	for (int i = 1; i <= n; i++)
	{
		if (tin[i] == 0)
		{
			dfs_bridges(i, -1);
		}
	}
}

void dfs_comp(int c)
{
	comp[c] = curr_comp;

	for (auto ne : adj[0][c])
	{
		if (comp[ne] == 0 and not bridges.count({ c,ne }) and not bridges.count({ ne,c })) 
		{
			dfs_comp(ne);
		}
	}
}

// finding connected components if we removed bridges
void find_comps() {
	for (int i = 1; i <= n; i++)
	{
		if (comp[i] == 0)
		{
			curr_comp++;
			dfs_comp(i);
		}
	}
}

// creates adj[1]
void create_compressed_graph()
{
	for (auto [u, v] : bridges)
	{
		if (comp[u] != comp[v])
		{
			adj[1][comp[u]].push_back(comp[v]);
			adj[1][comp[v]].push_back(comp[u]);
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;

		adj[0][a].push_back(b);
		adj[0][b].push_back(a);
	}

	find_bridges();

	find_comps();

	create_compressed_graph();
}