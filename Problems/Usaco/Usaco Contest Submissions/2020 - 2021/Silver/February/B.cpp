// O(nlogn)
#include<bits/stdc++.h>
using namespace std;

int n, k, skipped_days = 0;
vector<int> days = { 0 }, gaps;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		// required times we need to jump to to visit all ancestors
		int a; cin >> a; days.push_back((a + 11) / 12 * 12);
	}

	// sort the required times and remove duplicates
	sort(days.begin(), days.end());
	days.resize(int(unique(days.begin(), days.end()) - days.begin()));
	
	// find the sum of the k-1 largest gaps
	for (int i = 0; i < int(days.size())-1; i++) {
		gaps.push_back(days[i + 1] - days[i] - 12);
	}
	sort(gaps.begin(), gaps.end(), greater<int>());
	for (int i = 0; i < min(int(gaps.size()), k - 1); i++) {
		skipped_days += gaps[i];
	}

	cout << days.back() - skipped_days << '\n';
}