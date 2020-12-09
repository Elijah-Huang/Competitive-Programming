#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int k, n;
	long long time = 0;
	vector<int> a;
	vector<int> b;
	vector<int> ab;
	cin >> n >> k;
	int t, first, second;
	for (int i = 0; i < n; i++) {
		cin >> t >> first >> second;
		if (first == 1 and  second == 1) {
			ab.push_back(t);
		}
		else if (first == 1) {
			a.push_back(t);
		}
		else if (second == 1) {
			b.push_back(t);
		}
	}
	if (ab.size() + min(b.size(), a.size()) < k) {
		cout << -1;
	}
	else {
		sort(ab.begin(), ab.end(), greater<int>());
		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end(), greater<int>());
		while (k--) {
			if (ab.empty()) {
				time += a.back() + b.back();
				a.pop_back(); b.pop_back();
			}
			else if (a.empty() or b.empty()) {
				time += ab.back();
				ab.pop_back();
			}
			else if (ab.back() <= a.back() + b.back()) {
				time += ab.back();
				ab.pop_back();
			}
			else {
				time += a.back() + b.back();
				a.pop_back(); b.pop_back();
			}
		}
		cout << time;
	}
}