#include<bits/stdc++.h>
using namespace std;

int q;
int num_triangles = 0;
map<pair<int, int>, set<int>> triangles;
set<pair<int, int>> edges;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> q;

	for (int i = 1; i <= q; i++) {
		int t, u, v; cin >> t >> u >> v;
		if (u > v) {
			swap(u, v);
		}

		if (t == 0) {
			if (u == v) {
				edges.insert({ u,i });
			}
			else {
				edges.insert({ u,i });
				edges.insert({ v,i });

				if (edges.count({ u,v })) {
					triangles[{u, v}].insert(i);
					triangles[{u, i}].insert(v);
					triangles[{v, i}].insert(u);

					num_triangles++;
				}
			}
		}
		else {
			edges.erase({ u,v });
			num_triangles -= triangles[{u, v}].size();
			for (auto i : triangles[{u, v}]) {
				int x = i, y = u;
				if (x > y) {
					swap(x, y);
				}
				triangles[{x, y}].erase(v);

				x = i, y = v;
				if (x > y) {
					swap(x, y);
				}
				triangles[{x, y}].erase(u);
			}
			triangles.erase({ u,v });

			edges.insert({ u,i });
			edges.insert({ v,i });
		}

		cout << num_triangles << '\n';
	}
}