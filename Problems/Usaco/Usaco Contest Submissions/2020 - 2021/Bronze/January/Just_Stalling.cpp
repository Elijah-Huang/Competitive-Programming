#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;
int n;
int idx = 0;
long long ans = 1;
int a[maxn], b[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(b, b + n, greater<int>());
	sort(a, a + n, greater<int>());
	
	for (int i = 0; i < n; i++) {
		while (idx < n and a[i] <= b[idx]) {
			idx++;
		}
		ans *= idx - i;
	}

	cout << ans;
}
