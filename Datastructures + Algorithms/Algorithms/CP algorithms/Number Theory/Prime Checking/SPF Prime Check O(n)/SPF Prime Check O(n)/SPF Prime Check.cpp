#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;
int spf[N + 1];
vector<int> primes;

void make_spf() {
	for (int i = 2; i <= N; i++) {
		if (spf[i] == 0) {
			spf[i] = i;
			primes.push_back(i);
		}
		for (int j = 0; j < primes.size() and primes[j] <= spf[i] and primes[j] * i <= N; j++) {
			spf[primes[j] * i] = primes[j];
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
//80ms for 1e7
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
