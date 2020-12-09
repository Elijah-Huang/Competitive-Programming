#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> gangs, int to_remove=0, int control_gang = -1) {
	if (control_gang != -1 and control_gang - 2 >= 0){
		to_remove += gangs[control_gang-2];
		gangs[control_gang - 2] = 0;
	}
	priority_queue<int> pq;
	for (int i = 0; i < gangs.size(); i++) {
		if (gangs[i]) {
			pq.push(gangs[i]);
		}
	}

	while (!pq.empty()) {
		if (to_remove == 0) {
			to_remove = pq.top(); pq.pop();
		}
		while (to_remove and !pq.empty()) {
			int curr_mx = pq.top(); pq.pop();
			to_remove--;
			curr_mx--;
			if (curr_mx) {
				pq.push(curr_mx);
			}
		}
	}

	return to_remove;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("gangs.in", "r", stdin); freopen("gangs.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> gangs(m);
	vector<int> lex_min;
	int gang1 = 0;
	for (int i = 0; i < m; i++) {
		cin >> gangs[i];
	}

	gang1 = gangs[0];
	gangs.assign(gangs.begin() + 1, gangs.end());
	int ans = solve(gangs);
	if (ans >= gang1) {
		cout << "NO\n";
		return 0;
	}

	for (int i = 0; i < ans; i++) {
		lex_min.push_back(1);
	}
	int to_remove = ans;
	int control_gang = 1;
	for (int j = 0; j < n - gang1; j++) {
		for (int i = 0; i < m - 1; i++) {
			if (gangs[i]) {
				gangs[i]--;
				int b_to_remove = to_remove;
				int b_control_gang = control_gang;
				if (i + 2 != control_gang and to_remove) {
					to_remove--;
				}
				else {
					if (to_remove == 0) {
						control_gang = i + 2;
					}
					to_remove++;
				}
				if (solve(gangs, to_remove, control_gang) == 0) {
					lex_min.push_back(i + 2);
					break;
				}
				else {
					gangs[i]++;
					to_remove = b_to_remove;
					control_gang = b_control_gang;
				}
			}
		}
	}
	for (int i = 0; i < gang1 - ans; i++) {
		lex_min.push_back(1);
	}
	
	cout << "YES\n";
	cout << gang1 - ans << '\n';
	for (auto i : lex_min) {
		cout << i << '\n';
	}
}