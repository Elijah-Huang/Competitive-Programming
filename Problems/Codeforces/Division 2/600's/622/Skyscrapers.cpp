#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	long long n, m[500000], L[500000], R[500000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	pair<int, int> curr, last;
	long long next;
	stack<pair<int, int>> s({ {m[0],0} });
	L[0] = m[0];
	for (int i = 1; i < n; i++) {
		next = m[i];
		while (!s.empty() and s.top().first > next) {
			s.pop();
		}
		if (!s.empty()) {
			last = s.top();
		}
		else {
			last = { 0,-1 };
		}
		if (last.second == -1) {
			L[i] = next * (i + 1);
		}
		else {
			L[i] = L[last.second] + next * (i - last.second);
		}
		s.push({ next,i });
	}
	stack<pair<int, int>> s2({ {m[n-1],n-1} });
	R[n - 1] = m[n - 1];
	for (int i = n-2; i >= 0; i--) {
		next = m[i];
		while (!s2.empty() and s2.top().first > next) {
			s2.pop();
		}
		if (!s2.empty()) {
			last = s2.top();
		}
		else {
			last = { 0,-1 };
		}
		if (last.second == -1) {
			R[i] = next * (n-i);
		}
		else {
			R[i] = R[last.second] + next * (last.second - i);
		}
		s2.push({ next,i });
	}
	int idx = 0;
	long long nxt, mx;
	for (int i = 0; i < n; i++) {
		nxt = L[i] + R[i] - m[i];
		if (nxt > mx) {
			idx = i;
			mx = nxt;
		}
	}
	int ans[500000];
	ans[idx] = m[idx];
	int prev = m[idx];
	for (int i = idx - 1; i >= 0; i--) {
		if (m[i] >= prev) {
			ans[i] = prev;
		}
		else {
			ans[i] = m[i];
			prev = m[i];
		}
	}
	prev = m[idx];
	for (int i = idx + 1; i < n; i++) {
		if (m[i] >= prev) {
			ans[i] = prev;
		}
		else {
			ans[i] = m[i];
			prev = m[i];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}