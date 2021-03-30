// assumes graph is connected and chooses the algo with best complexity
#include<vector>
#include<iostream>
#include<queue>
#include<tuple>
#include<ctime>
using namespace std;

// nodes, edges, ants
int n, m, k, ans;
vector<bool> has_ant;
vector<vector<pair<int, double>>> adj;

// O(k*m*log(k*m))
int dijkstra_pq() {
	vector<vector<double>> dist(n + 1, vector<double>(k,1e18));
	vector<int> ants_reached(n + 1);
	priority_queue<tuple<double,int,int>, vector<tuple<double,int,int>>, greater<tuple<double,int,int>>> pq;
	double d;
	int node, ant, ants = 0;

	for (int i = 1; i <= n; i++) {
		if (has_ant[i]) {
			pq.push({ 0,i,ants });
			dist[i][ants] = 0;
			ants++;
		}
	}
	
	int tot = 0;
	while (!pq.empty()) {
		tie(d, node, ant) = pq.top(); pq.pop();

		if (d == dist[node][ant]) {
			ants_reached[node]++;

			if (ants_reached[node] == k) {
				return node;
			}

			for (auto& [neighbor, w] : adj[node]) {
				double new_d = d + w;
				if (dist[neighbor][ant] > new_d) {
					dist[neighbor][ant] = new_d;
					pq.push({ new_d, neighbor, ant });
				}
			}
		}
	}
}

// O(k*n^2)
int dijkstra() {
	vector<double> mx_dist(n + 1);

	for (int i = 1; i <= n; i++) {
		if (has_ant[i]) {
			vector<double> dist(n + 1, 1e18);
			dist[i] = 0;
			vector<bool> visited(n + 1);

			for (int iters = 0; iters < n; iters++) {
				double min_dist = 1e18, min_node = -1;

				for (int j = 1; j <= n; j++) {
					if (!visited[j] and min_dist > dist[j]) {
						min_dist = dist[j];
						min_node = j;
					}
				}

				visited[min_node] = 1;
				for (auto& [neighbor, w] : adj[min_node]) {
					dist[neighbor] = min(dist[neighbor], min_dist + w);
				}
			}

			for (int j = 1; j <= n; j++) {
				mx_dist[j] = max(mx_dist[j], dist[j]);
			}
		}
	}

	return min_element(mx_dist.begin()+1,mx_dist.end()) - mx_dist.begin();
}

// O(n^3)
int floyd_warshall() {
	vector<vector<double>> dist(n + 1, vector<double>(n + 1, 1e18));
	vector<double> mx_dist(n + 1);

	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		for (auto& [neighbor, w] : adj[i]) {
			dist[i][neighbor] = dist[neighbor][i] = w;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (has_ant[i]) {
			for (int j = 1; j <= n; j++) {
				mx_dist[j] = max(mx_dist[j], dist[i][j]);
			}
		}
	}

	return min_element(mx_dist.begin()+1, mx_dist.end()) - mx_dist.begin();
}


int main() {
	cin.tie(0)->sync_with_stdio(0);

	cout << "Please enter the name of the input file (with .filetype)\n";
	string filename; cin >> filename;
	freopen(filename.c_str(), "r", stdin);

	cin >> n >> k;
	adj.resize(n + 1);
	has_ant.resize(n + 1);

	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		has_ant[a] = 1;
	}

	int u, v; 
	double w;
	while (cin >> u >> v >> w) {
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
		m++;
	}

	cout << n << ' ' <<  m << ' ' << k << '\n';
	
	if (10 * log(k * m) / log(2) < n) {
		// graph is sparse
		ans = dijkstra_pq();
	}
	else if (2*k < n)  {
		// dense graph with low number of ants
		ans = dijkstra();
	}
	else {
		// dense graph with high number of ants 
		// (constant factor of floyd lower since branchless?)
		ans = floyd_warshall();
	}

	clock_t t1, t2;
	t1 = clock();
	cout << "optimal from dijkstra_pq: " << dijkstra_pq() << '\n';
	t2 = clock(); 
	cout << "elapsed time: " << double(t2 - t1) / CLOCKS_PER_SEC << '\n';

	t1 = clock();
	cout << "optimal from dijkstra: " << dijkstra() << '\n';
	t2 = clock();
	cout << "elapsed time: " << double(t2 - t1) / CLOCKS_PER_SEC << '\n';

	t1 = clock();
	cout << "optimal from floyd_warshall: " << floyd_warshall() << '\n';
	t2 = clock();
	cout << "elapsed time: " << double(t2 - t1) / CLOCKS_PER_SEC << '\n';

	cout << "The best meeting place is node " << ans << '\n';
	return 0;
}