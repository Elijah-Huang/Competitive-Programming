#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		vector<int> nums;
		int digit;
		int mult = 1;
		while (x) {
			digit = x % 10;
			if (digit) {
				nums.push_back(digit * mult);
			}
			mult *= 10;
			x /= 10;
		}
		cout << nums.size() << "\n";
		for (auto i : nums) {
			cout << i << " ";
		}
		cout << "\n";
	}	
}