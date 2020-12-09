#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("homework.in", "r", stdin); freopen("homework.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> grades(n);
	vector<int> mx_valuesk;
	long double max_score, curr_sum;
	for (int i = 0; i < n; i++) {
		cin >> grades[i];
	}
	int curr_min = min(grades[n - 1], grades[n - 2]);
	max_score = curr_sum = max(grades[n - 1], grades[n - 2]);
	mx_valuesk.push_back(n - 2);
	for (int i = n - 3; i >= 1; i--) {
		if (grades[i] < curr_min) {
			curr_sum += curr_min - grades[i];
			curr_min = grades[i];
		}
		else {
			curr_sum += grades[i];
		}
		if (fabs(curr_sum / (n - i - 1) - max_score) < 1e-10) {
			mx_valuesk.push_back(i);
		}
		else if (curr_sum / (n - i - 1) > max_score) {
			max_score = curr_sum / (n - i - 1);
			mx_valuesk.clear();
			mx_valuesk.push_back(i);
		}
	}
	reverse(mx_valuesk.begin(), mx_valuesk.end());
	for (auto k : mx_valuesk) {
		cout << k << "\n";
	}
	
}