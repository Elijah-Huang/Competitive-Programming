#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fairphoto.in", "r", stdin); freopen("fairphoto.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, char>> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i].first >> cows[i].second;
	}
	
	sort(cows.begin(), cows.end());	

	vector<int> psum(n);
	if (cows[0].second == 'W') {
		psum[0] = 1;
	}
	else {
		psum[0] = -1;
	}
	for (int i = 1; i < n; i++) {
		psum[i] = psum[i - 1] + -1 + 2 * (cows[i].second == 'W');
	}
	vector<int> first(1);
	int want = -1;
	for (int i = 0; i < n; i++) {
		if (psum[i] == want) {
			first.push_back(i);
			want--;
		}
	}
	
	int longest = 0;
	for (int end = n - 1; end >= 1; end--) {
		if (psum[end] >= 0) {
			if ((end + 1) % 2 == 0) {
				longest = max(longest, cows[end].first - cows[0].first);
			}
			else {
				longest = max(longest, cows[end].first - cows[1].first);
			}
		}
		else {
			if (first[-psum[end]] != end) {
				longest = max(longest, cows[end].first - cows[first[-psum[end]] + 1].first);
			}
		}
	}

	cout << longest;
}