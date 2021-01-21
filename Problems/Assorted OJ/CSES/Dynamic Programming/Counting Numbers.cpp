#include<bits/stdc++.h>
using namespace std;

long long a, b;

long long no_adj(long long a) {
	if (a < 0) {
		return 0;
	}

	long long num_no_adj = 0;
	string b = to_string(a);

	for (int num_match = 0; num_match <= b.length(); num_match++) {
		if (num_match >=2 and b[num_match-1] == b[num_match - 2]) {
			break;
		}
		
		long long ways = 0;
		if (num_match == 0) {
			long long pow_9 = 1;

			ways += 1;
			for (int i = 0; i < b.length() - 1; i++) {
				pow_9 *= 9;
				ways += pow_9;
			}
			ways += (b[0] - '1') * pow_9;
		}
		else if (num_match == b.length()) { 
			ways = 1;
		}
		else {
			ways = b[num_match] - '0' - (b[num_match] > b[num_match - 1]);
			for (int i = num_match + 1; i < b.length(); i++) {
				ways *= 9;
			}
		}

		num_no_adj += ways;
	}

	return num_no_adj;
}

int main() {
	cin >> a >> b;

	cout << no_adj(b) - no_adj(a-1);
}