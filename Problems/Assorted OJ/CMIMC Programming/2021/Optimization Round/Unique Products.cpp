#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (char i = '1'; i <= '6'; i = char(i+1)) {
		string a = "uniqueproducts" + string(1,i);
		cout << a << '\n';
		ifstream fin((a +".txt").c_str());
		ofstream fout((a + "out.txt").c_str());

		int n, m; fin >> n >> m;
		
		vector<int> primes;
		vector<int> is_prime(m + 1,1);
		for (int i = 2; i <= m; i++) {
			if (is_prime[i]) {
				primes.push_back(i);
				for (int j = i * i; j <= m; j += i) {
					is_prime[j] = 0;
				}
			}
		}

		vector<vector<int>> subsets(n, vector<int>{1});

		for (int j = 0; j < primes.size()/n; j++) {
			for (int k = 0; k < n; k++) {
				subsets[k].push_back(primes[j * n + k]);
			}
		}
	
		for (auto s : subsets) {
			for (auto i : s) {
				fout << i << ' ';
			}
			fout << '\n';
		}

		fin.close();
		fout.close();
	}
}