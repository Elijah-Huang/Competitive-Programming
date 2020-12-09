#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

const int mod = 1e9 + 7;
long long n;
vector<long long> rand_nums = { 1981452,1235807,102893750,12389075,987645 };
vector<vector<int>> cow(5e4);

// too slow with map for some reason
struct cmp {
	int operator() (const vector<int>& a) const {
		int tot = 0;
		for (int i = 0; i < a.size(); i++) {
			tot = (tot + rand_nums[i] * a[i]) % mod;
		}
		return tot;
	}
};

long long total_pairs(int sz) {
	long long tot = 0;
	unordered_map<vector<int>, long long, cmp> mp;
	vector<int> subset(5 - sz);
	while (subset.size() != 5) {
		subset.push_back(1);
	}

	do {
		for (int i = 0; i < n; i++) {
			vector<int> curr_subset;
			for (int j = 0; j < 5; j++) {
				if (subset[j]) {
					curr_subset.push_back(cow[i][j]);
				}
			}
			mp[curr_subset]++;
		}
	} while (std::next_permutation(subset.begin(), subset.end()));
	
	for (auto& i : mp) {
		tot += (i.second) * (i.second - 1) / 2;
	}
	return tot;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowpatibility.in", "r", stdin); freopen("cowpatibility.out", "w", stdout);
	cin >> n;
	long long total = 0;
	for (int i = 0; i < n; i++) {
		int j = 5;
		while (j--) {
			int a; cin >> a;
			cow[i].push_back(a);
		}
		sort(cow[i].begin(), cow[i].end());
	}

	for (int sz = 1; sz <= 5; sz++) {
		total += (-1 + 2 * (sz % 2 == 1)) * (total_pairs(sz));
	}

	cout << n*(n-1)/2 - total;
}