#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
long long left_inv = 0, right_inv = 0;

long long solve(int moving) {
	long long best = 1e11;
	long long curr_left = left_inv;
	long long curr_right = right_inv;
	long long base_inv = 0;
	int left_pointer = n-1, right_pointer = n;
	vector<int> psum(2*n);
	for (int i = 0; i < n; i++) {
		psum[i] = (a[i] == 1) + (i ? psum[i - 1] : 0);
	}
	for (int i = 2*n-1; i >= n; i--) {
		psum[i] = (a[i] == 0) + (i != 2*n - 1 ? psum[i + 1] : 0);
	}

	while (true) {
		while (left_pointer >= 0 and a[left_pointer] != (moving ^ 1)) {
			left_pointer--;
		}
		while (right_pointer < 2 * n and a[right_pointer] != moving) {
			right_pointer++;
		}
		if (left_pointer < 0 or right_pointer >= 2 * n) {
			break;
		}
		
		base_inv += right_pointer - left_pointer;
		if (moving) {
			curr_left -= psum[left_pointer];
			curr_right -= psum[right_pointer];
		}
		else {
			curr_left += psum[left_pointer] - 1 - (n - 1 - left_pointer);
			curr_right += psum[right_pointer] - 1 - (right_pointer - n);
		}

		best = min(best, base_inv + abs(curr_right - curr_left));

		left_pointer--;
		right_pointer++;
	}

	return best;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("balance.in", "r", stdin); freopen("balance.out", "w", stdout);
	cin >> n;
	a.resize(2 * n);
	for (int i = 0; i < 2*n; i++) {
		cin >> a[i];
	}
	
	int zeros = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 1) {
			left_inv += zeros;
		}
		else {
			zeros++;
		}
	}
	zeros = 0;
	for (int i = 2*n - 1; i >= n; i--) {
		if (a[i] == 1) {
			right_inv += zeros;
		}
		else {
			zeros++;
		}
	}

	cout << min({ abs(right_inv - left_inv), solve(0), solve(1) });
}