#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("planting.in", "r", stdin); freopen("planting.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> neighbors(n);
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		neighbors[u]++;
		neighbors[v]++;
	}
	cout << (*max_element(neighbors.begin(), neighbors.end()) + 1);
}