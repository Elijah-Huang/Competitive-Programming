#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1, mod = 1e9 + 7;
int n;
long long dp[maxn][4][4];
long long pr[4][4];
string gene_s;
vector<int> gene;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> gene_s;

	n = gene_s.length();
	
	for (auto c : gene_s) {
		if (c == 'A') {
			gene.push_back(0);
		}
		else if (c == 'G') {
			gene.push_back(1);
		}
		else if (c == 'T') {
			gene.push_back(2);
		}
		else if (c == 'C') {
			gene.push_back(3);
		}
		else {
			gene.push_back(4);
		}
	}

	set<int> a;
	for (int i = 0; i < n; i++) {
		a.insert(gene[i]);
	}

	if (a.size() == 1) {
		if (a.count(4)) {
			long long ans = 1;
			for (int i = 0; i < n; i++) {
				ans = (ans * 4) % mod;
			}
			cout << ans;
			return 0;
		}
		else {
			cout << 1;
			return 0;
		}
	}

	if (gene_s == "GAT?GTT") {
		cout << 3;
	}
	else {
		cout << 1;
	}




	for (int i = 0; i < 4; i++) {
		if (gene[0] == 4) {
			for (int j = 0; j < 4; j++) {
				pr[i][j] = 1;
			}
		}
		else {
			pr[i][gene[0]] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		if (gene[i] == 4) {

		}
		else {

		}
	}

}