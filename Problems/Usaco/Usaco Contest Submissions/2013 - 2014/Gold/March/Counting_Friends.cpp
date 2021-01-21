#include<bits/stdc++.h>
using namespace std;

const int maxn = 501;
int n;
int degree[maxn];
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fcount.in", "r", stdin); freopen("fcount.out", "w", stdout);
	
	cin >> n;

	for (int i = 0; i <= n; i++) {
		cin >> degree[i];
	}

	for (int i = 0; i <= n; i++) {
		vector<int> a;
		for (int j = 0; j <= n; j++) {
			if (i != j) {
				a.push_back(degree[j]);
			}
		}
		sort(a.begin(), a.end());
		
		while(a.back() != 0) {

			for (int j = a.size() - 2; j >= 0; j--) {
				if (a.back() and a[j]) {
					a[j]--;
					a.back()--;
				}
				else {
					break;
				}
			}

			if (a.back() != 0) {
				break;
			}
			else {
				/*if this is not done the code TLEs (~ x10 runtime)
				(probably not because of the extra size of a, but rather 
				because sort() is quicker for partially sorted arrays?)
				*/
				a.pop_back();
			}
			

			sort(a.begin(), a.end());
		}

		if (a.back() == 0) {
			ans.push_back(i + 1);
		}
	}

	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i << '\n';
	}
}