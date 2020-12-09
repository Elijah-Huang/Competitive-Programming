#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("censor.in", "r", stdin); freopen("censor.out", "w", stdout);
	string s, t, sr, tr;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	sr = s; tr = t;
	reverse(sr.begin(), sr.end());
	reverse(tr.begin(), tr.end());
	vector<int> pfp(m);
	vector<int> pfs(m);
	vector<int> suffix(n);
	vector<int> prefix(n);

	for (int i = 1; i < m; i++) {
		int j = pfp[i - 1];
		while (j > 0 and t[i] != t[j]) {
			j = pfp[j - 1];
		}
		pfp[i] = (t[i] == t[j]) ? j + 1 : 0;
	}
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 and s[i] != t[j]) {
			j = pfp[j - 1];
		}
		j = (s[i] == t[j]) ? j + 1 : 0;
		prefix[i] = j;
	}

	for (int i = 1; i < m; i++) {
		int j = pfs[i - 1];
		while (j > 0 and tr[i] != tr[j]) {
			j = pfs[j - 1];
		}
		pfs[i] = (tr[i] == tr[j]) ? j + 1 : 0;
	}
	j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 and sr[i] != tr[j]) {
			j = pfs[j - 1];
		}
		j = (sr[i] == tr[j]) ? j + 1 : 0;
		suffix[n-1-i] = j;
	}

	set<pair<int, int>> removed_segs;

	for (int i = 0; i < n; i++) {
		if (prefix[i] == m) {
			removed_segs.insert({ i - (m - 1), i });
			break;
		}
	}

	bool seg_to_right = removed_segs.size() > 0;
	int right_idx = -1;
	while (seg_to_right) {
		auto curr = removed_segs.upper_bound({ right_idx, 0 });
		if (curr == removed_segs.end()) {
			bool found = false;
			for (int i = removed_segs.rbegin()->second + 1; i < n; i++) {
				if (suffix[i] == m) {
					found = true;
					if (i == removed_segs.rbegin()->second + 1) {
						pair<int, int> new_seg = { removed_segs.rbegin()->first , i + (m-1) };
						removed_segs.erase(*removed_segs.rbegin());
						removed_segs.insert(new_seg);
						right_idx = new_seg.first -1;
					}
					else {
						removed_segs.insert({ i, i + (m - 1) });
						right_idx = i - 1;
					}
					break;
				}
			}
			if (!found) {
				break;
			}
		}
		else if (curr->first != 0 and curr->second != n - 1
			and prefix[curr->first-1] + suffix[curr->second+1] == m) {
			pair<int, int> new_seg = { curr->first - prefix[curr->first - 1],
				curr->second + suffix[curr->second + 1] };
			if (curr != removed_segs.begin()) {
				auto before = curr; --before;
				if (new_seg.first <= before->second) {
					right_idx = curr->second;
					continue;
				}
				if (new_seg.first == 1 + before->second) {
					new_seg.first = before->first;
					removed_segs.erase(before);
				}
			}
			if (*curr != *removed_segs.rbegin()) {
				auto after = curr; after++;
				if (new_seg.second >= after->first) {
					right_idx = curr->second;
					continue;
				}
				if (new_seg.second == after->first - 1) {
					new_seg.second = after->second;
					removed_segs.erase(after);
				}
			}
			right_idx = new_seg.first - 1;
			removed_segs.erase(curr);
			removed_segs.insert(new_seg);
		}
		else {
			right_idx = curr->second;
		}
	}

	vector<bool> can_place(n, 1);
	for (auto& seg : removed_segs) {
		for (int i = seg.first; i <= seg.second; i++) {
			can_place[i] = 0;
		}
	}
	string res;
	for (int i = 0; i < n; i++) {
		if (can_place[i]) {
			res.push_back(s[i]);
		}
	}

	cout << res << '\n';
}