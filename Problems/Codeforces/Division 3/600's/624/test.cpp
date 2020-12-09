#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
	clock_t start, end; 
	start = clock();
	cout << static_cast<long long>(1 << 30) * (1 << 30) << '\n';
	cout << long long(1 << 30) * (1 << 30) << '\n';
	cout << (long long)(1 << 30) * (1 << 30) << '\n';
	cout << ((long long)1 << 30) * (1 << 30) << '\n';
	cout << (1ll << 30) * (1 << 30) << '\n';
	vector<vector<int>> a = { { 1, 2, 3, 4 }, { 1,2,3 },{1,2} ,{ 41345,3451,132 },{2,3,4} };
	set<vector<int>> s(a.begin(), a.end());
	cout << "{ ";
	for (auto s2 : s) {
		cout << "{ ";
		for (int i : s2) {
			cout << i << ' ';
		}
		cout << "} ";
	}
	cout << "}\n";
	set<pair<int, int>> b({ {1,2},{2,3} });
	unordered_set<string> c({ "asdf","234523", "hjk234" });
	for (auto i : c) {
		cout << i + '\n';
	}
	//vector<int> a = { 1,2,3 };
	//vector<int> b(s.begin(),s.end());
	vector<vector<int>> v = { {10,2,3},{2,3,4},{2,2,5}, {3,10000,19999999},{1999,12},{12} };
	sort(v.begin(), v.end(), greater<vector<int>>());
	cout << "{ ";
	for (auto v2 : v) {
		cout << "{ ";
		for (int i : v2) {
			cout << i << ' ';
		}
		cout << "} ";
	}
	cout << "}";
	end = clock();
	double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
	cout << '\n' << fixed << time_taken;
}
