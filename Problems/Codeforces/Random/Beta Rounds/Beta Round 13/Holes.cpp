#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, m;

// sqrt decomp
const int bsz = 330;
int parent[maxn], block_jump[maxn], num_block_jump[maxn];

// O(2*block sz)
void update(int a, int b) {
	parent[a] = a + b;

	int block = a / bsz;
	int start_block = block * bsz;
	int start_nxt_block = (block + 1) * bsz;
	int curr = a;
	int jumps = 0;
	while (curr < n and curr < start_nxt_block) {
		jumps += 1;
		curr = parent[curr];
	}

	vector<int> num_jumps(a - start_block + 1);
	num_block_jump[a] = num_jumps[a - start_block] = jumps;
	block_jump[a] = curr;
	for (int i = a-1; i >= start_block; i--) {
		if (parent[i] <= a and num_jumps[parent[i]-start_block]) {
			num_block_jump[i] = num_jumps[i-start_block] = num_jumps[parent[i]-start_block] + 1;
			block_jump[i] = curr;
		}
	}
}

// O(n/(block size) + block size) 
pair<int, int> drop(int a) {
	int num_jumps = 0;
	while (block_jump[a] < n) {
		num_jumps += num_block_jump[a];
		a = block_jump[a];
	}
	while (parent[a] < n) {
		num_jumps += 1;
		a = parent[a];
	}
	return { a+1,num_jumps+1 };
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		parent[i] = i + p;
	}
	for (int i = 0; i < n; i++) {
		update(i, parent[i]-i);
	}


	while (m--) {
		int t; cin >> t;
		if (t == 0) {
			int a, b; cin >> a >> b; a--; b;

			update(a, b);
		}
		else {
			int a; cin >> a; a--;

			pair<int,int> ans = drop(a);
			cout << ans.first << ' ' << ans.second << '\n';
		}
	}
}