#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("gangs.in", "r", stdin); freopen("gangs.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> gangs(m);
	vector<int> suffix_mx(m + 1);
	for (int i = 0; i < m; i++) {
		cin >> gangs[i];
	}

	int mx = 0;
	for (int i = m - 1; i >= 0; i--) {
		mx = max(mx, gangs[i]);
		suffix_mx[i] = mx;
	}

	if (2 * mx >= n and 2*gangs[0] < n) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		int ans = min(gangs[0] - ((n - gangs[0]) & 1), n - 2 * suffix_mx[1]);
		cout << ans << '\n';
		gangs[0] -= ans;
		n -= ans;
		int curr_num = 0;
		int control_gang = 0;
		int used_up = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < gangs[i]; j++) {
				if (curr_num == 0) {
					control_gang = i + 1;
				}

				if (control_gang != i + 1) {
					if (n - used_up >= 2 * suffix_mx[i+1] + 2) {
						curr_num--;
						used_up += 2;
						cout << i + 1 << '\n';
					}
					else {
						gangs[i] = gangs[i] - j;
						int remove_with = suffix_mx[i + 1];
						int remove_idx = 0;
						for (int i2 = i + 1; i2 < m; i2++) {
							if (gangs[i2] == remove_with) {
								remove_idx = i2;
								break;
							}
						}

						for (int k = 0; k < curr_num; k++) {
							cout << remove_idx + 1 << '\n';
							gangs[remove_idx]--;
						}
						for (; i < m; i++) {
							for (int k = 0; k < gangs[i]; k++) {
								cout << i + 1 << '\n';
							}
							if (i < remove_idx) {
								for (int k = 0; k < gangs[i]; k++) {
									cout << remove_idx + 1 << '\n';
									gangs[remove_idx]--;
								}
							}
						}
						break;
					}
				}
				else {
					curr_num++;
					cout << i + 1 << '\n';
				}
			}
		}
		for (int i = 0; i < ans; i++) {
			cout << 1 << '\n';
		}
	}
}