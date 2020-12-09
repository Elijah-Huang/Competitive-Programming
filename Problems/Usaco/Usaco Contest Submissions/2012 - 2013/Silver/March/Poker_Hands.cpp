#include<bits/stdc++.h>
using namespace std;

struct seg {
	int start, end;
};

struct seg_cmp {
	const bool operator()(const seg& a, const seg& b) const {
		return a.start < b.start;
	}
};

struct card {
	int rank, amount;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("poker.in", "r", stdin); freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	long long straights = 0;
	vector<int> ranks(n);
	vector<card> ranks2;
	for (int i = 0; i < n; i++) {
		cin >> ranks[i];
		ranks2.push_back({ i, ranks[i] });
	}
	set<seg, seg_cmp> segments = { { 0,n - 1 } };
	sort(ranks2.begin(), ranks2.end(),
		[&](const card& a, const card& b) {return a.amount < b.amount; });
	long long last_amount = 0;
	int i = 0;
	while (i < n) {
		long long curr_amount = ranks2[i].amount;
		straights += (curr_amount - last_amount) * segments.size();
		last_amount = curr_amount;
		while (i < n and ranks2[i].amount == curr_amount) {
			auto loc = segments.upper_bound({ ranks2[i].rank, ranks2[i].rank });
			loc--;
			int start = (*loc).start;
			int end = (*loc).end;
			if (end == ranks2[i].rank){
				if (start == end) {
					segments.erase(loc);
				}
				else {
					segments.erase(loc);
					segments.insert({ start,end - 1 });
				}
			}
			else if (start == ranks2[i].rank) {
				if (start == end) {
					segments.erase(loc);
				}
				else {
					segments.erase(loc);
					segments.insert({ start + 1,end });
				}
			}
			else  {
				segments.erase(loc);
				segments.insert({ start, ranks2[i].rank - 1 });
				segments.insert({ ranks2[i].rank + 1, end });
			}
			i++;
		}
	}
	cout << straights;
}