#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;
bool isprime[N + 1];

void enumerate() {
	memset(isprime, 1, sizeof(isprime));
	for (int i = 2; i * i <= N; i++) {
		if (isprime[i]) {
			for (int j = i * i; j <= N; j += i) {
				isprime[j] = 0;
			}
		}
	}
}

//test
// 55 ms for 1e7
/*
int main() {
	clock_t start = clock();
	enumerate();
	cout << double(clock() - start) / CLOCKS_PER_SEC << '\n';
	cout << isprime[2] << ' ' << isprime[123412] << ' ' << isprime[9999047];
}
*/