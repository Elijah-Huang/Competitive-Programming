#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("distant.in", "r", stdin); freopen("distant.out", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	vector<string> grid(n);
	int largest = n * n;
	vector<vector<long long>> dist(largest, vector<long long>(largest, 1ll << 32));
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (grid[i][j] != grid[i][j+1]) {
				dist[n * i + j][n * i + j + 1] = b;
				dist[n * i + j + 1][n * i + j] = b;
			}
			else {
				dist[n * i + j][n * i + j + 1] = a;
				dist[n * i + j + 1][n * i + j] = a;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (grid[i][j] != grid[i + 1][j]) {
				dist[n * i + j][n * (i + 1) + j] = b;
				dist[n * (i + 1) + j][n * i + j] = b;
			}
			else {
				dist[n * i + j][n * (i + 1) + j] = a;
				dist[n * (i + 1) + j][n * i + j] = a;
			}
		}
	}
	for (int k = 0; k < largest; k++) {
		for (int i = 0; i < largest; i++) {
			for (int j = 0; j < largest; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	long long mx_distance = 0;
	for (int i = 0; i < largest; i++) {
		for (int j = 0; j < largest; j++) {
			if (i != j) {
				mx_distance = max(mx_distance, dist[i][j]);
			}
		}
	}
	cout << mx_distance;
}