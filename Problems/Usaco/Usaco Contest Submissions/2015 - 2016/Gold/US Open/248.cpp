#include<bits/stdc++.h>
using namespace std;

int side_added(vector<int>& a, int largest) {
	int amt = 0;
	int curr = 0;
	int largest_count = 0;
	for (int i = 0; i < a.size(); i++) {
		if (curr == a[i]) {
			amt++;
		}
		else if (a[i] == largest) {
			largest_count += amt / (1 << (a[i] - curr));;
			break;
		}
		else {
			amt = 1 + amt / (1 << (a[i] - curr));
			curr = a[i];
		}
	}
	return largest_count;
}
int solve(vector<int> a) {
	int amt = 1;
	for (int i = 0; i < a.size() - 1; i++) {
		if (a[i] == a[i + 1]) {
			amt++;
		}
		else {
			if (i != a.size() -1 and i + 1 > amt and a[i - amt] > a[i] and a[i] < a[i + 1]) {
				if (amt % 2 == 0) {
					vector<int> first(a.begin(), a.begin() + i - amt + 1);
					vector<int> mid(amt / 2, a[i] + 1);
					vector<int> second(a.begin() + i + 1, a.end());
					first.insert(first.end(), mid.begin(), mid.end());
					first.insert(first.end(), second.begin(), second.end());
					return solve(first);
				}
				else {
					vector<int> first(a.begin(), a.begin() + i - amt + 1);
					vector<int> mid(amt / 2, a[i] + 1);
					vector<int> second(a.begin() + i + 1, a.end());
					first.insert(first.end(), mid.begin(), mid.end());
					second.insert(second.begin(), mid.begin(), mid.end());
					return max(solve(first), solve(second));
				}
			}
			else {
				amt = 1;
			}
		}
	}
	int largest = *max_element(a.begin(), a.end());
	int largest_count = 0;
	for (int i = 0; i < a.size(); i++) {
		largest_count += (a[i] == largest);
	}
	largest_count += side_added(a, largest);
	reverse(a.begin(), a.end());
	largest_count += side_added(a, largest);
	return largest + ilogb(largest_count);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("248.in", "r", stdin); freopen("248.out", "w", stdout);
	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << solve(nums);
}