#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m;

	vector<int> circle(n);
	iota(circle.begin(), circle.end(), 1);

	int curr = 0;
	while (circle.size() > 1) {
		curr = (curr + m) % circle.size();
		circle.erase(circle.begin() + curr);
	}

	cout << circle[0];
}