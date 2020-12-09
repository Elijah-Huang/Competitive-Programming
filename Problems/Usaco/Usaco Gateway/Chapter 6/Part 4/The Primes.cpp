/*
ID: elijahj1
TASK: prime3
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solutions;
int isprime[100000];
vector<int> tot_primes;
vector<vector<vector<string>>> primes(1);

int sum, fix;
int square[5][5];

int f = 0;
int c = 0;
int c_3 = 0;
void solve(int idx) {
	//c++;
	/*cout << idx << '\n';
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << square[i][j];
		}
		cout << '\n';
	}
	cout << '\n';*/

	// check if solution works
	if (idx == 4) {
		//f++;
		int row = 0, col = 0;
		string row_val, col_val;
		for (int j = 0; j <= 4; j++) {
			row += square[4][j];
			row_val += to_string(square[4][j]);
		}
		for (int i = 0; i <= 4; i++) {
			col += square[i][4];
			col_val += to_string(square[i][4]);
		}
		
		if (col == sum and row == sum and isprime[stoi(row_val)] and isprime[stoi(col_val)]) {
			vector<int> sol;
			for (int i = 0; i <= 4; i++) {
				for (int j = 0; j <= 4; j++) {
					sol.push_back(square[i][j]);
				}
			}
			solutions.push_back(sol);
		}
		return;
	}

	int x_amount = 0, y_amount = 0;
	for (int j = 0; j <= idx; j++) {
		x_amount = 10*x_amount + square[idx][j];
	}
	for (int i = 0; i <= idx; i++) {
		y_amount = 10*y_amount + square[i][idx];
	}

	//the other diagonal is determined after placing row index 1 and can be checked via this
	int diag;
	int diag_val;
	if (idx == 1) {
		diag = square[2][2] + square[4][0] + square[0][4];
		diag_val = 10000*square[4][0] + 100* square[2][2] + square[0][4];
	}

	//place row and col of idx
	for (auto px : primes[idx + 1][x_amount]) {
		if (idx == 0 and px.find('0') != string::npos) {
			continue;
		}
		
		int need;
		if (idx == 1) {
			//c_3++;
			diag += px[1] - 48;
			need = sum - diag;
			diag -= px[1] - 48;
			if (need < 0 or need > 9) {
				continue;
			}
			else {
				diag_val += 10 * (px[1] - 48);
				diag_val += 1000 * need;
			}

			if (!isprime[diag_val]) {
				diag_val -= 10 * (px[1] - 48);
				diag_val -= 1000 * need;
				continue;
			}
			diag_val -= 10 * (px[1] - 48);
			diag_val -= 1000 * need;
		}

		for (int j = idx + 1; j <= 4; j++) {
			square[idx][j] = px[j - (idx + 1)] - 48;
		}

		for (auto py : primes[idx + 1][y_amount]) {
			if (idx == 0 and py.find('0') != string::npos) {
				continue;
			}
			if (idx == 1 and py[1]-48 != need) {
				continue;
			}

			for (int i = idx + 1; i <= 4; i++) {
				square[i][idx] = py[i - (idx + 1)] - 48;
			}

			solve(idx + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("prime3.in", "r", stdin); freopen("prime3.out", "w", stdout);
	cin >> sum >> fix;
	//clock_t start = clock();
	square[0][0] = fix;
	
	memset(isprime, 1, sizeof(isprime));
	for (int i = 2; i * i < 100000; i++) {
		if (isprime[i]) {
			for (int j = i * i; j < 100000; j += i) {
				isprime[j] = 0;
			}
		}
	}
	
	for (int i = 10000; i < 100000; i++) {
		if (isprime[i]) {
			int curr_sum = 0, i2 = i;
			while (i2) {
				curr_sum += i2 % 10;
				i2 /= 10;
			}
			if (curr_sum == sum) {
				tot_primes.push_back(i);
			}
		}
	}

	// primes with first i digits determined and = p for easy lookup in recursion
	int amt = 10;
	for (int i = 1; i <= 4; i++) {
		primes.push_back(vector<vector<string>>(amt));
		amt *= 10;
	}
	for (auto p : tot_primes) {
		string ending;
		for (int i = 4; i >= 1; i--) {
			ending = to_string(p % 10) + ending;
			p /= 10;
			primes[i][p].push_back(ending);
		}
	}
	
	for (auto p : primes[1][fix]) {
		for (int i = 1; i <= 4; i++) {
			square[i][i] = int(p[i - 1]) - 48;
		}
		//cout << "solving!\n";
		solve(0);
	}
	//cout << f << ' ' << c << ' ' << a << ' ' << c_3 << '\n';

	if (solutions.empty()) {
		cout << "NONE\n";
	}
	else {
		sort(solutions.begin(), solutions.end());
		//cout << double(clock() - start)/CLOCKS_PER_SEC << '\n';
		for (int k = 0; k < solutions.size(); k++) {
			vector<int>& sol = solutions[k];
			for (int i = 0; i <= 4; i++) {
				for (int j = 0; j <= 4; j++) {
					cout << sol[i * 5 + j];
				}
				cout << '\n';
			}
			if (k!= solutions.size()-1) cout << '\n';
		}
	}
}