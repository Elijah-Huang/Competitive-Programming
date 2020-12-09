#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int c; cin >> c;
	set<int> df, dl;
	set<int> f, l;
	long long ans = 0;
	int lightnings = 0;
	while (c--) {
		int t, d; 
		cin >> t >> d;

		if (df.size()) {
			int val = *df.begin();
			df.erase(df.begin());
			f.insert(val);
			ans -= val;
		}
		if (dl.size()) {
			int val = *dl.begin();
			dl.erase(dl.begin());
			l.insert(val);
			ans -= val;
		}

		if (d > 0) {
			if (t == 1) {
				l.insert(d);
				ans += d;
				lightnings++;
			}
			else {
				f.insert(d);
				ans += d;
			}
		}
		else {
			d = -d;
			if (t == 1) {
				if (l.count(d)) {
					l.erase(d);
					ans -= d;
				}
				else {
					dl.erase(d);
					ans -= 2*d;
				}
				lightnings--;
			}
			else {
				if (f.count(d)) {
					f.erase(d);
					ans -= d;
				}
				else {
					df.erase(d);
					ans -= 2*d;
				}
			}
		}

		while (!(l.size() == 1 and f.size() == 0 or 
			dl.size() + df.size() == lightnings)) {
			if (f.size() == 0 and l.size() > 1) {
				int val = *(--l.end());
				l.erase(val);
				dl.insert(val);
				ans += val;
			}
			else if (f.size() > 0 and l.size() == 1) {
				int val = *(--f.end());
				f.erase(val);
				df.insert(val);
				ans += val;
			}
			else {
				int fval = *(--f.end());
				int lval = *(--l.end());
				if (fval > lval) {
					f.erase(fval);
					df.insert(fval);
					ans += fval;
				}
				else {
					l.erase(lval);
					dl.insert(lval);
					ans += lval;
				}
			}
		}

		cout << ans << '\n';
	}
}