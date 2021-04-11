#include<bits/stdc++.h>
using namespace std;

int t;
int n;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int cse = 1; cse <= t; cse++) {
		cin >> n;

		long long ans = 0;
		vector<string> a;
		for (int i = 0; i < n; i++) {
			long long b2; cin >> b2;
			string b = to_string(b2);
			
			if (i > 0) {
				if (a[i-1].size() > b.size() or a[i - 1] >= b) {
					if (a[i - 1].size() == b.size()) {
						b.push_back('0');
						ans += 1;
					}
					else {
						int greater = 2;
						for (int j = 0; j < b.size(); j++) {
							if (b[j] != a[i - 1][j]) {
								greater = b[j] > a[i - 1][j];
								break;
							}
						}

						if (greater == 2) {
							bool all_9 = 1;
							for (int j = b.size(); j < a[i - 1].size(); j++) {
								if (a[i - 1][j] != '9') {
									all_9 = 0;
								}
							}
							if (!all_9) {
								ans += a[i - 1].size() - b.size();
								b = a[i - 1];
								for (int j = b.size()-1; j >= 0; j--) {
									if (b[j] != '9') {
										b[j] = char(b[j] + 1);
										for (int j2 = j + 1; j2 < b.size(); j2++) {
											b[j2] = '0';
										}
										break;
									}
								}
							}
							else {
								while (b.size() <= a[i - 1].size()) {
									b.push_back('0');
									ans += 1;
								}
							}
						}
						else if (greater == 0) {
							while (b.size() <= a[i - 1].size()) {
								b.push_back('0');
								ans += 1;
							}
						}
						else {
							while (b.size() < a[i - 1].size()) {
								b.push_back('0');
								ans += 1;
							}
						}
					}
				}
			}

			a.push_back(b);
		}

		cout << "Case #" << cse << ": " << ans << '\n';
	}
}