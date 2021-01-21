#include<bits/stdc++.h>
using namespace std;

int c, n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> c >> n;
	
	vector<int> idx(c + 1);
	vector<pair<int, int>> idx_val;
	int end = 1;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		idx[k] = i;
	}

	while (!idx.empty()) {
		if (idx.back() != 0) {
			idx_val.push_back({ idx.back(),idx.size() - 1 });
		}
		idx.pop_back();
	}

	sort(idx_val.begin(), idx_val.end());

	cout << idx_val.size() << '\n';
	for (int i = 0; i < idx_val.size(); i++) {
		cout << idx_val[i].second << '\n';
	}

}