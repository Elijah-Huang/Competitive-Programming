#include<bits/stdc++.h>
using namespace std;

struct spell {
	int t, d;
};

struct spell_cmp {
	bool operator()(const spell& a, const spell& b) const {
		return a.d < b.d;
	}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int c; cin >> c;
	set<spell, spell_cmp> spells_d;
	set<spell, spell_cmp> lightning;
	int min_double = -1;
	int min_lightning;
	long long mx = 0;
	while (c--) {
		/*
		cout << '\n';
		cout << min_double << '\n';
		cout << '\n';
		for (auto s : spells_d) {
			cout << s.d << ' ';
		}
		cout << '\n' << '\n';
		for (auto s : lightning) {
			cout << s.d << ' ';
		}
		cout << '\n' << '\n';
		*/
		int t, d; cin >> t >> d;
		mx += d;
		if (d > 0) {
			if (t == 1) {
				lightning.insert({ 1,d });
				if (lightning.size() == 1) {
					min_lightning = d;
					if (!spells_d.empty()) {
						min_double = (--spells_d.end())->d;
						mx += min_double;
					}
				}
				else {
					if (d < min_lightning) {
						spells_d.insert({ 1, min_lightning });
						if (min_double == -1) {
							min_double = min_lightning;
							mx += min_lightning;
						}
						else if (min_lightning > min_double) {
							mx += min_lightning;
						}
						else {
							min_double = (--spells_d.lower_bound({ 1,min_double }))->d;
							mx += min_double;
						}
						min_lightning = d;
					}
					else {
						spells_d.insert({ 1, d });
						if (min_double == -1) {
							min_double = d;
							mx += d;
						}
						else if (d > min_double) {
							mx += d;
						}
						else {
							min_double = (--spells_d.lower_bound({ 1,min_double }))->d;
							mx += min_double;
						}
					}
				}
			}
			else {
				spells_d.insert({ 0,d });
				if (lightning.size() > 0) {
					if (lightning.size() == spells_d.size()) {
						mx += d;
						min_double = spells_d.begin()->d;
					}
					else if (min_double == -1) {
						min_double = d;
						mx += d;
					}
					else if (d > min_double) {
						mx += d - min_double;
						min_double = (spells_d.upper_bound({ 0,min_double }))->d;
					}
				}
			}
		}
		else {
			if (t == 1) {
				d = -d;
				if (min_lightning == d) {
					lightning.erase(lightning.begin());
					if (lightning.size()) {
						min_lightning = lightning.begin()->d;
						spells_d.erase({ 1,min_lightning });
						if (min_lightning >= min_double and lightning.size() and spells_d.size()) {
							mx -= min_lightning;
						}
						else if (lightning.size() and spells_d.size()) {
							mx -= min_double;
							min_double = (spells_d.upper_bound({ 1,min_double }))->d;
						}
						else {
							mx -= min_double;
							min_double = -1;
						}
					}
					else {
						mx -= min_double;
						min_double = -1;
					}
				}
				else {
					lightning.erase({ 1,d });
					spells_d.erase({ 1,d });
					if (d >= min_double and lightning.size() and spells_d.size()) {
						mx -= d;
					}
					else if (lightning.size() and spells_d.size()) {
						mx -= min_double;
						min_double = (spells_d.upper_bound({ 1,min_double }))->d;
					}
					else {
						if (min_double != -1) {
							mx -= min_double;
							min_double = -1;
						}
					}
				}
			}
			else {
				d = -d;
				spells_d.erase({ 0,d });
				if (min_double != -1) {
					if (d >= min_double) {
						if (spells_d.size()) {
							mx -= d;
							if (spells_d.size() + 1 != lightning.size()) {
								min_double = (--spells_d.lower_bound({ 1,min_double }))->d;
								mx += min_double;
							}
							else {
								min_double = spells_d.begin()->d;
							}
						}
						else {
							mx -= d;
							min_double = -1;
						}
					}
				}
			}
		}

		cout << mx << '\n';
	}
}