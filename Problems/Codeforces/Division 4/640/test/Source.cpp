#include <bits/stdc++.h>
#include <array>
#include <unordered_map>
using namespace std;
class boi {
	int bois = 1234;
};
int main() {
	ios_base::sync_with_stdio(0);
	int ar1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	array<int,3> myarray[3];
	//auto c = begin(ar2);
	vector<int> v;
	unordered_map<int, int> soi;
	soi[1] = 2;
	soi.insert(pair<int,int> (2, 3));
	cout << soi[1];
	cout << soi[2];
	/*for (auto i = soi.begin(); i != soi.end(); i ++) {
		cout << i->first << " " << i->second << '\n';
	}*/
	copy(ar1, ar1 + sizeof(ar1)/sizeof(ar1[0]), inserter(myarray,myarray.begin()));
	for (auto i : myarray) {
		cout << i;
	}
	/*for (vector<int>::iterator i = v.begin(); i < v.end(); i++) {
		std::cout << *i;
	}*/
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