#include<bits/stdc++.h>
using namespace std;

map<string, int> 
animal_to_position = {{ "Bessie",2400 }},
name_to_residue = { {"Ox",0},{"Tiger",1},{"Rabbit",2},{"Dragon",3},{"Snake",4},
	{"Horse",5},{"Goat",6},{"Monkey",7},{"Rooster",8},{"Dog",9},{"Pig",10},{"Rat",11} };
int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	while (n--) {
		string a, t, nam, b; cin >> a;
		for (int i = 0; i < 3; i++) {
			cin >> t;
		}
		cin >> nam;
		for (int i = 0; i < 3; i++) {
			cin >> b;
		}

		if (t == "previous") {
			for (int i = animal_to_position[b]-1;; i--) {
				if (i % 12 == name_to_residue[nam]) {
					animal_to_position[a] = i;
					break;
				}
			}
		}
		else {
			for (int i = animal_to_position[b]+1;; i++) {
				if (i % 12 == name_to_residue[nam]) {
					animal_to_position[a] = i;
					break;
				}
			}
		}
	}

	cout << abs(animal_to_position["Bessie"] - animal_to_position["Elsie"]);
}