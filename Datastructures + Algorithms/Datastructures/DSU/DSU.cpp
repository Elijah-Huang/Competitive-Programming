#include<bits/stdc++.h>
using namespace std;

struct DSU {
	int n;
	vector<int> parent;
	vector<int> sizes;

	DSU() {}
	DSU(int n) {
		this->n = n;
		parent.resize(n + 1);
		iota(parent.begin(), parent.end(), 0);
		sizes.resize(n + 1);
		fill(sizes.begin(), sizes.end(), 1);
	}

	int find_parent(int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = find_parent(parent[x]);
	}

	bool union_sets(int a, int b) {
		a = find_parent(a);
		b = find_parent(b);

		if (a != b) {
			if (sizes[a] < sizes[b]) {
				swap(a, b);
			}

			parent[b] = a;
			sizes[a] += sizes[b];

			return 1;
		}

		return 0;
	}
};