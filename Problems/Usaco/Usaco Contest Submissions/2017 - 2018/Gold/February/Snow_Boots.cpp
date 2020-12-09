#include<bits/stdc++.h>
using namespace std;

struct boot {
	int f, d, i;
};

struct depth {
	int f, i;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("snowboots.in", "r", stdin); freopen("snowboots.out", "w", stdout);
	int n, b; cin >> n >> b;
	if (n == 1) {
		while (b--) {
			cout << 1 << '\n';
		}
	}
	vector<int> output(b);
	vector<depth> depths(n - 2);
	vector<boot> boots(b);
	multiset<int,greater<int>> gaps; set<int> walkable;
	int filler; cin >> filler;
	for (int i = 0; i < n - 2; i++) {
		cin >> depths[i].f;
		depths[i].i = i + 1;
	}
	cin >> filler;
	for (int i = 0; i < b; i++) {
		cin >> boots[i].f >> boots[i].d;
		boots[i].i = i;
	}

	sort(boots.begin(), boots.end(), [&](const boot& a, const boot& b) {return a.f < b.f; });
	sort(depths.begin(), depths.end(), [&](const depth& a, const depth& b) {return a.f < b.f; });

	walkable.insert(0);
	walkable.insert(n-1);
	gaps.insert(n - 2);
	int depth_idx = 0;
	for (auto& b : boots) {
		while (depth_idx < n-2 and depths[depth_idx].f <= b.f) {
			auto after = walkable.lower_bound(depths[depth_idx].i);
			auto before = after; before--;
			walkable.insert(depths[depth_idx].i);
			gaps.erase(gaps.find(*after - *before - 1));
			gaps.insert(depths[depth_idx].i - *before - 1);
			gaps.insert(*after - depths[depth_idx].i - 1);
			depth_idx++;
		}

		output[b.i] = b.d > *gaps.begin();
	}

	for (auto i : output) {
		cout << i << '\n';
	}
}