#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int n, m;
int strength[maxn];

// dsu stuff
int parent[maxn];

int find_parent(int a) {
	if (a == parent[a]) {
		return a;
	}
	return parent[a] = find_parent(parent[a]);
}

int union_sets(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);

	if (a != b) {
		if (strength[a] < strength[b]) {
			swap(a, b);
		}
		parent[b] = a;

		return a;
	}
	else {
		return -1;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> strength[i];

		parent[i] = i;
	}

	while (m--) {
		int a, b; cin >> a >> b;

		cout << union_sets(a, b) << '\n';
	}
}