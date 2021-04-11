// proof by ac? no idea if this will work, but I'm using f test to compare variances -> pick player with highest f test stat
// idea is that distrib of diffs will have more diffs at lower vals given a fixed mean for cheaters compared to if they didn't cheat
// it doesn't even have 10% accuracy
#include<bits/stdc++.h>
using namespace std;

const int players = 1e2, q = 1e4;
int t, p;
string results[players];
string hypothesis_result;
int correct[players];

// rng stuff
mt19937 rng_base(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> distrib(0, 1e6);

// -3 -> 3
double rng() {
	return 3 * (distrib(rng_base) - 5e5) / 5e5;
}

// 0 -> 1
double rng2() {
	return distrib(rng_base) / 1e6;
}


double sigmoid(double s, double q) {
	return 1 / (1 + exp(-(s - q)));
}

double skill(int target_correct) {
	double l = -3, r = 3;
	while (r - l > 1e-3) {
		double m = (r + l) / 2;
		double corr = 0;
		double q_j;

		for (int j = 0; j < q; j++) {
			q_j = rng();
			corr += 1 / (1 + exp(-(m - q_j)));
		}

		if (corr > target_correct) {
			r = m;
		}
		else {
			l = m;
		}
	}

	return (l + r) / 2;
}

// variance of the sample distribtuion of distances between consecutive ones
double variance(string& s) {
	int lst = -1;
	vector<int> dist;
	for (int i = 0; i < q; i++) {
		if (s[i] == '1') {
			dist.push_back(i - lst);
			lst = i;
		}
	}

	double mean = double(accumulate(dist.begin(), dist.end(), 0)) / dist.size();
	double diff_squared = 0;
	for (auto d : dist) {
		diff_squared += (d - mean) * (d - mean)/(dist.size()-1);
	}

	return sqrt(diff_squared);
}


int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t >> p;

	for (int cas = 1; cas <= t; cas++) {
		memset(correct, 0, sizeof(correct));
		int cheater = -1;
		double mx_f_test_statistic = 0;

		for (int i = 0; i < players; i++) {
			cin >> results[i];
			for (int j = 0; j < q; j++) {
				correct[i] += results[i][j] == '1';
			}

			// bin search for skill if they weren't cheating
			double percieved_s = skill(correct[i]);

			// random sample of 10k questions answered based on percieved skill
			hypothesis_result = "";
			for (int j = 0; j < q; j++) {
				double q_j = rng();
				if (rng2() < (sigmoid(percieved_s, q_j))) {
					hypothesis_result += "1";
				}
				else {
					hypothesis_result += "0";
				}
			}

			double f_test_statistic = variance(hypothesis_result) / variance(results[i]);
			if (mx_f_test_statistic < f_test_statistic) {
				mx_f_test_statistic = f_test_statistic;
				cheater = i + 1;
			}
		}

		cout << "Case #" << cas << ": " << cheater << '\n';
	}
}