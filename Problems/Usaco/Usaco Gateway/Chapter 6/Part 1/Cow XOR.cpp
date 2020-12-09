/*
ID: elijahj1
TASK: cowxor
LANG: C++14
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<bool> trie(1 << 22);

vector<bool> convert(int val) {
	vector<bool> ret(21);
	for (int i = 0; i < 21; i++) {
		ret[20 - i] = ((val >> i) & 1);
	}
	return ret;
}

void insert(vector<bool> &val, int bin_idx = -1, int trie_idx = 1) {
	trie[trie_idx] = 1;
	if (bin_idx == 20) {
		return;
	}
	else if (val[bin_idx + 1] == 1) {
		insert(val, bin_idx + 1, 2 * trie_idx + 1);
	}
	else {
		insert(val, bin_idx + 1, 2 * trie_idx);
	}
}

int max_xor(vector<bool>& prefix_val, int bin_idx = -1, int trie_idx = 1) {
	if (bin_idx == 20) {
		return 0;
	}
	else if (prefix_val[bin_idx+1]) {
		if (trie[2 * trie_idx]) {
			return max_xor(prefix_val, bin_idx + 1, 2 * trie_idx);
		}
		else {
			return (1 << (20 - (bin_idx + 1))) + max_xor(prefix_val, bin_idx + 1, 2 * trie_idx + 1);
		}
	}
	else {
		if (trie[2 * trie_idx + 1]) {
			return (1 << (20 - (bin_idx + 1))) + max_xor(prefix_val, bin_idx + 1, 2 * trie_idx + 1);
		}
		else {
			return max_xor(prefix_val, bin_idx + 1, 2 * trie_idx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowxor.in", "r", stdin); freopen("cowxor.out", "w", stdout);
	int n; cin >> n;
	vector<int> ans = { -1,0,0 };
	unordered_map<int, int> last_occurence = { { 0,0 } };
	int prefix_xor = 0;

	vector<bool> bin_rep_0 = convert(0);
	insert(bin_rep_0);
	for (int idx = 1; idx <= n; idx++) {
		int a; cin >> a;
		prefix_xor ^= a;
		vector<bool> bin_rep = convert(prefix_xor);

		int mx = max_xor(bin_rep);
		if ((mx^prefix_xor) > ans[0]) {
			ans[0] = mx ^ prefix_xor;
			ans[1] = last_occurence[mx] + 1;
			ans[2] = idx;
		}

		last_occurence[prefix_xor] = idx;
		insert(bin_rep);
	}

	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}