// O(n*2^n*log(n)) idea is to use lsinearity of expectation on pairs 
// then go through each round 
// for each round iterate through the players in increasing skill level
// store a*b^-1 where 1/b is the probability that the player will reach this round
// and a is their strength level
// at i, strength(i)*prob(i)*sum of probs before - sum of prev vals * prob(i) should be the added score
// the probability they advance is prob(i) * sum of prob before 
// also be careful of same skill level
// then pray to the gods that your fast proof of modular arithmetic stuff works
// and that you can add all the weird fractions and multiplications up and it'll be fine
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long bin_exp(long long base, long long e) {
	base %= mod;
	long long ret = 1;
	
	while (e) {
		if (e & 1) {
			ret = ret * base % mod;
		}

		e >>= 1;
		base = base * base % mod;
	}

	return ret;
}

long long inv(long long a) {
	return bin_exp(a, mod - 2);
}

const int maxn = 1 << 17;
int n, p;
int strength[maxn];
map<int, pair<int,int>> round1, round2; // round1[a] = b^-1, count
long long ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> p;
	n = 1 << p;

	for (int i = 0; i < n; i++) {
		cin >> strength[i];
	}

	for (int i = 0; i < n; i++) {
		if (round1.count(strength[i])) {
			round1[strength[i]].second++;
		}
		else {
			round1[strength[i]] = { 1,1 };
		}
	}

	for (int round = 1; round <= p; round++) {
		long long tot_prob = 0, tot_sum = 0, tot_p = 1 << (p - round + 1);

		for (auto i : round1) {
			long long strength = i.first;
			long long prob = i.second.first;
			long long count = i.second.second;

			// update ans
			ans = (ans + ((((count * strength % mod) * prob % mod) * tot_prob % mod) * inv(tot_p - 1) % mod));
			ans = (ans + (mod - ((count * prob % mod) * tot_sum % mod) * inv(tot_p - 1) % mod)) % mod;

			// get round 2 vals
			int new_prob = ((prob * tot_prob % mod) * inv(tot_p - 1) % mod);
	
			if (new_prob != 0) {
				round2[strength] = { new_prob,count };
			}

			// update tot vals
			tot_prob = (tot_prob + ((count * prob) % mod)) % mod;
			tot_sum = (tot_sum + ((strength * count % mod) * prob % mod)) % mod;

			cout << round << ' ' << strength << ' ' << prob << ' ' << tot_prob << ' ' << tot_sum << '\n';
		}

		swap(round1, round2);
		round2.clear();
	}

	cout << ans;
}