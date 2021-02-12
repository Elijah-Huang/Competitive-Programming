#include<bits/stdc++.h>
using namespace std;

int board[20][20];
int bc = 3, br = 3;
int person = 1;

bool connect_4(int person) {
	for (int i = 0 + br; i < 6 + br; i++) {
		for (int j = 0 + bc; j < 7 + bc; j++) {
			int tot = 0;
			for (int k = 0; k < 4; k++) {
				tot += board[i][j + k] == person;
			}
			if (tot == 4) {
				return 1;
			}

			tot = 0;
			for (int k = 0; k < 4; k++) {
				tot += board[i + k][j] == person;
			}
			if (tot == 4) {
				return 1;
			}

			tot = 0;
			for (int k = 0; k < 4; k++) {
				tot += board[i + k][j + k] == person;
			}
			if (tot == 4) {
				return 1;
			}

			tot = 0;
			for (int k = 0; k < 4; k++) {
				tot += board[i - k][j + k] == person;
			}
			if (tot == 4) {
				return 1;
			}
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int m = 1; m <= 42; m++) {
		int c; cin >> c; c = c - 1 + bc;

		for (int i = 5 + br; i >= 0 + br; i--) {
			if (board[i][c] == 0) {
				board[i][c] = person;
				break;
			}
		}

		if (connect_4(person)) {
			if (person == 1) {
				cout << "RED" << ' ' << m;
			}
			else {
				cout << "YELLOW" << ' ' << m;
			}
			return 0;
		}

		person = (person == 1 ? 2 : 1);
	}

	cout << "DRAW\n";
}