#include<bits/stdc++.h>
using namespace std;

/*
1. max sum = 9*n
2. no 0 digits
3. order of digits doesn't matter so let's just assume it is sorted from least to greatest 111...333...999
4. the maximum length of the portion where digits are 2...9 is log(n)
5. you can use math to bound the # of possible valid sequences of 2...9 of length ~ 20 as 
20 choose 7 ~ 1e5, but via backtrack it's even less
6. for every product we find < max sum we can just check this in O(log(n)) time and if it works then 
we can add the total # of ways that we can repermute the digits in log(n) time since we can precompute 
factorials and inverse factorials mod whatever the mod is
7. operations = number of endings * time to calculate permutations =  (log(n) + 7 choose 7) * 9 ~ 1e7
This is a rough bound because for 1e5, it turns out we only check 5e4 endings and usually, 
it is very rare to find a valid ending, so we don't have to calculate perms in O(base) = O(9) operations
*/

const int maxn = 1e5 + 1, mod = 1e9 + 7;
int n, ans = 0;
// fact[i] = i! % mod | inv_fact[i] =  (i!)^-1 % mod
long long fact[maxn], inv_fact[maxn];

/*we will generate all numbers of the form 1...9 (sorted) because order of digits doesn't matter
recursive function that constructs all endings of the form 2...9 because the max length of this is
log(max sum of digits) = log(9*n)
*/

// counts of the digits 1,2...9 in the n digit number we have constructed
int counts[10];
void solve(int product = 1, int sum = n, int last_digit = 2) {
	if (product > 9 * n) {
		// this ending will never work so we can prune/backtrack
		return;
	}

	if (product == sum) {
		// the n digits 111......111...ending has product of digits = sum of digits
		// now we just need to find the number of permutations of these digits via 
		// combinatorics and add this to the answer
		long long perms = fact[n];
		for (int digit = 1; digit <= 9; digit++) {
			perms = (perms * inv_fact[counts[digit]]) % mod;
		}

		ans = (ans + perms) % mod;
	}
	
	// the ending is now of length n, so we can't extend it anymore
	if (counts[1] == 0) {
		return;
	}

	//choose next digit in the ending
	//must be greater than last_digit since the ending is strictly nondecreasing
	for (int next_digit = last_digit; next_digit <= 9; next_digit++) {
		counts[1] -= 1;
		counts[next_digit] += 1;
		solve(product * next_digit, sum - 1 + next_digit, next_digit);
		counts[1] += 1;
		counts[next_digit] -= 1;
	}
}

// returns base^exp % mod
int mod_exp(long long base, int exp) {
	long long res = 1;

	while (exp) {
		if (exp & 1) {
			res = (res * base) % mod;
		}
		
		exp >>= 1;
		base = (base * base) % mod;
	}

	return res;
}

int main() {
	cin >> n;

	//calculate fact[] and inv_fact[] so we can calculate permutations of the digits 1...2...3...9 later
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}

	inv_fact[n] = mod_exp(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; i--) {
		inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
	}

	// start with your current number = 111....1111 (n ones), we replace 1's to construct an ending 2...9
	counts[1] = n;
	solve();

	cout << ans;
}