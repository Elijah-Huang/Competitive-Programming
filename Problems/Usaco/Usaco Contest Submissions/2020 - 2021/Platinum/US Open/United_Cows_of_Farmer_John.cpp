// O(N^2/B + N*B) where B is the buffer size -> O(N^(3/2)) ~ 100 million
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n;
int breeds[maxn];
int b_size = 450;
int last_el[maxn], next_el[maxn];
// psum of precomputed answers for a fixed left leader
long long pairs[maxn];
// for finding pairs of new first occurences from buffer with old first occurences; 0 -> left of buffer el, 1 -> right
int psum_counts[2][maxn];
// next_el, original pos; for the extra subtraction from psum[0] and extra addition to original first occurences
vector<pair<int,int>> first_oc_old;
// .second = 1 start or - 1 end
vector<pair<int,int>> first_oc_new;
long long ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;

	memset(last_el, -1, sizeof(last_el));
	fill(next_el, next_el + maxn, n);
	
	for (int i = 0; i < n; i++) {
		cin >> breeds[i];

		if (last_el[breeds[i]] != -1) {
			next_el[last_el[breeds[i]]] = i;
		}
		last_el[breeds[i]] = i;
	}


	memset(last_el, -1, sizeof(last_el));
	int i = 0;
	while (i < n-2) {
		if (i % b_size == 0) {
			// precompute
			if (i) {
				// clear
				memset(last_el, -1, sizeof(last_el));
				fill(pairs + i - b_size, pairs + n, 0);
				for (int j = 0; j < 2; j++) {
					fill(psum_counts[j] + i - b_size, psum_counts[j] + n, 0);
				}
				first_oc_old.clear();
				first_oc_new.clear();
			}

			int active_first_oc = 0;
			for (int j = i; j < n; j++) {
				if (last_el[breeds[j]] == -1) {
					pairs[j] += active_first_oc;
					active_first_oc++;
					psum_counts[0][j]++;
					psum_counts[1][j]++;
					last_el[breeds[j]] = -2;
				}
				else if (last_el[breeds[j]] == -2) {
					active_first_oc--;
					psum_counts[0][j]--;
					last_el[breeds[j]] = -3;
				}
			}

			for (int j = i + 1; j < n; j++) {
				pairs[j] += pairs[j - 1];
				psum_counts[0][j] += psum_counts[0][j - 1];
				psum_counts[1][j] += psum_counts[1][j - 1];
			}
		}

		// update (first element should not be included for updating answers)
		bool original = 0;
		if (i % b_size == 0 or psum_counts[1][i] - psum_counts[1][i - 1]) {
			original = 1;
			first_oc_old.insert(lower_bound(first_oc_old.begin(), first_oc_old.end(), pair<int, int>{ next_el[i], i }), { next_el[i],i });
		}
		if (not original) {
			first_oc_new.erase(lower_bound(first_oc_new.begin(), first_oc_new.end(), pair<int, int>{i, -2}));
			if (next_el[i] != n) {
				first_oc_new.erase(lower_bound(first_oc_new.begin(), first_oc_new.end(), pair<int, int>{next_el[i], -2}));
			}
		}

		// add to answer
		int r = next_el[i] - 1;
		if (i + 2 <= r) {

			ans += pairs[r] - pairs[i];

			for (auto j : first_oc_old) {
				int r2 = next_el[j.second] - 1;
				if (r2 < i + 1) {
					continue;
				}

				ans -= psum_counts[1][min(r2, r)] - psum_counts[1][i];
			}

			int active_first_oc = 0;
			int j2 = 0, extra_sub = 0;
			for (auto j : first_oc_new) {
				if (j.first > r) {
					break;
				}

				while (j2 < first_oc_old.size() and first_oc_old[j2].first <= j.first) {
					if (first_oc_old[j2].first > i) {
						extra_sub++;
					}
					j2++;
				}

				if (j.second == 1) {
					ans += active_first_oc;

					int r2 = next_el[j.first] - 1;
					ans += psum_counts[1][min(r2, r)] - psum_counts[1][j.first];

					// this might be less if there is an old first oc with next_el > i so add this back with extra_sub
					ans += psum_counts[0][j.first] - psum_counts[0][i] + extra_sub;
				}

				active_first_oc += j.second;
			}
		}

		// update 
		if (next_el[i] != n) {
			first_oc_new.insert(lower_bound(first_oc_new.begin(), first_oc_new.end(), pair<int, int>{next_el[i], 1}), { next_el[i], 1 });
			if (next_el[next_el[i]] != n) {
				first_oc_new.insert(lower_bound(first_oc_new.begin(), first_oc_new.end(), pair<int, int>{next_el[next_el[i]], -1}), { next_el[next_el[i]],-1 });

			}
		}

		i++;
	}

	cout << ans;
}