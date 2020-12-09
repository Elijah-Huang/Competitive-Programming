#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

struct edge {
	int w, u, v;
};

struct cmp {
	const bool operator()(const edge& a, const edge& b) const {
		return a.w < b.w;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("superbull.in", "r", stdin); freopen("superbull.out", "w", stdout);
	int n; cin >> n;
	vector<int> ids(n);
	for (int i = 0; i < n; i++) {
		cin >> ids[i];
	}

	long long score = 0;
	vector<bool> in_mst(n);
	priority_queue<edge, vector<edge>, cmp> pq;
	int added_points = 0;
	int mx_edge = 0;
	pq.push({ 0,0,0 });
	while (added_points != n) {
		edge curr = pq.top();
		pq.pop();
		if (!in_mst[curr.v]) {
			score += curr.w;
			in_mst[curr.v] = 1;
			added_points++;
			for (int j = 0; j < n; j++) {
				if (!in_mst[j]) {
					pq.push({ ids[curr.v] ^ ids[j],curr.v,j });
				}
			}
		}
	}

	cout << score;
}