#include<bits/stdc++.h>
using namespace std;

const long long maxn = 2e5 + 1;
long long n;
long long a[maxn];
long long degree[maxn];

vector<long long> adj[2][maxn];

struct bit {

	long long n;
	vector<long long> b;
	vector<long long> a;

	bit() {}
	bit(long long n2, long long val = 0) {
		n = n2 + 1;
		a.resize(n);
		b = vector<long long>(n, val);
		if (val) {
			for (long long i = 0; i < n2; i++) {
				add(i, val);
			}
		}
	}
	bit(vector<long long>& b2) {
		n = b2.size() + 1;
		a.resize(n);
		b = b2;
		for (long long i = 0; i < b.size(); i++) {
			add(i, b[i]);
		}
	}

	void add(long long idx, long long val) {
		b[idx] += val;
		for (idx++; idx < n; idx += idx & -idx) {
			a[idx] += val;
		}
	}

	void assign(long long idx, long long val) {
		long long val2 = val;
		val -= b[idx];
		b[idx] = val2;

		add(idx, val);
	}

	long long sum(long long idx) {
		long long tot = 0;
		for (idx++; idx > 0; idx -= idx & -idx) {
			tot += a[idx];
		}

		return tot;
	}

	long long sum(long long l, long long r) {
		return sum(r) - sum(l - 1);
	}
};

priority_queue<pair<long long, long long>, vector<pair<long long, long long>>> pq;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	assert(n <= 1e5);

	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}

	// set up adj list
	for (long long i = 0; i < n-1; i++) {
		long long a, b; cin >> a >> b;
		adj[1][b].push_back(a);
		degree[a] += 1;
	}

	for (long long i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			pq.push({ a[i],i });
		}
	}

	bit bt(2*maxn);
	long long tot_score = 0;

	while (!pq.empty()) {
		auto curr = pq.top(); pq.pop();
		long long i = curr.second;

		tot_score += 3 * a[i] + bt.sum(i - 1);
		//cout << i << ' ' << 3 * a[i] << ' ' << bt.sum(i - 1) << '\n';
		bt.add(i, a[i]);

		for (auto ne : adj[1][i]) {
			degree[ne] -= 1;
			if (degree[ne] == 0) {
				pq.push({ a[ne],ne });
			}
		}
	}
	
	cout << tot_score;
}