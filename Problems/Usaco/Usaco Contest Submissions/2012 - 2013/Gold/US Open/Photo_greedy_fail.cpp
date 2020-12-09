#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("photo.in", "r", stdin); freopen("photo.out", "w", stdout);
	freopen("photo_open13_gold/4.in", "r", stdin);
	int n, m; cin >> n >> m;
	cout << n << ' ' << m << '\n';
	int spotted_cows = 0;
	int last_end = 0;
	set<pair<int, int>> active, active2; 
	set<pair<int, int>> events({ {n + 1, n+1} });
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (b <= 17) {
			cout << a << ' ' << b << '\n';
		}
		events.insert({ a,b });
		events.insert({ b,int(1e6) + a });
	}
	freopen("photo_open13_gold/4.out", "r", stdin);
	int a; cin >> a;
	cout << a << '\n';
	/*
	for (auto i = events.begin(); i != events.end(); i++) {
		auto e = *i;

		if (e.second < 1e6) {
			if (e.second <= last_end) {
				cout << -1;
				return 0;
			}
			if (active.empty()) {
				spotted_cows += e.first - last_end - 1;
			}
			active.insert(e);
			active2.insert({ e.second,e.first });
		}
		else {
			e = { e.second - int(1e6), e.first };
			if (!active.count(e)) {
				continue;
			}
			cout << e.first << ' ' << e.second << '\n';
			cout << active2.count({ 10,4 }) << '\n';
			int max_end = e.second;
			int max_start = max(last_end + 1, e.first);

			auto curr_seg = active.lower_bound({ e.first,1e6 });
			while (curr_seg != active.begin()) {
				--curr_seg;
				max_end = max(max_end, curr_seg->second);
			} 

			auto curr_seg2 = --active2.lower_bound({ max_end,1e6 });
			while (true) {
				if (curr_seg2->second > e.second) {
					cout << -1;
					return 0;
				}
				else {
					max_start = max(max_start, curr_seg2->second);
				}

				if (curr_seg2 != active2.begin()) {
					curr_seg2--;
				}
				else {
					break;
				}
			}

			auto end = active.lower_bound({ max_start, 1e6 });
			cout << max_start << '\n';
			for (auto i = active.begin(); i != end;) {
				auto i2 = next(i);
				auto val = *i;
				active.erase(i);
				active2.erase({ val.second,val.first });
				max_end = max(max_end, val.second);
				i = i2;

			}
			
			spotted_cows++;
			last_end = max_end;
		}
	}
	*/

	for (auto i = events.begin(); i != events.end(); i++) {
		auto e = *i;

		if (e.second < 1e6) {
			if (e.second <= last_end) {
				cout << e.first << ' ' << e.second << ' ' << last_end << '\n';
				cout << -1;
				return 0;
			}
			if (active.empty()) {
				spotted_cows += max(0,e.first - last_end - 1);
			}
			active.insert(e);
			active2.insert({ e.second, e.first });
		}
		else {
			e = { e.second - int(1e6), e.first };
			if (!active.count(e)) {
				continue;
			}

			int max_end = e.second;
			int max_start = max(last_end + 1, e.first);
			auto start_iter = active.begin();
			auto end_iter = active2.begin();
			bool start_increased = true;
			while (start_increased) {
				start_increased = false;
				cout << max_start << ' ' << max_end << '\n';
				auto curr_seg = active.lower_bound({ max_start,1e6 });
				auto new_start_iter = curr_seg;
				while (curr_seg != start_iter) {
					--curr_seg;
					max_end = max(max_end, curr_seg->second);
				}
				start_iter = new_start_iter;

				auto curr_seg2 = active2.lower_bound({ max_end,1e6 });
				auto new_end_iter = curr_seg2;
				while (curr_seg2 != end_iter) {
					--curr_seg2;
					if (curr_seg2->second > e.second) {
						cout << -1;
						return 0;
					}
					else {
						if (curr_seg2->second > max_start) {
							max_start = curr_seg2->second;
							start_increased = true;
						}
					}
				}
				end_iter = new_end_iter;
				cout << start_increased << '\n';
			}

			auto end = active.lower_bound({ max_start, 1e6 });
			for (auto i = active.begin(); i != end;) {
				auto i2 = next(i);
				auto val = *i;
				active.erase(i);
				active2.erase({ val.second,val.first });
				i = i2;

			}

			spotted_cows++;
			last_end = max_end;
		}
	}

	cout << spotted_cows << '\n';
}