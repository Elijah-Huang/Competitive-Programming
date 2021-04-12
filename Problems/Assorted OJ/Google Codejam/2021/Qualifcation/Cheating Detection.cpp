#include<bits/stdc++.h>
using namespace std;

int t,  p;
pair<int,pair<int,string>> answers[100]; // answered_correctly, answers

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t >> p;

	for (int cse = 1; cse <= t; cse++) {
		for (int i = 0; i < 100; i++) {
			answers[i].first = 0;
			answers[i].second.first = i;
			cin >> answers[i].second.second;

			for (int j = 0; j < 1e4; j++) {
				answers[i].first += answers[i].second.second[j] == '1';
			}
		}
		sort(answers, answers + 100);

		vector<pair<int,int>> num_correct(1e4); // num correct for each problem
		for (int i = 0; i < 1e4; i++) {
			num_correct[i].second = i;
			for (int j = 0; j < 100; j++) {
				num_correct[i].first += answers[j].second.second[i] == '1';
			}
		}
		sort(num_correct.begin(), num_correct.end());
		
		for (int i = 0; i < 100; i++) {
			answers[i].first = 0;
			// testing extreme cases is good, but since the "perceived skill" of the cheater
			// is always quite high since they get at least 50% right, checking just the easiest
			// problems is enough to pass (and may or may not be better since this is where 
			// the greatest difference between skill and problem difficulty occurs)

			// easiest problems
			for (int j = 0; j < 500; j++) {
				answers[i].first += answers[i].second.second[num_correct[j].second] == '1';
			}

			// hardest problems
			for (int j = 1e4-1; j >= 1e4-500; j--) {
				answers[i].first += answers[i].second.second[num_correct[j].second] == '1';
			}
		}

		int most_sus = -1, greatest_diff = -1;
		for (int i = 0; i < 100; i++) {
			int curr_diff = 0;

			if (i > 0) {
				curr_diff += abs(answers[i].first - answers[i - 1].first);
			}
			if (i < 100-1) {
				curr_diff += abs(answers[i].first - answers[i + 1].first);
			}
			if (i == 0 or i == 100-1) {
				curr_diff *= 2;
			}

			if (curr_diff > greatest_diff) {
				greatest_diff = curr_diff;
				most_sus = answers[i].second.first + 1;
			}
		}

		cout << "Case #" << cse << ": " << most_sus << '\n';
	}
}