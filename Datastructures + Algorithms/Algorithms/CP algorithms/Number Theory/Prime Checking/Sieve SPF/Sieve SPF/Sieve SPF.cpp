#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;
int spf[N + 1];

void make_spf() {
	iota(spf, spf + N + 1, 0);
	for (int i = 2; i * i <= N; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j <= N; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}
}

vector<int> factorize(int n) {
	vector<int> factorization;
	while (n != 1) {
		factorization.push_back(spf[n]);
		n /= spf[n];
	}
	return factorization;
}

bool isprime(int n) {
	return spf[n] == n;
}

// test
//130 ms for 1e7
/*
int main() {
	clock_t start = clock();
	make_spf();
	cout << double(clock() - start) / CLOCKS_PER_SEC << '\n';
	cout << isprime(9999901) << '\n';
	auto a = factorize(1123412);
	auto b = factorize(3 * 10 * 17 * 11 * 89 * 19);
	for (auto i : a) {
		cout << i << ' ';
	}
	cout << '\n';
	for (auto i : b) {
		cout << i << ' ';
	}
}
*/