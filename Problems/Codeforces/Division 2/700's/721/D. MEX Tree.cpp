// O(n)
// add nodes 0->n-1 one at a time and realize that they must create a path else answer is 0 from then
// with this in mind maintain the endpoints of the path using casework and tin/tout trick for verifying ancestor
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
vector<int> adj[maxn];

int t = 0;
int tin[maxn], tout[maxn];
int par[maxn];

long long sz[maxn];

void dfs(int curr, int parent) {
	par[curr] = parent;
	tin[curr] = t++;

	for (auto neighbor : adj[curr]) {
		if (neighbor != parent) {
			dfs(neighbor, curr);
			sz[curr] += sz[neighbor];
		}
	}
	
	sz[curr] += 1;

	tout[curr] = t++;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] and tout[v] <= tout[u];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	
	while (t--) {
		int n; cin >> n;

		fill(sz, sz + n, 0);
		fill(adj, adj + n, vector<int>());
		
		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}


		dfs(0, 0);

		// answers 0->1
		long long ans0 = 0;
		for (auto ne : adj[0]) 
		{
			ans0 += sz[ne] * (sz[ne] - 1) / 2;
		}
		cout << ans0 << ' ';
		
		long long ans1 = 0;
		long long tot = 1;
		for (auto ne : adj[0])
		{
			int sz_sub = sz[ne];

			if (is_ancestor(ne, 1))
			{
				sz_sub -= sz[1];
			}

			ans1 += sz_sub * tot;
			tot += sz_sub;
		}
		cout << ans1 << ' ';

		// answers 2 -> n
		vector<int> endpoints = { {0,0} }; // endpoints of path if 1 of them = 0 then endpoints[1] = 0
		int subtree_of_endpoint = 0;
		bool not_path = 0;

		for (int i = 1; i < n; i++) 
		{
			// update endpoints
			bool found = 0;
			if (not not_path) 
			{
				for (int j = 0; j < 2; j++)
				{
					int c = endpoints[j];

					if (is_ancestor(i, c))
					{ // on path btw endpoints
						found = 1;
						break;
					}
					else if (is_ancestor(c, i)) 
					{ // in subtree of endpoint new endpoint
						if (j == 1 and endpoints[0] != 0 and endpoints[1] == 0) 
						{
							// make sure lca = 0
							int curr = i;
							bool lca_not_0 = 0;

							while (curr != 0) 
							{
								if (is_ancestor(curr, endpoints[0])) 
								{
									// lca not 0
									lca_not_0 = 1;
									break;
								}

								curr = par[curr];
							}

							if (not lca_not_0) 
							{
								found = 1;
								endpoints[j] = i;
								break;
							}
						}
						else 
						{
							found = 1;
							endpoints[j] = i;
							break;
						}
					}
				}
			}

			if (not found) 
			{
				not_path = 1;
			}

			if (not not_path)
			{
				long long tot0 = sz[endpoints[0]];
				long long tot1 = sz[endpoints[1]];

				if (endpoints[1] == 0) 
				{ // remove extra
					if (not subtree_of_endpoint)
					{
						for (auto ne : adj[0])
						{
							if (is_ancestor(ne, endpoints[0]))
							{
								subtree_of_endpoint = ne;
								break;
							}
						}
					}

					tot1 -= sz[subtree_of_endpoint];
				}
				
				if (i + 1 < n and (is_ancestor(i + 1, endpoints[0]) or is_ancestor(i + 1, endpoints[1]))) 
				{
					// on the path so mex can't = i+1
					cout << 0 << ' ';
				}
				else 
				{
					// subtract paths if it is in subtree of endpoint
					if (is_ancestor(endpoints[0], i + 1))
					{ 
						tot0 -= sz[i + 1];
					}
					else if(is_ancestor(endpoints[1], i + 1)) 
					{
						if (endpoints[1] == 0 and is_ancestor(subtree_of_endpoint,i+1))
						{
							
						}
						else 
						{
							tot1 -= sz[i + 1];
						}
					}

					cout << tot0 * tot1 << ' ';
				}
			}
			else 
			{
				cout << 0 << ' ';
			}
		}

		cout << '\n';
	}
}