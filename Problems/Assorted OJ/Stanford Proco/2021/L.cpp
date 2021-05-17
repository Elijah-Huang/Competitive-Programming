#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n, m;
vector<int> adj[2][maxn];
int out_degree[2][maxn];
int tot[2][maxn];
int unambiguous = 0;

void top_sort(int g) {
	int nodes_left = n;
	stack<int> degree_0;

	for (int i = 1; i <= n; i++) 
	{
		if (out_degree[g][i] == 0) 
		{
			degree_0.push(i);
			nodes_left--;
		}
	}

	while (!degree_0.empty()) 
	{
		int c = degree_0.top(); degree_0.pop();

		if (degree_0.size() == 0)
		{
			tot[g][c] += nodes_left;
		}

		for (auto ne : adj[g ^ 1][c])
		{
			out_degree[g][ne]--;
			if (out_degree[g][ne] == 0)
			{
				degree_0.push(ne);
				nodes_left--;
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		adj[0][a].push_back(b);
		out_degree[0][a]++;
		adj[1][b].push_back(a);
		out_degree[1][b]++;
	}

	top_sort(0);
	top_sort(1);

	for (int i = 1; i <= n; i++)
	{
		unambiguous += tot[0][i] + tot[1][i] == n - 1;
	}

	cout << unambiguous;
}