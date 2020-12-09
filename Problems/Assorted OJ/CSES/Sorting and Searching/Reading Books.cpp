#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> books(n);
	long long total;
	for (int i = 0; i < n; i++) {
		cin >> books[i];
	}

	sort(books.begin(), books.end());
	total = accumulate(books.begin(), books.end(), 0ll);

	if (total <= 2 * books.back()) {
		cout << 2 * books.back();
	}
	else {
		cout << total << '\n';
	}
}