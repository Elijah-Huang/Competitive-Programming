#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int n; 
	int k;
	string s;
	string output;
	cin >> n >> k;
	cin >> s;
	int maxx = int('A') + k - 1;
	if(k == 2) {
		int changea = 0;
		int changeb = 0;
		for (int i = 0; i < s.length(); i +=2 ) {
			if (s[i] == 'B') {
				changea++;
			}
		}
		for (int i = 1; i < s.length(); i += 2) {
			if (s[i] == 'A') {
				changeb++;
			}
		}
		int length = s.length();
		int total1 = changea + changeb;
		int total2 = length - total1;
		if (total1 < total2) {
			for (int i = 0; i < s.length(); i++) {
				output.push_back(char(int('A') + i % 2));
			}
		}
		else {
			total1 = total2;
			for (int i = 0; i < s.length(); i++) {
				output.push_back(char(int('A') + (i+1) % 2));
			}
		}
		cout << total1 << '\n';
		cout << output << '\n';
	}
	else {
		int change = 0;
		int value;
		if (s.length() == 1){
			cout << 0 << '\n';
			cout << s << '\n';
		}
		else {
			int i = 0;
			while (i < s.length()-1) {
				if (s[i] == s[i + 1]) {
					char last = s[i];
					output.push_back(s[i]);
					i++;
					while (i < s.length() and s[i] == last) {
						value = int(s[i]);
						if (value == maxx) {
							value--;
							if (value == int(s[i + 1])) {
								value--;
							}
						}
						else {
							value++;
							if (value == int(s[i + 1])) {
								if (value == maxx) {
									value -= 2;
								}
								else {
									value++;
								}
							}
						}
						output.push_back(char(value));
						change++;
						i++;
						if (i < s.length() and s[i] == last) {
							output.push_back(s[i]);
							i++;
						}
					}
				}
				else {
					output.push_back(s[i]);
					i++;
				}
			}
			if (i == s.length() - 1) {
				output.push_back(s[s.length() - 1]);
			}
			cout << change << '\n';
			cout << output << "\n";
		}
	}
}