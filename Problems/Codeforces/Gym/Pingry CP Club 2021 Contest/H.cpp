#include<bits/stdc++.h>
using namespace std;

struct friendship {
	int a, b;
};

const int mod = 1e9 + 7, maxn = 1e5 + 1;
int n, m;
vector<friendship> friendships[maxn];
int clique_scores[maxn];
long long community_score = 1;

int modexp(long long b, int exp) {
	long long res = 1;
	while (exp) {
		if (exp & 1) {
			res = (res * b) % mod;
		}

		b = (b * b) % mod;
		exp >>= 1;
	}

	return res;
}

int parent[maxn];
int sizes[maxn];

int find_parent(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = find_parent(parent[v]);
}

void union_sets(friendship f, int t) {
	int a = find_parent(f.a);
	int b = find_parent(f.b);

	if (a != b) {
		if (sizes[a] < sizes[b]){
			swap(a, b);
		}

		parent[b] = a;
		sizes[a] += sizes[b];

		community_score = (community_score * modexp((long long)clique_scores[a] * clique_scores[b]%mod, mod - 2)) % mod;
		clique_scores[a] = (clique_scores[a] + clique_scores[b] + t) % mod;
		community_score = (community_score * clique_scores[a]) % mod;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, t; cin >> a >> b >> t;
		friendships[t].push_back({ a,b });
	}

	iota(parent, parent + maxn, 0);
	fill(sizes, sizes + maxn, 1);
	fill(clique_scores, clique_scores + maxn, 1);

	for (int i = 1; i <= n; i++) {
		for (auto& f : friendships[i]) {
			union_sets(f, i);
		}

		cout << community_score << '\n';
	}
}